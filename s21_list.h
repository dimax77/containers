#ifndef S21_LIST_H_
#define S21_LIST_H_

namespace s21 {

template <class T>
class List {
 struct node{
   T val_;
   node *next, *prev;
   node() {
     val_ = 0;
     next = prev = 0;
   }
   node(T val) {
     val_ = val;
     next = prev = 0;
   }
 };
 node *base, *head, *tail;
//  size_t size;

 public:

 // constuctors
 List(){
   try
   {
     base = new node();
   }
   catch(const std::exception& e)
   {
     std::cerr << e.what() << '\n';
   }
   
   base->prev=base->next;
   head = tail = base;
 }
 ~List() {
   base->next = 0;
          node *tmp = 0;
   while (head != 0)
   {
          tmp = head->next;
          delete head;
          head = tmp;
   }
   
 }


   // methods
   T front() {
     return head->val_;
   };
   T back() {
     return tail->val_;
   };
   void push_back(T val) {
     node *tmp = 0;
     try
     {
       tmp = new node(val);
     }
     catch(const std::exception& e)
     {
       std::cerr << e.what() << '\n';
     }
     
     if(head == base) head = tmp;
     tail->next = tmp;
     tmp->prev = tail;
     tmp->next = base;
     tail = tmp;
    //  size++;
   };
   void pop_back() {
     if(head==base) return;
     node *tmp = tail;
     tail = tail->prev;
     tail->next = base;
     delete tmp;
   };
   void push_front() {};
   void pop_front() {};
   size_t size() {
     int count{};
     for(node* n = head; n != base; n = n->next)
     count++;
     return count;
   }
};
};      // namespace s21
#endif  // S21_LIST_H_