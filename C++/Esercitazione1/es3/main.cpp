#include "romano.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  int n;
  std :: cout << "Inserire un valore : ";
  std :: cin >> n;
  if(n < 1 || n > 3999){
    std::cerr << " valore inserito not gud :" << n << std::endl;
    return 2;
  }

  std :: cout << "il numero " << n << "in numeri romani e' ";
  print_roman(n);
  std :: cout << std::endl;
  return 0;
}
