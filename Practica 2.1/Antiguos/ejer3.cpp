#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(){

  /* Comprobar la ocurrencia de error y notificarlo con la llamada adecuada */

  //El numero de errores disponibles es 132
  for(int i = 0; i < 255; i++){
    cout << i << ".- Mensaje de error: " << strerror(i) << endl;
  }

  return 1;
}
