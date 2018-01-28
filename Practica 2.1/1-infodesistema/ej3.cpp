#include <iostream>
#include <unistd.h>
#include <limits.h>

using namespace std;


int main() {
  int r;
  cout << "Arg Max:\t " << sysconf(_SC_ARG_MAX) << endl;
  cout << "Child max:\t " << sysconf(_SC_CHILD_MAX) << endl;
  cout << "Files open max:\t " << sysconf(_SC_OPEN_MAX) << endl;
  return 0;
}
