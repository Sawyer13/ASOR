#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(){
  int apertura = open("s.txt", O_CREAT | O_WRONLY, 0666);
  int aux;

  printf("Texto anterior\n");

  //1 de salida
  dup2(1, aux);
  dup2(apertura, 1);

  printf("Texto siguiente\n");

  // 2 de error
  //Si el enunciado pide escribir el error en el cihero:
  // dup2(apertura, 2);

  //Si el enunciado pide escribir en la salida el error
  dup2(aux, 2);

  perror(strerror(15));

  close(apertura);

 return 0;
}
