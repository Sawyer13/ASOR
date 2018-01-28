#include <iostream>
using namespace std;
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

/*

struct dirent {
               ino_t          d_ino;       /* Inode number 
               off_t          d_off;       /* Not an offset; see below/
               unsigned short d_reclen;    /* Length of this record 
               unsigned char  d_type;      /* Type of file; not supported
                                              by all filesystem types 
               char           d_name[256]; /* Null-terminated filename 
           };


*/

/**** Violacion del segmento ****/
int main(int argc, char *argv[]){
  DIR *direc = opendir(argv[1]);
  dirent *dir = readdir(direc);

  if(dir->d_type == DT_REG){
    cout << "Nombre del fichero: " << argv[1] << endl;
  }
  else if(dir->d_type == DT_DIR){
    cout << "Nombre del directorio: " << argv[1] << "/" << endl;
  }
  else if(dir->d_type == DT_LNK){
    char *buf[100];
    size_t num;
    num = readlink(argv[1], *buf, num);
    cout << "Link: " << argv[1] << "->" << buf << endl;
  }
  else{
    cout << "Nombre ejecutable: " << argv[1] << "*" << endl;
  }
  
  return 0;
}
