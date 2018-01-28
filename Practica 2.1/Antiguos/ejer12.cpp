#include <iostream>
using namespace std;
#include <unistd.h>
#include <limits.h>

int main(){

  cout << sysconf(3) << endl;
  cout << confstr(sysconf(3)) << endl; 

  return 0;
}
