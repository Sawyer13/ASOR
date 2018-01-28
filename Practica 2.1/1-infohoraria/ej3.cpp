#include <iostream>
using namespace std;
#include <time.h>

/*
 char *ctime(const time_t *timep);
           struct tm {
               int tm_sec;         // seconds 
               int tm_min;         // minutes 
               int tm_hour;        // hours 
               int tm_mday;        // day of the month 
               int tm_mon;         // month
               int tm_year;        // year 
               int tm_wday;        // day of the week 
               int tm_yday;        // day in the year 
               int tm_isdst;       // daylight saving time 
           };
*/

int main(){
  time_t timer;
  timer = 0;
  //timer = 1516906859;
  char *cadena;

  cadena = ctime(&timer);

  cout << "Fecha y hora y toh: " << cadena << endl;

return 0;
}
