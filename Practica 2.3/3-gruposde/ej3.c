#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <error.h>
#include <string.h>
#include <sys/wait.h>

int main(){
  pid_t pid = fork();

  // Si queremos un demonio hacemos que el padre termine antes que el hijo
  if ( pid == -1 ) { // Error
    perror("fork");
  } else if (pid == 0) { // Hijo
    printf("<hijo>Padre del proceso: %d\n", getppid());
    printf("<hijo>Grupo de proceso: %d\n", getpgid(getpid()));
    printf("<hijo>Identificador de la sesion: %d\n\n", getsid(getpid()));
  } else { // Padre, pid es el PID del hijo
    wait(0);
    printf("<padre>Padre del proceso: %d\n", getppid());
    printf("<padre>Grupo de proceso: %d\n", getpgid(getpid()));
    printf("<padre>Identificador de la sesion: %d\n\n", getsid(getpid()));
  }

  return 0;
}
