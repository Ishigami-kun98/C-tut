#include <iostream>
#include "dbuffer.h"

int main(int argc, char *argv[]) {
    int tmp[] = {1,2,3,4,5};
    dbuffer::dynamic_buffer db;
    dbuffer::inizializza_buffer(db);
    db.buffer = tmp;
    db.size = 5;
    dbuffer::stampa_buffer(db);
  return 0;
}


/*namespace dbuffer{
  int tmp[] = {1,2,3,4,5}
  dbuffer::dynamic_buffer db;
  db.buffer = tmp;
  db.size = 5;
  buffer::stampa_buffer(db);
}
*/
