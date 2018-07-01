#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <fcntl.h>


int main(){
  int a = mkfifo("tuberia2", 644);
  int b = mkfifo("tuberia", 644);
  char buffer[256];
  int rc;

  fd_set set;
  struct timeval timeout;

  int fd1 = open("tuberia", O_RDWR, 0666);
  int fd2 = open("tuberia2", O_RDWR, 0666);
  int fdFinal;

  //Segundos que espero
  timeout.tv_sec = 10;
  timeout.tv_usec = 0;

  if(fd1 > fd2){
    fdFinal = fd1;
  }else{
    fdFinal = fd2;
  }

  FD_ZERO(&set);
  // Le meto la tuberia
  FD_SET(fd1, &set);
  // Le meto la otra tuberia
  FD_SET(fd2, &set);

  rc = select(fdFinal+1, &set, NULL, NULL, &timeout);

  if (rc == -1)
    perror("select()");
  else if (rc) { //FD_ISSET(0, &set) == 1
    // Ya nos han dado algo que leer
    printf("Data is avaible now\n");
    /*Deberiamos ver por cual nos ha venido*/
    if(FD_ISSET(fd1,&set)){
      read(fd1, buffer, sizeof(buffer));
      printf("Recibidos los siguientes datos en la tuberia 1: %s\n", buffer);
    }else{
      read(fd2, buffer, sizeof(buffer));
      printf("Recibidos los siguientes datos en la tuberia 2: %s\n", buffer);
    }
  } else
    printf("Timeout.\n");

  return 0;
}
