#include <iostream>
using namespace std;

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>

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
    int retval;
    char buffer[256];
    /* Watch stdin (fd 0) to see when it has input. */

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    /* Wait up to five seconds. */

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don't rely on the value of tv now! */

    if (retval == -1)
      perror("select()");
    else if (retval){
      cout << "Data is available now." << "Datos retval: " << retval << endl;
      /* FD_ISSET(0, &rfds) will be true. */
      read(0, buffer, 80);
      printf("Se ha recibido la cadena: %s\n", buffer);
    }
    else
      cout << "No data within five seconds." << endl;  
  
  return 0;
}
