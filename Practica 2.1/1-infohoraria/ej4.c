#include <time.h>
#include <stdio.h>
#include <sys/time.h>

/* int gettimeofday(struct timeval *tv, struct timezone *tz);
 *
 *           struct timeval {
 *               time_t      tv_sec;     /* seconds
 *              suseconds_t tv_usec;    /* microseconds
 *          };
 *
*/

int main(){
  struct timeval start, end;
  int i;

  i = gettimeofday(&start, NULL);

  for(int i = 0; i < 10000; i++);

  i = gettimeofday(&end, NULL);

  printf("%d seconds and %d microseconds\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

  return 0;
}
