#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>


int main(){

  /* Comprobar la ocurrencia de error y notificarlo con la llamada adecuada */

  //setuid(0);

  cout << setuid(0) << endl;

  return 1;
}
