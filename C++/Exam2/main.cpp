#include "iris.h"
#include <ostream> // std::ostream
#include <iostream>
#include <cassert>
#include <string>

int main(int argc, char *argv[]) {
  std::cout << "Hello" << std::endl;
  Iris iris1;
  Iris iris3("abc",0,0,0,0);
  Iris iris2 = iris1;
  std::cout << iris3 << std::endl;
  return 0;
}
