#include "voce.h"
#include "dbuffer.h"
#include <iostream>
#include <cassert>
#include<algorithm> //std::swap

std::ostream & operator <<(std::ostream &os, const voce &v){
  os << v.nome << " " << v.cognome << " " << v.ntel << std::endl;

  return os;
}

voce:: voce(){

}

voce(std::string c,
std::string n,
std::string ntelefono) : nome(n), cognome(c), ntel(ntelefono){}
