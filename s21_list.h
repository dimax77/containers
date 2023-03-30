#ifndef S21_LIST_H_
#define S21_LIST_H_

namespace s21 {

template <class T>
class List {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  // using iterator = T*;
  // using const_iterator = const T*;
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

   protected:
    Node* n_;
  };

  class ConstIterator : public Iterator {
   public:
    ConstIterator() { this->n_ = 0; }
    ConstIterator(Node* n) { this->n_ = n; }
    ConstIterator(const Iterator& it) { this->n_ = it.n; }
    const_reference operator*() { return this->n_->val_; }
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
  List(List&& l) : List() {
    this->base_ = l.base_;
    this->head_ = l.head_;
    this->tail_ = l.tail_;
    this->count = l.count;
    l.head_ = l.tail_ = nullptr;
    l.count = 0;
  }
  ~List() {
    base_->next_ = 0;
    Node* tmp = 0;
    while (head_ != 0) {
      tmp = head_->next_;
      delete head_;
      head_ = tmp;
    }
  }
  // List& operator=(List &&l) {}

  // Methods
  const_reference front() { return head_->val_; };
  const_reference back() { return tail_->val_; };

  Iterator begin() { return head_; }
  Iterator end() { return base_; }

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
    if (head_ == base_) head_ = tmp;
    tail_->next_ = tmp;
    tmp->prev_ = tail_;
    tmp->next_ = base_;
    tail_ = tmp;
    count++;
  };
  void pop_back() {
    if (head_ == base_) return;
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
  void merge(List& other) {}
  void splice(const_iterator pos, List& other) {}
  void reverse() {}
  void unique() {}
  void sort() {}

 private:
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
  size_t count{};
};
};      // namespace s21
#endif  // S21_LIST_H_