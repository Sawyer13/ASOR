#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/******************************************************
 * Comunicación por tuberías. Escribir un programa que emule el comportamiento
 * de la shell en la ejecución de una sentencia en la forma: comando1 argumento1 |
 * comando2 argumento2. El programa abrirá una tubería sin nombre y creará un hijo:
 * El programa padre ejecutará comando1 argumento1 y redireccionará la salida estándar
 * al extremo de escritura de la tubería.
 * El hijo, ejecutará comando2 argumento2, en este caso la entrada estándar deberá duplicarse
 *  con el extremo de lectura de la tubería.
 * Probar el funcionamiento con una sentencia similar a: ./ejercicio1 echo 12345 wc -c
  */

#define R 0
#define W 1

int main(int argc, char *argv[]){
  int pipefd[2];
  pipe(pipefd);
  char buf;
  pid_t cpid;

  cpid = fork();
  if (cpid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (cpid == 0) {    /* Child reads from pipe */
    close(pipefd[W]);          /* Close unused write end */
    dup2(pipefd[R], 0);
    close(pipefd[R]);
    // El padre ejecuta comando1 argumento1

    //char *args[] = {argv[3], argv[4], NULL};
    //exevlp(args[0], args);
    execlp(argv[3],argv[3],argv[4],NULL);
  } else {            /* Parent writes argv[1] to pipe */
    close(pipefd[R]);          /* Close unused read end */
    dup2(pipefd[W], 1);
    close(pipefd[W]);          /* Reader will see EOF */

    // El padre ejecuta comando1 argumento1
    //char *args[] = {argv[1], argv[2], NULL};
    //execvp(args[0], args);
    execlp(argv[1],argv[1],argv[2],NULL);

    wait(0);                /* Wait for child */
  }


  return 0;
}
