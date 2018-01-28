#include <iostream>
using namespace std;
#include <stdlib.h>


int main(int argc, char *argv[]){
  cout << "Ejecutando el comando " << argv[1] << endl;

  system(argv[1]);
  
  return 0;
}
