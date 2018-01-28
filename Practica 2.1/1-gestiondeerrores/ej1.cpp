
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
using namespace std;

int main() {
  int result;
  result = setuid(0);
  perror(strerror(result));
  return 0;
}
