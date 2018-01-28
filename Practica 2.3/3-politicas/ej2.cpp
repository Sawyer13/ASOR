#include <iostream>
using namespace std;
#include <sched.h>


/*
política actual de planificación del pid 4007: SCHED_OTHER
política actual de planificación del pid 4007: 0

getpriority(2)
        Return the nice value of a thread, a process group, or the set of threads owned by a specified user.


sched_getscheduler(2)
        Return the scheduling policy of a specified thread.

sched_get_priority_max(2)
        Return the maximum priority available in a specified scheduling policy.

sched_get_priority_min(2)
        Return the minimum priority available in a specified scheduling policy.



*/

int main(int argc, char *argv[]){
  pid_t pid = 4007;
  struct sched_param param;
  
  int i = sched_getparam(pid, &param);

  int polit = sched_getscheduler(pid);
  cout << "politica  acutal de planificacion del pid 4007: " << polit << endl;
  cout << "prioridad actual de planificacion del pid 4007: " << param.sched_priority << endl;
  cout << "Valores minimos: " << sched_get_priority_min(polit) << endl;
  cout << "Valores maximos: " << sched_get_priority_max(polit) << endl;
  return 0;
}
