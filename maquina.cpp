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

void Delta::printFunction(){
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
    movment = 0;
}

MaquinaTuring::MaquinaTuring(){
  nFunctions=0;
  string line;
  ifstream maquina("test.txt");

  if(maquina.is_open()){
    while (getline(maquina,line)) {
      switch (line[0]) {
        case 'd':
          nFunctions++;
        break;
      }
    }
  }
  maquina.close();

  table = new Delta[nFunctions];

  ifstream maquina2("test.txt");
  int counter=0,statesCounter=0;


  if(maquina2.is_open()){
    while (getline(maquina2,line)) {
      switch (line[0]) {
        case 'd':

          table[counter].setFunction(line);
          counter++;
        break;
      }
    }
  }
  maquina2.close();
}

MaquinaTuring::~MaquinaTuring(){
  delete []table;
}
