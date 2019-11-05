#include "rubrica.h"
#include <iostream>
#include <cassert>
#include <algorithm>

rubrica :: rubrica() : size(0),capacity(0), voci(nullptr){
  #ifndef NDEBUG
  std::cout << "phonebook() primo costruttore" << std::endl;
  #endif
}

rubrica :: ~rubrica(){
  delete[] voci;
  voci = nullptr;
  capacity = 0;
  size = 0;
  std :: cout << "Destroyer works" << std::endl;
}

  rubrica & rubrica::operator=(const rubrica &other){
    if(this != &other){
      rubrica tmp(other);
      std::swap(this -> size, tmp.size);
      std::swap(this -> capacity, tmp.capacity);
      //Viene facile usare lo swap per i oggetti custom
      //Se non avessimo swap, lo dovremo fare manualmente
      std::swap(this -> voci, tmp.voci);
    }
    return *this;
  }

  rubrica:: rubrica(size_type _capacity){
    voci = new voce[_capacity];
    capacity = _capacity;
  }

  rubrica::rubrica(const rubrica &other) : size(0), voci(nullptr), capacity(0){
    voci = new voce[other.capacity];
    for (size_t i = 0; i < other.size; i++) {
      voci[i] = other.voci[i];
    }
    size = other.size;
    capacity = other.capacity;
  }

  void rubrica:: set_capacity(size_type _capacity){
    if(_capacity > size){
    voce *tmp = new voce[new _capacity];
    for (size_t i = 0; i < size; i++) {
      tmp[i] = voci[i];
      capacity = _capacity;
      delete[] voci;
      voci = tmp;
      }
    }else if(_capacity < size){
      rubrica tmp(_capacity);
      std::swap(this -> size, tmp.size);
      std::swap(this -> capacity, tmp.capacity);
      //Viene facile usare lo swap per i oggetti custom
      //Se non avessimo swap, lo dovremo fare manualmente
      std::swap(this -> voci, tmp.voci);
    }
  }

  voce& rubrica::operator[](size_type index){
    assert(index < size);
    return voci[index];
  }

  const voce &operator[](size_type index) const{
    assert(index < size);
    return voci[index];
  }

  void rubrica:: add_voce(const voce &v){
    if(size < capacity){
      voci[size] = v;
      size++;
    }else{
      throw rubrica_out_of_space_exception();
    }
  }
