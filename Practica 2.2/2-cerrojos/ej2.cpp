#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(){
  int fd = open("s.txt", O_CREAT|O_RDWR, 0666);
  time_t timer;
  
  struct flock c;
  //Desbloqueo el cerrojo
  c.l_type = F_UNLCK; c.l_whence = SEEK_SET; c.l_start = 0; c.l_len = 0;
  fcntl(fd,F_GETLK, &c);

  if (c.l_type == F_UNLCK){ //Unlocked
    cout << "Cerrojo desbloqueado" << endl;
    c.l_type = F_WRLCK; //Fijo cerrojo de escritura
    fcntl(fd,F_SETLKW,&c);
    cout << "Fijo cerrojo de escritura" << endl;
    /**************************************************/
    dup2(fd,1);
    time(&timer);
    cout << "Hora: " << ctime(&timer) << endl; //Muestro la hora
    /**************************************************/
    sleep(3); //Suspendo ejecución durante 3 segundos
    c.l_type = F_UNLCK;  //Libero el cerrojo
    fcntl(fd, F_SETLKW, &c);
    cout << "Desbloqueo otra vez el cerrojo" << endl;
    close(fd);
  }else{
    cout << "Cerrojo bloqueado" << endl;
  }

  return 0;
}
