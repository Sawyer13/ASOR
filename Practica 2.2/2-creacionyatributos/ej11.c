#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  struct stat leer;
  char symlinkUser[30];
  char linkUser[30];
  int r = stat(argv[1], &leer);

  if ((leer.st_mode & S_IFMT) == S_IFREG) {
    /* Handle regular file */
    strcpy(linkUser, argv[1]);
    strcat(linkUser, ".hard");
    strcpy(symlinkUser, argv[1]);
    strcat(symlinkUser, ".sym");

    link(argv[1], linkUser);
    symlink(argv[1], symlinkUser);
  }

  return 0;
}
