#include <iostream>
#include <list>
using namespace std;

int main() {
  // list<int> my = list<int>();
  // cout << my.front();
  // for (int i = 0; i < 5; i++) l1.push_back(i);
  // cout << "List size: " << l1.size() << endl;
  // list<int>::iterator iter = l1.begin();
  // // while (iter != l1.end()) {
  // //   cout << *iter++ << endl;
  // // }
  // size_t temp = l1.size() / 2;
  // cout << "At the middle " << *(++iter) << endl;
  // cout << &l1 << endl;
  // cout << &l1.back() << endl;
  // typedef list<int> mylist2;
  // mylist2 l2;
  // cout << l2.back();
  // cout << l2.front();
  // list<int>::iterator it = l2.begin();
  // cout << &(*it);
  // cout<< *(l2.end());
  typedef struct Person {
    //  private:
    string name;
    int age;
  } person;
  using namespace std;
  person Vasya;
  Vasya.name = "vasya";
  Vasya.age = 25;
  list<person> office1({Vasya});
  office1.push_back({"dima", 46});

  cout << "Size: " << office1.size() << endl;
  cout << "First person: " << office1.front().name << ": "
       << office1.front().age << endl;
  list<double> l;
  cout << "Size: " << l.size() << endl;
  cout << "Head address: " << l.front() << "\n";
  list<int> my({1, 2, 3});

  cout << "Head address: " << &my.front() << "\n";
  cout << "Tail address: " << *my.end() << "\n";
  my.front() = 6;
  cout << "Head address: " << *(my.begin()++) << "\n";
  list<int>::iterator iter = my.end();
  cout << "Tail address: " << *(++iter) << "\n";
  cout << "Size: " << my.size() << endl;
  return 0;
}