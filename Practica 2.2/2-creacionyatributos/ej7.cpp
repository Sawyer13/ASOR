#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  umask(0033);
  open("prueba", O_CREAT, 0737);
  open("prueba2", O_CREAT, 0777);
   
  return 0;
}
