#include <iostream>
#include <sys/utsname.h>

using namespace std;


int main() {
  int r;
  utsname data;
  r = uname(&data);
  cout << (r==0?"ok":"error") << endl;
  cout << "Sysname: " << data.sysname << endl << "nodename: " << data.nodename << endl << "release: " << data.release << endl << "version: " << data.version << endl << "machine: " << data.machine << endl << "domainname: " << data.domainname << endl;
  return 0;
}
