#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
  int fd = open("./archivoNew.txt", O_CREAT | O_TRUNC, 0645);


  return 0;
}
