#ifndef DBUFFER_H
#define DBUFFER_H
#include <ostream>
#include <iostream>

//non ho finito la classe con il  template perchè non avevo voglia di continuare.

  //il nome della classe definisce anche un namespace di cosa contiene

  //di default tutto quello che dichiariamo è private
  template <typename T>
  class dbuffer{
  public:
    //adesso puoi sostituire tutti i int con size_type
    //ma non puoi sostituire un return a size_type
    typedef unsigned int size_type;
    typedef T value_type;
  private:
  //Lo scrivo per esplicitare ma non è necessario
    unsigned int size;
    int *buffer;
  //Tutto quello scritto da public in poi è public
  public:
    //primo metodo fondamentale che deve sempre esistere
    dbuffer(): size(0), buffer(nullptr){
      //size = 0;
      //buffer = nullptr;
      //Come entrare in modalita debug(Anche se di default lo siamo percio non serve)
      #ifndef NDEBUG
      std::cout << "dbuffer : dbuffer()" <<std::endl;
      #endif
    }
    //costruttore secondario con un parametro ~
    //costruttore secondario con 2 parametri
    explicit dbuffer(unsigned int sz){
      buffer = new T[sz];
      size = sz;
      std::cout << "dbuffer : dbuffer(int sz)"<< sz <<std::endl;
    }
    dbuffer(unsigned int sz, const T & value){
      buffer = new int[sz];
      size = sz;
      try{
        for(int i = 0; i < size; ++i){
          buffer[i] = value;
        }
      }catch(...){
        delete[] buffer;
        buffer = nullptr;
        size = 0;
        throw;
      }
      std::cout << "dbuffer : dbuffer(int sz, int value)" << sz << value <<std::endl;
    }
    //Destroyer è obbligatorio viene chiamato automaticamente al return
    ~dbuffer();
    //se metto const alla fine qui allora non deve cambiare
    int get_value(unsigned int value) const;
    void set_value(unsigned int index, int value);
    int& value(unsigned int index);
    const int& value(unsigned int index) const;
    unsigned int S() const;
    //Metodo fondamentale3 copia
    dbuffer& operator= (const dbuffer& rhs);
    dbuffer(const dbuffer &other){
      buffer = new int[other.size];
      try{
        for(int i = 0; i < other.size ; i++){
          buffer[i] = other.buffer[i];
          size = other.size;
        }
      }catch(...){
        delete[] buffer;
        buffer = nullptr;
        size = 0;
        throw;
      }

      #ifndef NDEBUG
      std::cout << "copy constructor" <<std::endl;
      #endif
    }
    void print() const;
    //lettura scritture
    int &operator[](int index);
    //lettura
    const int &operator[](int index) const;
    //Stiamo dichiarando che operator<< è un amica della classe
    //così anche se è globale puo accedere agli dati privati del debuffer
    friend std:: ostream & operator <<(std::ostream &os, const dbuffer &db);
  };
//Questo è la sintassi per agire su un operatore di assignature
 std:: ostream & operator <<(std::ostream &os, const dbuffer &db);
 //non c'è cout perchè è un oggetto di stream di output che spedisce informazioni
 //e deriva da ostream, perciò non serve scriverla qui
 //Qui viene ritornato un references perchè in std :: cout << .. << ci sono concatenazioni

//const alla fine, se abbiamo due metodi con lo stesso nome, il primo const
//e l'altro no, di default viene eseguito quello const, ma se cerchiamo di
//manipolarlo, cioè cambiare i dati, allora il compilatore mi da errore

#endif
