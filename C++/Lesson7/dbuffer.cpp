#include "dbuffer.h"
#include <iostream>
#include <cassert>

//Se dichiariamo dbuffer(){} senza il namespace viene vista come funzione globale
dbuffer :: dbuffer(){
  size = 0;
  buffer = nullptr;
  //Come entrare in modalita debug(Anche se di default lo siamo percio non serve)
  #ifndef NDEBUG
  std::cout << "dbuffer : dbuffer()" <<std::endl;
  #endif
}

//distruttore
dbuffer:: ~dbuffer(){
  delete[] buffer;
  buffer = nullptr;
  size = 0;
  std :: cout << "dbufferdestroye" << std::endl;

}

dbuffer :: dbuffer(unsigned int sz){
  buffer = new int[sz];
  size = sz;
  std::cout << "dbuffer : dbuffer(int sz)"<< sz <<std::endl;
}

dbuffer :: dbuffer(unsigned int sz, int value){
  buffer = new int[sz];
  size = sz;
  for(int i = 0; i < size; ++i){
    buffer[i] = value;
  }
  std::cout << "dbuffer : dbuffer(int sz, int value)" << sz << value <<std::endl;
}

int dbuffer :: get_value(unsigned int index){
  assert(index < size);
  return buffer[index];
}
void dbuffer :: set_value(unsigned int index, int value){
  assert(index < size);
  buffer[index] = value;
}

int& dbuffer::value(unsigned int index){
  assert(index < size);
  return buffer[index];
}

unsigned dbuffer:: S(){
  return size;
}

dbuffer& dbuffer_ operator=(const dbuffer &rhs){
  //Bisogna scriverlo sempre così
  //verifica indirizzo operando evito autoassegnamento
  if(this != &rhs){

  }

  return *this;
  //a volte potrebbe essere necessario scrivere a = b = c
  //a = (b = c) rhs è l'operando a destra dell assegnamento
}
