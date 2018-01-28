#include <iostream>
using namespace std;
       #include <unistd.h>
       #include <sys/types.h>
/*
       uid_t getuid(void);
       uid_t geteuid(void);*/

int main(){
  cout << "Usuario real: " << getuid() << endl;
  cout << "Usuario efectivo: " << geteuid() << endl;


  return 0;
}
