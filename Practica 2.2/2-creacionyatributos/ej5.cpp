#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  open("prueba", O_CREAT, O_TRUNC|S_IWUSR|S_IRGRP|S_IROTH|S_IXOTH);
  open("prueba2", O_CREAT, 0645);
  
  return 0;
}
