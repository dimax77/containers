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
TEST(Constructors, move) {
  List<int> a({1, 2, 3, 4, 5});
  auto b = std::move(a);
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 5);
  int i = 1;
  for (auto el : b) EXPECT_EQ(el, i++);
}
TEST(Operators, equal_move) {
  List<int> a({1, 2, 3, 4, 5}), b;
  b = std::move(a);
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 5);
  size_t i{};
  for (auto el : b) EXPECT_EQ(el, ++i);
}
TEST(Operators, equal_copy) {
  List<int> a({1, 2, 3, 4, 5}), b({6, 7, 8});
  b = a;
  EXPECT_EQ(b.size(), 5);
  size_t i{};
  for (auto el : b) EXPECT_EQ(el, ++i);
}
TEST(Methods, clear) {
  List<int> a({1, 2, 3, 4, 5});
  EXPECT_EQ(a.size(), 5);
  size_t i{};
  a.clear();
  EXPECT_EQ(a.size(), 0);
}
TEST(Methods, insert) {
  List<int> a({2, 3, 4, 5});
  auto it = a.begin();
  a.insert(it, 1);
  size_t i{};
  for (auto el : a) EXPECT_EQ(el, ++i);
  it = a.end();
  a.insert(it, 6);
  i = 0;
  for (auto el : a) EXPECT_EQ(el, ++i);
  EXPECT_EQ(a.size(), 6);
}
TEST(Methods, erase) {
  List<int> a({1, 1, 2, 3, 4, 5, 6});
  auto it = a.begin();
  a.erase(it);
  size_t i{};
  for (auto el : a) EXPECT_EQ(el, ++i);
  it = --a.end();
  a.erase(it);
  i = 0;
  for (auto el : a) EXPECT_EQ(el, ++i);
  EXPECT_EQ(a.size(), 5);
  it = a.end();
  EXPECT_THROW(a.erase(it), std::invalid_argument);
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
  d.push_back(3.4);
  EXPECT_EQ(d.size(), 3);
  d.pop_back();
  EXPECT_EQ(d.size(), 2);
  d.pop_back();
  EXPECT_EQ(d.size(), 1);
  EXPECT_NO_THROW(d.pop_back());
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
TEST(Methods, merge) {
  List<int> a({1, 2, 3, 6}), b({5, 6, 7, 8, 9});
  a.merge(b);
  EXPECT_EQ(a.size(), 9);
  List<int> c({1, 2, 3, 4}), d({5, 6, 7, 8, 9, 10});
  c.merge(d);
  EXPECT_EQ(c.size(), 10);
  int i = 1;
  for (auto el : c) EXPECT_EQ(el, i++);
}
TEST(Methods, swap) {
  List<int> a({1, 2, 3, 4}), b({4, 3, 2, 1});
  a.swap(b);
  int i = 1;
  for (auto el : b) EXPECT_EQ(el, i++);
}
TEST(Methods, splice) {
  List<int> a({5, 6, 7, 8}), b({1, 2, 3, 4});
  auto it = ++a.end();
  a.splice(it, b);
  int i = 1;
  for (auto el : a) EXPECT_EQ(el, i++);
  List<int> d({1, 2, 3, 4}), c({5, 6, 7, 8});
  d.swap(c);
  it = c.end();
  c.splice(it, d);
  i = 1;
  for (auto el : c) EXPECT_EQ(el, i++);
  List<int> j({1, 2, 7, 8}), k({3, 4, 5, 6});
  it = j.begin();
  it++;
  it++;
  j.splice(it, k);
  i = 1;
  for (auto el : j) EXPECT_EQ(el, i++);
}
TEST(Methods, reverse) {
  List<int> a({5, 4, 3, 2, 1});
  a.reverse();
  int i = 1;
  for (auto el : a) EXPECT_EQ(el, i++);
}
TEST(Methods, unique) {
  List<int> a({5, 5, 4, 4, 4, 4, 3, 2, 1, 1});
  a.reverse();
  a.unique();
  int i = 1;
  for (auto el : a) EXPECT_EQ(el, i++);
  EXPECT_EQ(a.size(), 5);
}
TEST(Iterator, default) {
  List<int> l({1, 2, 3});
  List<int>::Iterator it = l.begin();
  for (auto i : l) EXPECT_EQ(*(it++), i);
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