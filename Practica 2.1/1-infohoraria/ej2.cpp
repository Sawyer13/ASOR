#include <iostream>
using namespace std;
#include <time.h>

int main(){
  time_t timer;
  timer = 0;
  //timer = 1516906859;

  timer = time(&timer);

cout << timer << endl;

return 0;
}
