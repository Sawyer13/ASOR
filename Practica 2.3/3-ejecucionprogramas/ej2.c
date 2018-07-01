#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
  int fdSalida, fdError, fdEntrada;
  fdSalida = open("/tmp/daemon.out", O_CREAT | O_RDWR | O_TRUNC, 0666);
  fdError = open("/tmp/daemon.err", O_CREAT | O_RDWR | O_TRUNC, 0666);
  fdEntrada = open("/dev/null", O_CREAT | O_RDWR | O_TRUNC, 0666);

  dup2(fdEntrada, 0);

  pid_t pid = fork();

  if ( pid == -1 ) { // Error
    perror("fork");
    dup2(fdError, 2);
  } else if (pid == 0) { // Hijo
    dup2(fdSalida, 1);
    printf("<hijo>Padre del proceso: %d\n", getppid());
    printf("<hijo>Grupo de proceso: %d\n", getpgid(getpid()));
    printf("<hijo>Identificador de la sesion: %d\n\n", getsid(getpid()));

    printf("Ejecucion del comando: \n\n");

    char *args[] = {argv[1], argv[2], NULL};
    execvp(args[0], args);

    printf("El comando termino de ejecutarse\n\n");
  } else { // Nos cargamos al padre para crear un demonio
    sleep(5);
    exit(0);
  }

  close(fdSalida);
  close(fdEntrada);
  close(fdError);

  return 0;
}
