#include <sys/utsname.h>
#include <stdio.h>

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

  struct utsname name;
  int result;

  result = uname(&name);

  printf("Sistema operativo: %s \n", name.sysname);
  printf("Distribucion: %s \n", name.nodename);
  printf("Release: %s \n", name.release);
  printf("Version: %s \n", name.version);
  printf("Machine: %s \n", name.machine);

  return 0;
}
