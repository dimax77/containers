#include <iostream>
#include "s21_list.h"
#include <gtest/gtest.h>

using std::cin;
using std::cout;
using std::endl;

TEST(Constructors, default) {
    using namespace s21;
    List<int> a;
    a.push_back(3);
    a.push_back(5);

}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
    
}