/********************************************************************
+   Implementación de las clases "Delta" y "MaquinaTuring"          *
+   Autor: López Calderón Adrián Aberto                             *
+   Escuela Superior de Cómputo (ESCOM-IPN)                         *
*********************************************************************/


#include "maquina.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Delta::Delta(){
    currentState='B';
    targetState='B';
    currentSymbol='B';
    targetSymbol='B';
    movment=2;
}

void Delta::getFunction(){
  cout <<"\nd(q"<<currentState<<","<<currentSymbol<<")-->(q"
       <<targetState<<","<<targetSymbol<<","<<movment<<")"<<endl;
}

void Delta::setFunction(string chain){
  currentState = chain[3];
  targetState = chain[10];
  currentSymbol = chain[5];
  targetSymbol = chain[12];
  if(chain[14]=='D')
    movment = 1;
  else
    movment = -1;
}

MaquinaTuring::MaquinaTuring(string file){
  nFunctions=0;
  string line;
  ifstream maquina(file);
  string listStates="-";
  int counter = 0;

  if(maquina.is_open()){
    while (getline(maquina,line)) {
      switch (line[0]) {
        case 'd':
        if(listStates[counter]!=line[3]){
          listStates.append(line,3,1);
          counter++;
        }
          nFunctions++;
        break;
        case '*':
        if(listStates[counter]!=line[3]){
          counter++;
        }
        accept = (char)(counter+47);
        break;
      }
    }
  }

  states = listStates.size();
  maquina.close();

  table = new Delta[nFunctions];

  ifstream maquina2(file);
  int counter2=0;
  if(maquina2.is_open()){
    while (getline(maquina2,line)) {
      switch (line[0]) {
        case 'd':
          table[counter2].setFunction(line);
          counter2++;
        break;
      }
    }
  }
  maquina2.close();

  ifstream c("cadena.txt");
  string aux;
  getline(c,aux);
  cadena.append("BBBB");
  cadena.append(aux);
  cadena.append("BBBBBBBBBBBBBBBBBBBBBBBBBB");
  c.close();
}

int MaquinaTuring::findDelta(char state,char symbol){

  for(int i = 0 ; i<nFunctions ; i++){
    if(table[i].getCurrentState() == state &&
       table[i].getCurrentSymbol() == symbol)
       return i;
  }
  return -1;
}

void MaquinaTuring::printTable(){
  cout <<endl;
  for(int i = 0 ; i < nFunctions ; i++)
    table[i].getFunction();
}
MaquinaTuring::~MaquinaTuring(){
  delete []table;
}
