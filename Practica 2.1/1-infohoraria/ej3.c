#include <time.h>
#include <stdio.h>

/* char *asctime(const struct tm *tm);
*/

int main(){
  time_t timer;

  timer = time(NULL);

  printf("Hora: %s\n", ctime(&timer));

  return 0;
}
