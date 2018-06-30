#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
  int resultado;
  resultado = setuid(0);

  printf ("El codigo del error: %d\n", resultado);
  perror(strerror(resultado));
  printf("\n");

  return 0;
}
