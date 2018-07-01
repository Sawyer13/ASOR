#include <sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/* int sched_getscheduler(pid_t pid);
 *
 *
 * sched_get_priority_min
 *
 * sched_get_priority_max
 */


int main(){
  int pid;
  struct sched_param param;
  pid = getpid();
  int policy;

  policy = sched_getscheduler(pid);

  printf("Pid %d's current shceduling policy: %d\n", pid, policy);

  printf("Pid %d's current shceduling min priority: %d\n", pid, sched_get_priority_min(policy));

   printf("Pid %d's current shceduling max priority: %d\n", pid, sched_get_priority_max(policy));


  return 0;
}
