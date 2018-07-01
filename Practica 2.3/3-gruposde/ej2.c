#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){

  printf("Identificador del proceso: %d\n", getpid);
  printf("Padre del proceso: %d\n", getppid);
  printf("Grupo de proceso: %d\n", getpgid);
  printf("Identificador de la sesion: %d\n", getsid);

  return 0;
}
