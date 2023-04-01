#ifndef S21_LIST_H_
#define S21_LIST_H_

namespace s21 {

template <class T>
class List {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 private:
  struct Node;  // Declare for Iterator have access

 public:
  // Iterator class
  class Iterator {
   public:
    Iterator() : n_(0) {}
    Iterator(Node* n) : n_(n) {}
    Iterator(const Iterator& it) : n_(it.n_) {}
    Iterator& operator=(const Iterator& it) {
      n_ = it.n_;
      return *this;
    }
    bool operator==(const Iterator& it) { return n_ == it.n_; }
    bool operator!=(const Iterator& it) { return n_ != it.n_; }

    Iterator& operator++() {
      n_ = n_->next_;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp = *this;
      n_ = n_->next_;
      return tmp;
    }
    Iterator& operator--() {
      n_ = n_->prev_;
      return *this;
    }
    Iterator operator--(int) {
      Iterator tmp = *this;
      n_ = n_->prev_;
      return tmp;
    }
    reference operator*() { return n_->val_; }
    Node* getnode() const { return n_; }

   protected:
    Node* n_;
  };

  class ConstIterator : public Iterator {
   public:
    ConstIterator() : iterator() {}
    ConstIterator(Node* n) : iterator(n) {}
    ConstIterator(const Iterator& it) : iterator(it) {}
    const_reference operator*() const { return this->n_->val_; }
  };

  using const_iterator = const ConstIterator;
  using iterator = Iterator;

  // Constuctors
  List() {
    try {
      base_ = new Node();
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    base_->prev_ = base_->next_;
    head_ = tail_ = base_;
  }
  List(size_type n) : List() {
    while (n--) {
      push_back(0);
    }
  }
  List(std::initializer_list<value_type> const& items) : List() {
    for (auto it : items) {
      push_back(it);
    }
  }
  List(const List& l) : List() {
    for (auto el : l) {
      push_back(el);
    }
  }
  List(List&& l) {
    this->base_ = l.base_;
    this->head_ = l.head_;
    this->tail_ = l.tail_;
    this->count = l.count;
    l.base_ = l.head_ = l.tail_ = nullptr;
    l.count = 0;
  }
  ~List() { delete_all_nodes(); }

  List& operator=(List&& l) {
    delete_all_nodes();
    this->base_ = l.base_;
    this->head_ = l.head_;
    this->tail_ = l.tail_;
    this->count = l.count;
    l.base_ = l.head_ = l.tail_ = nullptr;
    l.count = 0;
    return *this;
  }
  List& operator=(const List& l) {
    while (head_ != base_) pop_back();
    for (auto it = l.begin(); it != l.end();) push_back(*(it++));
    return *this;
  }

  // Methods
  const_reference front() { return head_->val_; };
  const_reference back() { return tail_->val_; };

  iterator begin() { return head_; }
  iterator end() { return base_; }

  const_iterator begin() const { return head_; }
  const_iterator end() const { return base_; }

  bool empty() { return head_ == base_; }
  size_t size() { return count; }
  size_type max_size() { return size(); }

  void clear() {}
  iterator insert(iterator pos, const_reference value) {}
  void erase(iterator pos) {}
  void push_back(const_reference val) {
    Node* tmp = 0;
    try {
      tmp = new Node(val);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      return;
    }
    if (head_ == base_) {
      head_ = tmp;
      base_->next_ = tmp;
      base_->prev_ = tail_;
    }
    tail_->next_ = tmp;
    tmp->prev_ = tail_;
    tmp->next_ = base_;
    tail_ = tmp;
    count++;
  };
  void pop_back() {
    if (head_ != base_) {
      Node* tmp = tail_;
      if (tail_->prev_ == base_) {
        head_ = tail_ = base_;
      } else {
        tail_ = tail_->prev_;
        tail_->next_ = base_;
      }
      count--;
      delete tmp;
    };
  };
  void push_front(const_reference val) {
    Node* tmp = 0;
    try {
      tmp = new Node(val);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      return;
    }
    if (head_ == base_) {
      tail_ = tmp;
      tmp->next_ = base_;
    } else {
      tmp->next_ = head_;
    }
    base_->next_ = tmp;
    tmp->prev_ = base_;
    head_ = tmp;
    count++;
  };
  void pop_front() {
    if (head_ == base_) return;
    Node* tmp = head_;
    if (head_->next_ == base_) {
      head_ = tail_ = base_;
    } else {
      base_->next_ = head_->next_;
      head_ = head_->next_;
      head_->prev_ = base_;
    }
    count--;
    delete tmp;
  };
  void swap(List& other) {
    Node* tmp_base = this->base_;
    Node* tmp_head = this->head_;
    Node* tmp_tail = this->tail_;
    size_t tmp_count = this->count;
    this->base_ = other.base_;
    this->head_ = other.head_;
    this->tail_ = other.tail_;
    this->count = other.count;
    other.base_ = tmp_base;
    other.head_ = tmp_head;
    other.tail_ = tmp_tail;
    other.count = tmp_count;
  }
  void merge(List& other) {
    auto it_this_cur = begin();
    auto it_this_end = end();
    auto it_other_cur = other.begin();
    auto it_other_end = other.end();
    s21::List<T> tmp;
    while (it_this_cur != it_this_end) {
      while (it_other_cur != it_other_end) {
        if (*it_this_cur > *it_other_cur) {
          tmp.push_back(*it_other_cur++);
        } else if (*it_this_cur == *it_other_cur) {
          tmp.push_back(*it_other_cur++);
        } else {
          tmp.push_back(*it_this_cur++);
          break;
        }
      }
      if (it_other_cur == it_other_end) break;
    }
    while (it_this_cur != it_this_end) {
      tmp.push_back(*(it_this_cur++));
    }
    while (it_other_cur != it_other_end) {
      tmp.push_back(*(it_other_cur++));
    }
    *this = tmp;
  }
  void splice(const_iterator pos, List& other) {
    Node* tmp = pos.getnode();
    std::cout << "----pos addr------\n"
              << *pos << std::endl
              << "------------\n";
    Node* prev = tmp->prev_;
    std::cout << "----pos.prev addr------\n"
              << tmp->prev_ << std::endl
              << "------------\n";
    prev->next_ = other.head_;
    other.head_->prev_ = prev;
    other.tail_->next_ = tmp;
    tmp->prev_ = other.tail_;
    if (prev == base_) head_ = other.head_;
    if (tmp == base_) tail_ = other.tail_;
    other.head_ = other.base_;
    other.count = 0;
  }
  void reverse() {}
  void unique() {}
  void sort() {}

 private:
  // Inner functions
  void delete_all_nodes() {
    if (base_) {
      base_->next_ = 0;
      Node* tmp = 0;
      while (head_ != 0) {
        tmp = head_->next_;
        delete head_;
        head_ = tmp;
      }
    }
  }

  // Node struct
  struct Node {
    value_type val_;
    Node *next_, *prev_;
    Node() {
      val_ = 0;
      next_ = prev_ = 0;
    }
    Node(value_type val) {
      val_ = val;
      next_ = prev_ = 0;
    }
  };
  Node *base_, *head_, *tail_;
  size_type count{};
};
};      // namespace s21
#endif  // S21_LIST_H_