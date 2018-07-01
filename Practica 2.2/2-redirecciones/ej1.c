#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
  int apertura = open("s.txt", O_CREAT | O_WRONLY, 0666);

  printf("Texto anterior\n");

  dup2(apertura, 1);

  printf("Texto siguiente");

  close(apertura);

 return 0;
}
