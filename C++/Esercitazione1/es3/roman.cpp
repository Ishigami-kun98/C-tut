#include "romano.h"
#include <iostream>

using namespace std;

static void print_roman_helper(int digit, char s1, char s2, char s3){
  //switch se noi siamo davanti a un po di porte, sulle basi delle nostre proprieta
  //possiamo entrare solo in una di queste porte, e queste vengono gestite da diverse
  //case se digit = 0 e esiste il case per questo allora va dentro in quella porta.
  //Posso gestire alcuni casi speciali se non sono dentro allova va nella porta default.
  switch (digit) {
    case 0:
      break;
    case 1: std:: cout << s1 ;
    break;
    case 2: std::cout << s1 << s1 ;
    break;
    case 3: std::cout << s1 << s1 << s1;
    break;
    case 4: std::cout << s1 << s2;
    break;
    case 9: std::cout << s1 << s3;
    break;
    default:
    std::cout << s2;
    print_roman_helper(digit -5, s1, s2, s3);
    break;
  }
}

void print_roman(int n){
  //Usiamo questa funzione per aiutarci un pocchino
  print_roman_helper(n / 1000, 'M', '?', '?');
  n = n % 1000;
  print_roman_helper(n / 100, 'C', 'D', 'M');
  n = n % 100;
  print_roman_helper(n / 10, 'X', 'L', 'C');
  n = n % 10;
  print_roman_helper(n, 'I', 'V', 'X');

}
