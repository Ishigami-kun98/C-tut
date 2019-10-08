#include "romano.h"

void print_roman_helper(int digit, ){
  //switch se noi siamo davanti a un po di porte, sulle basi delle nostre proprieta
  //possiamo entrare solo in una di queste porte, e queste vengono gestite da diverse
  //case se digit = 0 e esiste il case per questo allora va dentro in quella porta.
  //Posso gestire alcuni casi speciali se non sono dentro allova va nella porta default.
  switch (digit) {
    case 1: cout << s1 << endl;
    case 2: cout << s1 << s1 << endl;
    case 3: cout << s1 << s1 << s1<< endl;
    default:
  }
}

void print_roman(int n){
  //Usiamo questa funzione per aiutarci un pocchino
  print_roman_helper(n / 1000, 'M');
  n = n % 1000;
  print_roman_helper(n / 100, 'C');
  n = n % 100;
  print_roman_helper(n / 10, 'X');
  n = n % 10;
}
