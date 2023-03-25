#include <iostream>
#include "test2.h"
using namespace s_21;

int main() {

    List<int> list;
    list.iterator iter = new List<int>::Iterator;
    std::cout << iter.begin();
    return 0;

}