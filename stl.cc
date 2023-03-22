#include "stl.h"

int main() {
  Double_list<int> the_list;

  Double_list<int>::iterator list_iter;

  for (int i = 0; i < 5; ++i) {
    the_list.add_front(i);
  }

  the_list.print();

  the_list.remove_front();

  for (list_iter = the_list.front(); list_iter != the_list.rear();
       ++list_iter) {
    std::cout << *list_iter << " ";
  }
  std::cout << std::endl;

  // выводим в обратном порядке
  for (list_iter = the_list.rear(); list_iter != the_list.front();) {
    --list_iter;
    std::cout << *list_iter << " ";
  }

  std::cout << std::endl;

  system("PAUSE");
  return 0;
}
