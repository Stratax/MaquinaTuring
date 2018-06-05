#include "maquina.h"

using namespace std;

void pausa(int mili_sec);

int main(int argc, char const *argv[]) {
  MaquinaTuring mt;
  mt.getDelta(1).printFunction();
  return 0;
}

void pausa(int mili_sec){
  clock_t t = clock() + (mili_sec*CLOCKS_PER_SEC/1000);
  while(clock()<t);
}
