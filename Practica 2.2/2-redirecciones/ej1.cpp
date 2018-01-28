#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
  //int fd = open("prueba.txt", O_CREAT, 0666);
  int apertura = open("s.txt", O_CREAT | O_WRONLY, 0666);
  
  cout << "Texto anterior" << endl;

  dup2(apertura, 1);

  cout << "Texto siguiente" << endl;

  close(apertura);

  return 0;
}
