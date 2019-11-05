#ifndef RUBRICA_H
#define RUBRICA_H

#include "voce.h"

class rubrica_out_of_space_exception{
  
}
class rubrica{
public:
  typedef unsigned int size_type;

private:
  size_type capacity;
  size_type size;
  voce * voci;

public:
  rubrica();
  rubrica(const rubrica& other);
  rubrica(size_type _capacity);
  ~rubrica();
  rubrica& operator=(const rubrica &other);
  voce &operator[](size_type index);
  const voce &operator[](size_type index) const;
  void set_capacity(size_type capacity);
  void add_voce(std::string cognome,
  std::string nome,
  std::string ntel);
};


#endif
