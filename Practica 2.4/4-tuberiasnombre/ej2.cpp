#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int fd = open("tuberia", O_CREAT|O_WRONLY, 0666);

  string arg = string(argv[1])+"\n";
  
  write(fd,arg.c_str(),arg.length());

  close(fd);
  
  return 0;
}
