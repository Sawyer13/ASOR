#include <sys/file.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

int main(){
  struct flock c;
  time_t timer;

  int fd = open("prueba.txt", O_CREAT | O_RDWR, 0644);
  int aux;
  dup2(1, aux);
  c.l_type = F_WRLCK;
  c.l_whence = SEEK_SET;
  c.l_start = 0;
  c.l_len = 0;
  fcntl(fd, F_GETLK, &c);

  if (c.l_type == F_UNLCK){ // Unlocked
    c.l_type = F_WRLCK;
    fcntl(fd, F_SETLKW, &c); // Lock
    printf("Cerrojo bloqueado\n");

    timer = time(NULL);
    dup2(fd, 1);
    printf("Momento actual: %s",ctime(&timer));
    sleep(2);
    dup2(aux, 1);

    c.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &c); // Unlock
    printf("Cerrojo desbloqueado\n");
  } else // Locked by c.l_pid

    return 0;
}
