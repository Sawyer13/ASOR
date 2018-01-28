#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
using namespace std;

int main() {
  for (int i = 0; i <= 255; i++) {
    perror(strerror(i));
  }
  return 0;
}


