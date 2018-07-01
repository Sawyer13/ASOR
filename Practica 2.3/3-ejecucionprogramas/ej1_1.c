#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
  char buff[100];
  printf("Ejecucion del comando: \n\n");

  //printf("Tamano argc: %d\n", argc);

  for(int i = 1; i < argc; i++){
    //printf("Argumento: %s\n", argv[i]);
    strcat(buff, argv[i]);
    //printf("Concatenado: %s\n",buff);
    strcat(buff, " ");
    //printf("Con espacio: %s\n",buff);
  }

  system(buff);

  printf("El comando termino de ejecutarse\n\n");

  return 0;
}
