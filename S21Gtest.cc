#include <gtest/gtest.h>

#include <iostream>

#include "s21_list.h"

using std::cin;
using std::cout;
using std::endl;
using namespace s21;

TEST(Constructors, default) { List<int> a; }
TEST(Constructors, size_n) {
  List<int> a(10);
  EXPECT_EQ(a.size(), 10);
}
TEST(Constructors, list) {
  List<int> a({1, 2, 3, 4, 5});
  EXPECT_EQ(a.size(), 5);
}
TEST(Constructors, copy) {
  List<int> a({1, 2, 3, 4, 5});
  auto b(a);
  auto it = a.begin();
  for (auto el : b) EXPECT_EQ(el, *(it++));
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
  d.pop_back();
  EXPECT_EQ(d.size(), 0);
  EXPECT_NO_THROW(d.pop_back());
}
TEST(Methods, push_front) {
  List<int> i;
  i.push_front(100);
  EXPECT_EQ(i.front(), 100);
  EXPECT_EQ(i.size(), 1);
  i.push_front(200);
  EXPECT_EQ(i.front(), 200);
  EXPECT_EQ(i.back(), 100);
  EXPECT_EQ(i.size(), 2);
}
TEST(Methods, pop_front) {
  List<double> d;
  d.push_back(2.3);
  d.push_back(3.4);
  EXPECT_EQ(d.size(), 2);
  d.pop_front();
  EXPECT_EQ(d.size(), 1);
  d.pop_front();
  EXPECT_EQ(d.size(), 0);
  EXPECT_NO_THROW(d.pop_front());
}
TEST(Methods, swap) {
  List<int> a({1, 2, 3, 4}), b({4, 3, 2, 1});
  a.swap(b);
  int i = 1;
  for (auto el : b) EXPECT_EQ(el, i++);
}
TEST(Iterator, default) {
  List<int> l({1, 2, 3});
  List<int>::Iterator it = l.begin();
  for (auto i : l)  // *Iter
    EXPECT_EQ(*(it++), i);
}
TEST(Iterator, inc_decr) {
  List<int> l({1, 2, 3});
  List<int>::Iterator it = l.begin();
  EXPECT_EQ(*(++it), 2);
  EXPECT_EQ(*(it++), 2);
  EXPECT_EQ(*(--it), 2);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}