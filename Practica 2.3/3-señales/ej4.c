#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int contINT = 0;
int contSTP = 0;

//Instalar manejador para señal SIGSTP
void handler(int signal){
  if (signal == SIGINT) {
    contINT++;
  }
  else if (signal == SIGTSTP) {
    contSTP++;
  }
}

int main() {
  printf("Pid del programa: %d", getpid());

  struct sigaction act;

  //SIGINT
  sigaction(SIGINT, NULL, &act);
  act.sa_handler = handler;
  sigaction(SIGINT, &act, NULL);

  //SIGSTP
  sigaction(SIGTSTP, NULL, &act);
  act.sa_handler = handler;
  sigaction(SIGTSTP, &act, NULL);

  while((contINT + contSTP) < 10){
    sleep(1);
  }

  return 0;
}
