#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

/* struct dirent *readdir(DIR *dirp);
 *
 * struct dirent {
 *               ino_t          d_ino;       /* Inode number
 *              off_t          d_off;       /* Not an offset; see below
 *             unsigned short d_reclen;    /* Length of this record
 *            unsigned char  d_type;      /* Type of file; not supported by all filesystem types
 * char           d_name[256]; /* Null-terminated filename
 * };
 */

int main(int argc, char *argv[]){
  struct dirent *dir;
  DIR *directory = opendir(argv[1]);

  dir = readdir(directory);

  while((dir = readdir(directory)) != NULL){
    if(dir->d_type == DT_REG){
      printf("Filename: %s \n", dir->d_name);
    }
    else if (dir->d_type == DT_DIR ){
      printf("Directory name: %s/\n", dir->d_name);
    }
    else if (dir->d_type == DT_LNK){
      char a[50];
      readlink(dir->d_name, a, 50);
      printf("Link: %s -> %s\n", dir->d_name, a);
    }
  }

  closedir(directory);

  return 0;
}
