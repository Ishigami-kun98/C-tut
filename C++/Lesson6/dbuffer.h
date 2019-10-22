#ifndef DBUFFER_H
#define DBUFFER_H

  namespace dbuffer{
    struct dynamic_buffer{
      unsigned int size; //dimensione del buffer
      int *buffer;      // puntatore al buffer
    };

  void stampa_buffer(const dynamic_buffer &db);
  void inizializza_buffer(dynamic_buffer &db);
  void alloca_buffer(dynamic_buffer &db, unsigned int size);
  void dealoca_buffer(dynamic_buffer &db);
  void riempi_buffer(dynamic_buffer &db);
  void riempi_buffer(dynamic_buffer &db, const int * values, int val_size);
  dynamic_buffer clona(dynamic_buffer &db);
}

#endif
