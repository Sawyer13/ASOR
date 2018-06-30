#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

/*uid=1000(sawyer) gid=1000(sawyer) grupos=1000(sawyer)*/

int main(){
  printf("uid=%d gid=%d \n", getuid(), getgid());

  return 0;
}
