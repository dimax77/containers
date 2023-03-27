#ifndef S21_LIST_H_
#define S21_LIST_H_

namespace s21 {

template <class T>
class List {
 public:
  // using value_type = T;
  typedef T value_type;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  List() { Init(); };
  List(List &other_list){};
  List(List &&other_list){};
  ~List(){};

  iterator begin() { return iterator(this->_M_impl._M_node._M_next); }
  iterator end() { return iterator(&this->_M_impl._M_node); }
  reference front() { return *begin(); }
  reference back() {
    iterator tmp = end();
    --tmp;
    return *tmp;
  }

  void Init() { int a = default; };

 private:
  struct Node_ {
    value_type value_;
    value_type *next_;
    value_type *prev_;
  };

  Node_ *first_;
  Node_ *last_;
  size_type size_;

  struct Iterator_ {
    Node_ *node_;
    iterator() : node_(0){};
    iterator(Node *node) : node_(node){};
    iterator()
  };
};
};      // namespace s21
#endif  // S21_LIST_H_