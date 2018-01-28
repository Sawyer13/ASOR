#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
  /**************************************
   * char *args[] = {"ls", "-l", NULL}; *
   * int i = execvp(args[0], args);     *
   *
   * o
   *
   * i = execlp("ls", "ls", "-l", NULL);
   **************************************/
  pid_t mi_pid, pid;
  pid = fork();
  int i = 0;

  int daemon = open("/tmp/daemon.out", O_CREAT|O_RDWR, 0666);
  int error = open("/tmp/daemon.err", O_CREAT|O_RDWR, 0666);
  int null = open("/dev/null", O_CREAT|O_RDWR, 0666); 
  
  switch (pid) {
  case -1:
    {
      dup2(error,2);
      perror("fork");
      exit(-1);
    }break;
  case 0:
    {
      dup2(daemon,1);
      cout << "Soy el proceso hijo y ejecuto un ls: " << endl;
      // Funciona :D
      char *args[] = {"ls", "-l", NULL};
      int i = execvp(args[0], args);
    }break;
  default:
    cout << "Soy el proceso padre y no hago nada :)" << endl;
    wait(0);
  }

  //¿Entrada estandar?
  
  return 0;
}
