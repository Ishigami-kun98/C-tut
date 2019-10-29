#include <iostream>
#include "dbuffer.h"
#include <cassert>

void funct1(dbuffer d){

}

//è errato mettere const dbuffer &d come argomento perchè il compilatore è uno scarsone
//percio dobbiamo dirgli che S() non cambia nulla di &d 
void funct2(dbuffer &d){
  std::cout << d.S() << std::endl;
  for (size_t i = 0; i < d.S(); i++) {
    std::cout << d.value(i) << std::endl;
  }
}

void funct3(dbuffer *d){

}

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
  dbuffer db5;
  db5 = db2;
  assert(db5.S() == db2.S());
  for (size_t i = 0; i < db5.S(); i++) {
    assert(db5.value(i) == db2.value(i));
  }
  //what i have done??? i assigned a number to dbuffer type
  //We have a problem, for us debuffer assign number to dbuffer is a normal operation
  //but why? it will go to see if there exist a such assignment, he didn't find it in the variable
  //then it find it in the constructor, the dbuffer(unsigned int sz);
  //Here s a int, i ll give u a dbuffer. then if we add explicit dbuffer(unsigned int sz)

  funct1(db5); //Passaggio per valore copia




  return 0;
}
