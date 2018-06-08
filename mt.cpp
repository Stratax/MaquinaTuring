#include "maquina.h"
#include<iomanip>
using namespace std;

void pausa(int mili_sec);

int main(int argc, char const *argv[]) {
  int i = 5;
  char currentState = '0';
  MaquinaTuring mt(argv[1]);
  string c_aux = mt.getCadena();
  while(1){
    int index = mt.findDelta(currentState,c_aux[i-1]);
    if(index == -1){
      if(currentState == mt.getAccept()){
        cout << "Aceptados"<<endl;
        break;
      }else{
        cout <<"No aceptado"<<endl;
        break;
      }
    }
    system("clear");
    cout<<c_aux<<endl;
    cout<<setfill(' ')<<setw(i);
    cout <<"^"<<endl;
    mt.getDelta(index).getFunction();
    c_aux[i-1]=mt.getDelta(index).getTargetSymbol();
    currentState = mt.getDelta(index).getTargetState();
    i+= mt.getDelta(index).getMovment();
    pausa(100);
  }


//mt.printTable();

  return 0;
}

void pausa(int mili_sec){
  clock_t t = clock() + (mili_sec*CLOCKS_PER_SEC/1000);
  while(clock()<t);
}
