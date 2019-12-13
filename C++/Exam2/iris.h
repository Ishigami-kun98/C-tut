
#ifndef IRIS_H
#define IRIS_H

#include <ostream> // std::ostream
#include <iostream>

#include <string>


  struct Iris{
    std::string _nome;
    float _sepal_length;
    float _sepal_width;
    float _petal_length;
    float _petal_width;



    Iris() : _nome(""), _sepal_length(0), _sepal_width(0),
    _petal_length(0), _petal_width(0){
      std::cout << "Constructor Iris()" << std::endl;
    }

    explicit Iris(const std::string &nome, float sepal_length = 0,
    float sepal_width = 0,
    float petal_length = 0,
    float petal_width = 0): _nome(nome), _sepal_width(sepal_width),
    _sepal_length(sepal_length), _petal_length(petal_length),
    _petal_width(petal_width){
      std::cout << "Constructor Iris(string nome, .., .., .., ..)" << std::endl;
    }

    Iris(const Iris &Other) : _nome(Other._nome), _sepal_width(Other._sepal_width),
    _sepal_length(Other._sepal_length), _petal_length(Other._petal_length),
    _petal_width(Other._petal_width){
      std::cout << "Constructor Iris(Iris &other)" << std::endl;
    }

    Iris& operator=(const Iris &other){
      if(this != &other){
        Iris tmp(other);
        std::swap(this ->_nome, tmp._nome);
        std::swap(this ->_sepal_length, tmp._sepal_length);
        std::swap(this ->_sepal_width, tmp._sepal_width);
        std::swap(this ->_petal_length, tmp._petal_length);
        std::swap(this ->_petal_width, tmp._petal_width);
      }
      std::cout << "operator assignment = const(Iris other)" << std::endl;
      return *this;
    }


    std::string get_nome() const {
      return _nome;
    }
    float get_sepal_length() const {
      return _sepal_length;
    }
    float get_sepal_width() const{
      return _sepal_width;
    }
    float get_petal_length() const{
      return _petal_length;
    }
    float get_petal_width() const{
      return _petal_width;
    }


    ~Iris(){
      //Nothing to do since we didn t allocated dynamic memory
    }

  };

  std::ostream &operator<<(std::ostream &os, const Iris &other){
    os << other.get_nome()<< other.get_sepal_length() << other.get_sepal_width() <<
    other.get_petal_length() << other.get_petal_width() << std::endl;
    return os;
  }

#endif
