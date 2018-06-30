#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
  int resultado;
  resultado = setuid(0);

  printf ("Obtenemos el siguiente error: %s\n", strerror(resultado));

  return 0;
}
