#include "dbuffer.h"
#include <iostream>
#include <cassert>
#include<algorithm> //std::swap

//Se dichiariamo dbuffer(){} senza il namespace viene vista come funzione globale
//intrisation list
dbuffer :: dbuffer() : size(0), buffer(nullptr){
  //size = 0;
  //buffer = nullptr;
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

int dbuffer :: get_value(unsigned int index) const{
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

const int& dbuffer::value(unsigned int index) const{
  assert(index < size);
  return buffer[index];
}

unsigned dbuffer:: S() const{
  return size;
}

dbuffer& dbuffer::operator=(const dbuffer &rhs){


  /*uno delle possibilita
  if(this != &rhs){
    delete[] buffer;
    buffer = nullptr;
    size = 0;
    int *tmp = new int[rhs.size];
    for (size_t i = 0; i < size; i++) {
      tmp[i] = rhs.buffer[i];
    }
    delete[] buffer;
    buffer = tmp;
    size = rhs.size;
  }*/
  //piu usato
  if(this != &rhs){
    //se il costruttore riesce quello che dobbiamo fare e trasferire i dati in this
    dbuffer tmp(rhs);
    //di solino non ha problemi, perchè se falisce non tcambio nulla su this
    //se la dichiarazione fallisce lo swap non viene eseguito
    std::swap(this -> buffer, tmp.buffer);
    std::swap(this -> size, tmp. size);
  }



  #ifndef NDEBUG
  std::cout << "operand= worked" <<std::endl;
  #endif

  return *this;
  //a volte potrebbe essere necessario scrivere a = b = c
  //a = (b = c) rhs è l'operando a destra dell assegnamento
}

//This is usefull :> this is just like the top one
//the only difference is there this is on born
dbuffer::dbuffer(const dbuffer &other){
  buffer = new int[other.size];
  for(int i = 0; i < other.size ; i++){
    buffer[i] = other.buffer[i];
  }
  size = other.size;
  #ifndef NDEBUG
  std::cout << "copy constructor" <<std::endl;
  #endif
}
