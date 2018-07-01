#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  char buff[100];
  printf("Ejecucion del comando: \n\n");

  char *args[] = {argv[1], argv[2], NULL};
  execvp(args[0], args);

  printf("El comando termino de ejecutarse\n\n");

  return 0;
}
