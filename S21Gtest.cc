#include <iostream>
#include "s21_list.h"
#include <gtest/gtest.h>

using std::cin;
using std::cout;
using std::endl;
using namespace s21;

TEST(Constructors, default) {
    List<int> a;
}

TEST(Methods, push_back) {
  
    List<int> a;
    a.push_back(3);
    EXPECT_EQ(a.size(), 1);
    a.push_back(5);
    EXPECT_EQ(a.back(), 5);
    
    EXPECT_EQ(a.front(), 3);
    EXPECT_EQ(a.size(), 2);
}
TEST(Methods, pop_back) {
  List<double> d;
  d.push_back(2.3);
  d.push_back(3.4);
  EXPECT_EQ(d.size(), 2);
  d.pop_back();
  EXPECT_EQ(d.size(), 1);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
    
}