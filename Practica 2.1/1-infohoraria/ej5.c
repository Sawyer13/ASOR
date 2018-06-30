#include <time.h>
#include <stdio.h>
#include <sys/time.h>

/* struct tm *localtime(const time_t *timep);
 *
 * struct tm {
 *              int tm_sec;    /* Seconds (0-60)
 *              int tm_min;    /* Minutes (0-59)
 *              int tm_hour;   /* Hours (0-23)
 *              int tm_mday;   /* Day of the month (1-31)
 *              int tm_mon;    /* Month (0-11)
 *              int tm_year;   /* Year - 1900
 *              int tm_wday;   /* Day of the week (0-6, Sunday = 0)
 *              int tm_yday;   /* Day in the year (0-365, 1 Jan = 0)
 *              int tm_isdst;  /* Daylight saving time
 *          };
*/

int main(){
  time_t timer;
  timer = time(NULL);

  struct tm total;

  total = *localtime(&timer);

  printf("This year is: %d\n", total.tm_year+1900);

  return 0;
}
