#ifndef S21_LIST_H_
#define S21_LIST_H_

namespace s21 {

template <class T>
class List {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  struct Node;

  struct Iterator {
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
    T& operator*() const { return n_->val_; }

   private:
    Node* n_;
  };

  // constuctors
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
    for (auto it : items) push_back(it);
  }
  // List(const List &l) : List() {}
  // List(List &&l) {}
  ~List() {
    base_->next_ = 0;
    Node* tmp = 0;
    while (head_ != 0) {
      tmp = head_->next_;
      delete head_;
      head_ = tmp;
    }
  }

  // methods
  // List& operator=(List &&l) {}
  const_reference front() { return head_->val_; };
  const_reference back() { return tail_->val_; };
  void push_back(value_type val) {
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
    delete tmp;
  };
  void push_front(value_type val) {
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
    delete tmp;
  };
  size_t size() {
    int count{};
    for (Node* n = head_; n != base_; n = n->next_) count++;
    return count;
  }
  Iterator begin() { return head_; }
  Iterator end() { return base_; }

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
};
};      // namespace s21
#endif  // S21_LIST_H_