#include "rubrica.h"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <fstream>

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
    voce *tmp = new voce[_capacity];
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

  const voce & rubrica :: operator[](size_type index) const{
    assert(index < size);
    return voci[index];
  }

  rubrica::size_type rubrica:: S() const{
    return size;
  }

  rubrica::size_type rubrica:: C() const{
    return capacity;
  }

  void rubrica:: add_voce(const voce &v){
    if(size < capacity){
      voce *tmp = nullptr;
      tmp = find_voce_helper(v.ntel);
      if(tmp == nullptr){
        voci[size] = v;
        size++;
      }else
      throw duplicated_voce_exception();

    }else{
      throw rubrica_out_of_space_exception();
    }
  }

  voce rubrica :: find_voce(const std:: string &nt){
    voce * risultato = nullptr;
    risultato = find_voce_helper(nt);
    if(risultato == nullptr)
    throw duplicated_voce_exception();
    else
    return *risultato;
  }

  voce * rubrica:: find_voce_helper(const std::string &nt) const {

    for (size_t i = 0; i < size; i++) {
      if(nt == voci[i].ntel){
        return &(voci[i]);
      }
    }
    return nullptr;
  }

  void rubrica:: clear(){
    size = 0;
    //concetual clear so we can t use it on the destroyer
  }

  std:: ostream & operator <<(
    std::ostream &os, const rubrica &r)
  {
    os << r.S();
    os << r.C();
    for (size_t i = 0; i < r.S(); i++) {
      os << r[i] << std::endl;
      if(i < r.S()-1)
      {
      os << std:: endl;
      }
    }
    return os;
  }

void rubrica:: save(const std::string &filename) const{
  std::ofstream ofs;
  ofs.open(filename);
  if(ofs.is_open()){
    ofs << *this;
  }else
  throw file_error_exception();
  ofs.close();
}
bool rubrica:: load(const std::string &filename){
  std::ifstream ifs;
  ifs.open(filename);
  if(ifs.is_open()){
    size_type cap, siz;
    ifs >> cap;
    ifs >> siz;
    rubrica tmp;
    tmp.set_capacity(cap);
    size_type i;
    for (size_t i = 0; i < siz ; i++) {
      std::string nome, cognome, ntel;
      ifs >> nome >> cognome >> ntel;
      voce v(nome, cognome, ntel);
      tmp.add_voce(v);
    }
    std::swap(voci, tmp.voci);
    std::swap(capacity, tmp.capacity);
    std::swap(size, tmp.size);
  }else{return false;}
  ifs.close();
  return true;
}
