#include <iostream>
#include <unistd.h>
#include <limits.h>

using namespace std;


int main() {
  int r;
  char a[]="/home";

  cout << "maximum number of links:\t " << pathconf(a,_PC_LINK_MAX) << endl;
  cout << "maximum  length  of  a  relative  pathname:\t " << pathconf(a,_PC_PATH_MAX) << endl;
  cout << "maximum  length  of  a  file:\t " << pathconf(a,_PC_NAME_MAX) << endl;

  return 0;
}
