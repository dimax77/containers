#include <iostream>

struct base {
  virtual ~base() = default;
};

struct der : base {
  ~der() { std::cout << "der::der\n"; }
};

int main() {
  base *d = new der;
  delete d;
}