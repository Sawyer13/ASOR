#include <time.h>
#include <stdio.h>

/* La función principal para obtener la hora del sistema es time(2). Escribir un programa que obtenga la hora usando esta función y la muestre en el terminal.
*/

int main(){
  time_t timer;

  timer = time(NULL);

  printf("Hora en segundos: %d\n", timer);

  return 0;
}
