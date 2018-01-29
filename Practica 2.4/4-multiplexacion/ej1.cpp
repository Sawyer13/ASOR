#include <iostream>
using namespace std;

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <fcntl.h>

/*

 FD_ZERO(&set);
 FD_SET(0, &set);
 timeout.tv_sec = 2;  
 timeout.tv_usec = 0;
 rc = select(1, &set, NULL, NULL, &timeout);

 struct timeval {
     long    tv_sec;         /* seconds 
     long    tv_usec;        /* microseconds 
 };

*/

int main(){
    fd_set rfds;
    struct timeval tv;
    int retval, fd;
    char buff[256];
    /* Watch stdin (fd 0) to see when it has input. */
    int tub1 = open("tuberia", O_CREAT|O_RDWR, 0666);
    int tub2 = open("tuberia2", O_CREAT|O_RDWR, 0666);

    
    FD_ZERO(&rfds);
    FD_SET(tub1, &rfds);
    FD_SET(tub2, &rfds);
    
    /* Wait up to five seconds. */

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    if(tub1 > tub2)
      fd = tub1;
    else
      fd = tub2;
    
    retval = select(fd+1, &rfds, NULL, NULL, &tv);

    if (retval == -1)
      perror("select()");
    else if (retval){
      cout << "Data is available now." << endl;
      /* FD_ISSET(0, &rfds) will be true. */
      if(FD_ISSET(tub1, &rfds)){
        read(tub1, &buff, sizeof(buff));
	cout << buff << endl;
      }
      else{
	read(tub2, &buff, sizeof(buff));
	cout << buff << endl;
      }
    }
    else
      cout << "No data within five seconds." << endl;  
  
  return 0;
}
