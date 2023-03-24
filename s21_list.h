#ifndef S21_LIST_H_
#define S21_LIST_H_
#include <list>


template <class T>
class s21_list {
 private:
  //  Class node
  int nodes_count{};
  template <class T>
  class s21_node {
   public:
    friend class s21_list;
    s21_node() {
      next = nullptr;
      prev = nullptr;
      val = 0;
      nodes_count = 1;
    }
    s21_node(T val) {}

   private:
    T val;
    s21_node* next;
    s21_node* prev;
  }
  //  End node class
  public : friend s21_node;
  s21_list() { s21_node(); }
  s21_list(T val) : s21_node(val){};
};
#endif  // S21_LIST_H_