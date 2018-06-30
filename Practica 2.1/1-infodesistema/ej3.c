#include <sys/utsname.h>
#include <stdio.h>
#include <unistd.h>

int main(){

  /*  int uname(struct utsname *buf);
   *
   *           struct utsname {
   *              char sysname[];    /* Operating system name (e.g., "Linux")
   *              char nodename[];   /* Name within "some implementation-defined network"
   *               char release[];    /* Operating system release (e.g., "2.6.28")
   *           char version[];    /* Operating system version
   *            char machine[];    /* Hardware identifier
   *	             #ifdef _GNU_SOURCE
   *            char domainname[]; /* NIS or YP domain name
   *        #endif
   *        };
   */

  printf("Longitud maxima de los argumentos: %d \n", sysconf(_SC_ARG_MAX));
  printf("Numero maximo de hijos: %d \n", sysconf(_SC_CHILD_MAX));
  printf("Numero maximo de ficheros: %d \n", sysconf(_SC_HOST_NAME_MAX));

  return 0;
}
