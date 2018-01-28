#include <iostream>
using namespace std;
#include <unistd.h>

/*getpid(2), getppid(2),
  getpgid(2), getsid(2)*/

int main(){
  pid_t pid = getpid();
  
  cout << "Pid del actual proceso: " << pid << endl;
  cout << "Pid del procedo padre: " << getppid() << endl;
  cout << "Pid del grupo: " << getpgid(pid) << endl;
  cout << "pid de la sesion: " << getsid(pid) << endl;
  
  return 0;
}
