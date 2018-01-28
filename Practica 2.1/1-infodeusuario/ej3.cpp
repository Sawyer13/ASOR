#include <iostream>
using namespace std;
       #include <unistd.h>
       #include <sys/types.h>
       #include <pwd.h>


/*
           struct passwd {
               char   *pw_name;       // username 
               char   *pw_passwd;     // user password 
               uid_t   pw_uid;        // user ID 
               gid_t   pw_gid;        // group ID 
               char   *pw_gecos;      // user information 
               char   *pw_dir;        // home directory 
               char   *pw_shell;      // shell program 
           };

       struct passwd *getpwuid(uid_t uid);

*/

int main(){
  passwd *pass;

  pass = getpwuid(getuid());

  cout << "Username: " << pass->pw_name << "\t Directory: " << pass->pw_dir << "\t User info: " << pass->pw_gecos << endl;

  return 0;
}
