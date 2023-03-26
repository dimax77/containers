#ifndef NEW_H_
#define NEW_H_

namespace s_21 {
template <typename T>
class List {
 public:
  List() { Init(); }

 private:
  struct Node {
    T val;
    T *next, *prev;
  };
  size_t size;
  Node *front, *rear;
  Init() {
    front = rear = this;
    size = 0;
    Node.val = 0;
  }
};
}  // namespace s_21
#endif  // NEW_H_