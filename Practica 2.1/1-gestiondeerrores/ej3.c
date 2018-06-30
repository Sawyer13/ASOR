#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
  for(int i = 0; i < 134; i++){
    perror(strerror(i));
    printf("\n");
  }

  return 0;
}
