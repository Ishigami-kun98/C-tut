#include <iostream>
#include "dbuffer.h"

int main(int argc, char *argv[]) {
  //Il primo dbuffer() quello di default;
  //dbuffer db;
  //il secondo dbuffer(unsigned int sz)
  dbuffer db2(100);
  //il terzo dbuffer(unsigned int sz, int value)
  //dbuffer db3(10,0);
  //in java serve new ma in c++ no
  //dbuffer db[5];

  db2.set_value(0, 100);
  int tmp = db2.get_value(0);
  db2.set_value(0, db2.get_value(50));
  db2.value(0) = db2.value(50);
  std::cout << "La size di debuffer e' : " <<db2.S()<< std::endl;
  dbuffer db4;
  db4 = db2;
  //Copiare è una operazione fondamentale, che il compilatore fa
  //e crea la memoria al posto nostro, ma la copia è bit a bit
  //Cioè l'array in db2 puntano entrambi allo heap, quando muore
  //db2, viene ridistrutto anche db4
  //db2.buffer[0] = db2.buffer[50];
  return 0;
}
