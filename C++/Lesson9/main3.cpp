//for read and write
#include <iostream>
#include "dbuffer.h"
#include <cassert>
#include <fstream> //std::ofstream

int main(int argc, char *argv[]) {
  dbuffer src(10, 50);
  std::ofstream ofs;
  ofs.open("out.txt");
  ofs << src << std::endl;
  ofs.close();

  ifstream inFile;
  inFile.open("out.txt");

  if(inFile.fail()){
    cerr <<"Error on opening file" << endl;
    exit(1);
  }

  int size;
  //il primo elemento che legge sono quanti elementi ha
  inFile >> size;
  dbuffer dst(size);

  for (size_t i = 0; i < size; i++) {
    ifs >> dst[i];
  }
  inFile.close();

  std::cout << dst << std::endl;

  //dbuffer dst2;
  //ifs >> dst2;

  return 0;
}
