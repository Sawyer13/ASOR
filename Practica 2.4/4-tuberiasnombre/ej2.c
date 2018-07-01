#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
    // Con tuberia ya creada
  int fd = open("tuberia", O_WRONLY);
  write(fd, argv[1], strlen(argv[1]));

  return 0;
}
