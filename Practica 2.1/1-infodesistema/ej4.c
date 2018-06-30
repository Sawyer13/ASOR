#include <sys/utsname.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  char a[] = "/home/sawyer";

  printf("Numero maximo de enlaces: %d \n", pathconf(a, _PC_LINK_MAX));
  printf("Tamano maximo de una ruta: %d \n", pathconf(a, _PC_PATH_MAX));
  printf("Tamano maximo del nombre de un fichero: %d \n", pathconf(a, _PC_NAME_MAX));

  return 0;
}
