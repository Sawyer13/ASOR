#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>


int main(){
  pid_t mi_pid, pid;
  pid = fork();

  switch (pid) {
    case -1:
      perror("fork");
      exit(-1);
    case 0:
      mi_pid = getpid();
      cout << "Proceso hijo " << mi_pid << " (padre: " << getppid() << ")" << "con pid de grupo: " << getpgid(mi_pid) << " y pid de sesion: " << getsid(mi_pid) << endl;
      break;
    default:
      mi_pid = getpid();
      cout << "Proceso padre " << mi_pid << " (hijo: " << pid << ")" << " con pid de grupo: " << getpgid(mi_pid) << " y pid de sesion: " << getsid(mi_pid) << endl;
      break;	
  }

  return 0;
}
