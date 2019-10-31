#ifndef DBUFFER_H
#define DBUFFER_H
#include <ostream>

  //il nome della classe definisce anche un namespace di cosa contiene

  //di default tutto quello che dichiariamo è private
  class dbuffer{
  public:
    //adesso puoi sostituire tutti i int con size_type
    //ma non puoi sostituire un return a size_type
    typedef unsigned int size_type;
  private:
  //Lo scrivo per esplicitare ma non è necessario
    unsigned int size;
    int *buffer;
  //Tutto quello scritto da public in poi è public
  public:
    //primo metodo fondamentale che deve sempre esistere
    dbuffer();
    //costruttore secondario con un parametro ~
    //costruttore secondario con 2 parametri
    explicit dbuffer(unsigned int sz);
    dbuffer(unsigned int sz, int value);
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
    dbuffer(const dbuffer &other);
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
