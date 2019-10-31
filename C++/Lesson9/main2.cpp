#include <iostream>
#include "dbuffer.h"
#include <cassert>
#include <fstream> //std::ofstream

void test_fondamentali(){
  dbuffer db1;
  dbuffer db2(100);
  dbuffer db3(50, -1);

  //test cctor
  dbuffer db4(db3); //dbuffer db4 = db3

  assert(db4.S() == db3.S());
  for (size_t i = 0; i < db4.S(); i++) {
    assert(db3[i] == db4[i]);
  }



  //op assegnamento
  db1 = db3;
  assert(db1.S() == db3.S());
  for (size_t i = 0; i < db1.S(); i++) {
    assert(db3[i] == db1[i]);
  }//assert
  db1[4] = 100;
  //assert
  //int tmp = db[8];
  //cosa deve accadere esplodere e non funzicare

  //N.B. abbiamo 5 dbuffer perchè durante l'assegnamento operator=
  //abbiamo creato un dbuffer temporaneo(che ovviamente è gia morto)
  std:: cout << db4 << std::endl;
}

void test_buffer(){
  dbuffer db(5, 0);
  for (size_t i = 0; i < 5; i++) {
    db[i] = 1;
  }
}

void test_debuffer_const(){
  dbuffer db(5, 0);
}

void test_debuffer_const_helper(const dbuffer db){
  int tmp = db[10];
  std::cout << db << std::endl;
}


int main(int argc, char *argv[]) {
  test_buffer();
  test_debuffer_const();
  return 0;
}
