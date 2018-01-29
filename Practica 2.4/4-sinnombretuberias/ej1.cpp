#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*

El programa padre ejecutará comando1 argumento1 y redireccionará la salida estándar al extremo de escritura de la tubería.
El hijo, ejecutará comando2 argumento2, en este caso la entrada estándar deberá duplicarse con el extremo de lectura de la tubería.
Probar el funcionamiento con una sentencia similar a: ./ejercicio1 echo 12345 wc -c

fd[0] para lectura y fd[1] para escritura.

comando1 argumento1 | comando2 argumento2.

*/

#define PR 0
#define PW 1

int main(int argc, char *argv[]){
  int pipefd[2];

  // Abro tuberia sin nombre
  pipe(pipefd);
  // Creo un hijo
  pid_t pid = fork();

  switch(pid){
  case -1: // Error
    {
    perror("fork()");
    }break;
  case 0:
    { // Hijo
    close(pipefd[PW]);
    dup2(pipefd[PR],0);
    close(pipefd[PR]);
    execlp(argv[3],argv[3],argv[4],NULL);
    }break;
  default:
    { // Padre, pid es el PID del hijo
      close(pipefd[PR]);
      dup2(pipefd[PW],1);
      close(pipefd[PW]);
      execlp(argv[1], argv[1], argv[2], NULL);
      wait(0);
    }
  }
  
  return 0;
}
