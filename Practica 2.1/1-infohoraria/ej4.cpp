#include <iostream>
using namespace std;
#include <sys/time.h>
       #include <time.h>

extern long timezone;

/*
       #include <sys/time.h>

       int gettimeofday(struct timeval *tv, struct timezone *tz);

           struct timeval {
               time_t      tv_sec;     // seconds 
               suseconds_t tv_usec;    // microseconds 
           };

           struct timezone {
               int tz_minuteswest;     // minutes west of Greenwich 
               int tz_dsttime;         // type of DST correction 
           };



*/

int main(){
  timeval start, end;

  int i = gettimeofday(&start, NULL);

  for(int i = 0; i < 10000; i++){}

  gettimeofday(&end, NULL);

  cout << start.tv_usec  << endl;

return 0;
}
