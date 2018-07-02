#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>


int main(){
  printf("Mi pid: %d\n", getpid());

  //Bloquear un conjunto de señales
  sigset_t set, pending;
  sigemptyset(&set);
  sigaddset(&set,SIGINT);
  sigaddset(&set,SIGTSTP);
  sigprocmask(SIG_BLOCK, &set, NULL);

  sleep(20);

  sigpending(&pending);
  if (sigismember(&pending, SIGINT)) {
    printf("He recibido la señal SIGINT\n");
  }
  else if (sigismember(&pending, SIGTSTP)) {
    printf("He recibido la señan SIGTSTP\n");
    sigemptyset(&set);
    // Desbloqueo la señal
    printf("Señal desbloqueada\n");
  }

  printf("Finalizando el programa\n");

  return 0;
}
