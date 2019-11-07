#ifndef RUBRICA_H
#define RUBRICA_H
#include <ostream>

#include "voce.h"

class rubrica_out_of_space_exception{

};

class duplicated_voce_exception{

};

class file_error_exception{};
class rubrica{
public:
  typedef unsigned int size_type;

private:
  size_type capacity;
  size_type size;
  voce * voci;
  voce * find_voce_helper(const std::string &nt) const;

public:
  rubrica();
  rubrica(const rubrica& other);
  rubrica(size_type _capacity);
  ~rubrica();
  rubrica& operator=(const rubrica &other);
  voce &operator[](size_type index);
  const voce &operator[](size_type index) const;
  void set_capacity(size_type capacity);
  void add_voce(const voce &v);
  size_type C() const;
  size_type S() const;
  voce find_voce(const std::string &nt);
  void clear();

    void save(const std::string &filename) const;
    bool load(const std::string &filename);
};

std:: ostream & operator <<(
  std::ostream &os, const rubrica &r);



#endif
