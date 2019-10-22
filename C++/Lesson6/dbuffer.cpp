#include "dbuffer.h"
#include <iostream>
#include <cassert>

namespace dbuffer{
  void stampa_buffer(const dynamic_buffer &db){
    assert(db.buffer != nullptr);
    for (size_t i = 0; i < db.size; i++) {
      std::cout << db.buffer[i] << std :: endl;
    }
  }

//Puo provocare un memory leak se lo chiamiamo dopo l'inizializzazione di una roba
  void inizializza_buffer(dynamic_buffer &db){
    db.size = 0;
    db.buffer = nullptr;
  }

  void alloca_buffer(dynamic_buffer &db, unsigned int size){
    //assert(db.buffer == null); soluzione possibile
    if(db.buffer != nullptr){
      dealoca_buffer(db);
    }
    db.buffer = new int[size];
    //La db.size deve essere sotto perchè se la new int non funziona allora abbiamo un buffer vuoto e una size con valore
    db.size = size;
  }

  void dealoca_buffer(dynamic_buffer &db){
    assert(db.buffer != nullptr);
    delete[] db.buffer;
    inizializza_buffer(db);
  }

  void riempi_buffer(dynamic_buffer &db){
    int value;
    for (size_t i = 0; i < db.size; i++) {
      std::cout << "Insert a value in the position " << i <<std::endl;
      std:: cin >> value;
    }
  }

  void riempi_buffer(dynamic_buffer &db, const int * values, int val_size){

    assert(values != nullptr);
    assert(db.buffer != nullptr);
    assert(db.size != val_size);

    for (size_t i = 0; i < val_size; i++) {
      db.buffer[i] = values[i];
    }
  }

  dynamic_buffer clona_buffer(dynamic_buffer &db){
    assert(db.buffer != nullptr);
    dbuffer :: dynamic_buffer dbclone;
    inizializza_buffer(dbclone);
    alloca_buffer(dbclone, db.size);
    riempi_buffer(dbclone, db.buffer, db.size);
    return dbclone;
  }
}
