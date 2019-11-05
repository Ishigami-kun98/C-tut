#ifndef VOCE_H
#define VOCE_H
#include <ostream>

#include<string>

struct voce{
  std::string cognome;
  std::string nome;
  std::string ntel;

  //se facciamo così il costruttore di default sparisce, cioè non viene piu visto
  voce(std::string cognome,
  std::string nome,
  std::string ntel);
  //Se vogliamo il costruttore di default bisogna esplicitarlo
};

std::ostream & operator <<(std::ostream &os, const voce &v);


#endif
