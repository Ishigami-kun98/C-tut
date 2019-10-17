#include "stringhe.h"
#include <iostream>
#include <cassert>

void stampa_stringa(const char *str){
  assert(str!= nullptr);
  const char * current = str;

  while(*current != '\0'){
    std :: cout << *current << std::endl;
    current ++;
  }

}

unsigned int lunghezza_Stringa(const char * str){
  /*if(str == nullptr){
    return -1;
  }*/
  assert(str != nullptr);
  const char * current = str;
  while(*current != '\0'){
    current++;
  }
  return static_cast<unsigned int>(current - str);
}

void inverti_stringa(char *str){
  char *start = str;
  char *end = str + lunghezza_Stringa(str) -1;

  while(start < end){
    std::swap(*start, *end);
    start++;
    end--;
  }
}

  char *clona_stringa(const char *str){
    int sz = lunghezza_Stringa(str);
    char *out = new char[sz +1];
    for (size_t i = 0; i < sz +1; i++) {
      out[i] = str[i];
    }
    return out;
  }

char *unisci_string(const char * str1, const char *str2){
  int sz1 = lunghezza_Stringa(str1);
  int sz2 = lunghezza_Stringa(str2);
  char *out = new char[sz1 + sz2 + 1];
  for (size_t i = 0; i < sz1; i++) {
    out[i] = str1[i];
  }
  for (size_t i = sz1; i < sz1 + sz2; i++) {
    out[i] = str2[i -sz1];
  }

  return out;

}

const char *cerca_stringa(const char * s1, const char * s2){
  int sz = lunghezza_Stringa(s1);
  int sz2 = lunghezza_Stringa(s2);
  for (size_t i = 0; i < sz; i++) {
    int j = 0;
    while((j < sz2) && (i + j < sz)&&(s1[i + j] == s2[j])){
      j++;
      if(j == sz2){
        return s1 + i;
      }
      if(i + j >= sz){
        return nullptr;
      }
    }

    return nullptr;
  }
}

  void sostituisci_stringa(char *s1, const char *s2){

    int szt = lunghezza_Stringa(s2);
    int szs = lunghezza_Stringa(s1);

    assert(szt == szs);

    char *token = const_cast<char *>(cerca_stringa(s1, s2));
    while(token != nullptr){
      for (size_t i = 0; i < szt ;  ++i)
        token[i] = s1[i];
      const char *token = const_cast<char *>(cerca_stringa(token + szs, s2));
    }

  }
