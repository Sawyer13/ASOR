#include <iostream>
using namespace std;
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  string fileName = string(argv[1]);
  string fileRig = fileName+".hard";
  string fileSym = fileName+".sym";

  link(fileName.c_str(), fileRig.c_str());
  symlink(fileName.c_str(), fileSym.c_str());
  
  return 0;
}
