#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pwd.h>

/*
 * struct passwd {
 *   char   *pw_name;       /* username
 *   char   *pw_passwd;     /* user password
 *   uid_t   pw_uid;        /* user ID
 *   gid_t   pw_gid;        /* group ID
 *   char   *pw_gecos;      /* user information
 *   char   *pw_dir;        /* home directory
 *   char   *pw_shell;      /* shell program
 * };
*/


int main(){
  struct passwd pass;
  pass = *getpwuid(getuid());

  printf("User:%d \nHome directory:%s \nUser info: %s \n", pass.pw_uid, pass.pw_dir, pass.pw_gecos);

  return 0;
}
