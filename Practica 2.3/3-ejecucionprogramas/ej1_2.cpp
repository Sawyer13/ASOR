#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>

int main(){
  /**************************************
   * char *args[] = {"ls", "-l", NULL}; *
   * int i = execvp(args[0], args);     *
   **************************************/

  // Funciona :D
  int i = execlp("ls", "ls", "-l", NULL);
  
  return 0;
}
