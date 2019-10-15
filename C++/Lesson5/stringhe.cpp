#include "stringhe.h"
#include <iostream>
#include <cassert>

void stampa_stringa(const char *str){
  const char * current = str;

  while(*current != "\0"){
    std :: cout << *current << std::endl;
    current ++;
  }

}

int lunghezza_Stringa(const char * str){
  /*if(str == nullptr){
    return -1;
  }*/
  assert(str != nullptr);
  const char * current = str;
  while(*current != '\0')
  current++;
  return current;
}

void inverti_stringa(char *str){
  char * punt = str;
  char *end = str + lunghezza_Stringa;

  while(start < end){
    std :: swap(*start, *end);
    start ++;
    end --;
  }
}
