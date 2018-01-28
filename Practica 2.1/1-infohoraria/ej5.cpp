#include <iostream>
using namespace std;
#include <sys/time.h>
       #include <time.h>

extern long timezone;

/*
  char *asctime(const struct tm *tm);

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
tm *tm_es;
time_t timer;

tm_es = *localtime(time(timer));

cout << "Segundos: " << time(&timer) << endl;
cout << "Estamos en el ano: " << tm_es->tm_year << endl;

return 0;
}
