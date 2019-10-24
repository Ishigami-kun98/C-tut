#ifndef DBUFFER_H
#define DBUFFER_H

  //il nome della classe definisce anche un namespace di cosa contiene

  //di default tutto quello che dichiariamo è private
  class dbuffer{
  //Lo scrivo per esplicitare ma non è necessario
    unsigned int size;
    int *buffer;
  //Tutto quello scritto da public in poi è public
  public:
    //primo metodo fondamentale che deve sempre esistere
    dbuffer();
    //costruttore secondario con un parametro ~
    //costruttore secondario con 2 parametri
    dbuffer(unsigned int sz);
    dbuffer(unsigned int sz, int value);
    //Destroyer è obbligatorio viene chiamato automaticamente al return
    ~dbuffer();
    int get_value(unsigned int value);
    void set_value(unsigned int index, int value);
    int& value(unsigned int index);
    unsigned int S();
    //Metodo fondamentale3 copia
    dbuffer& operator= (const dbuffer& rhs);
  };

#endif
