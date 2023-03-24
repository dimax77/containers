#include <iostream>
#include <list>
using namespace std;

int main() {
  class mylist : public list<int> {
   public:
    ~mylist() { cout << "My destructor working\n"; };
  };
  mylist l1;
  for (int i = 0; i < 5; i++) l1.push_back(i);
  cout << "List size: " << l1.size() << endl;
  list<int>::iterator iter = l1.begin();
  // while (iter != l1.end()) {
  //   cout << *iter++ << endl;
  // }
  size_t temp = l1.size() / 2;
  cout << "At the middle " << *(++iter) << endl;
  cout << &l1 << endl;
  cout << &l1.back() << endl;
  return 0;
}