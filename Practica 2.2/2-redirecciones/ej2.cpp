#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
 #include <string.h>

int main(int argc, char *argv[]){
  //int fd = open("prueba.txt", O_CREAT, 0666);
  int apertura = open("s.txt", O_CREAT | O_WRONLY, 0666);
  
  cout << "Escritura antes: " << argv[1] << endl;
  
  dup2(apertura, 1);
  
  cout << "Texto siguiente" << endl;
  cout << "El usuario escribió: " << argv[1] <<  endl;

  dup2(apertura, 2);
  perror(strerror(1));

  close(apertura);

  return 0;
}
