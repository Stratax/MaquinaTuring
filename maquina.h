/********************************************************************
+   definición de las clases "Delta" y "MaquinaTuring"              *
+   Autor: López Calderón Adrián Aberto                             *
+   Escuela Superior de Cómputo (ESCOM-IPN)                         *
*********************************************************************/

#ifndef _MAQUINA_H_
#define _MAQUINA_H_

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Delta{

private:
  char currentState;
  char targetState;
  char currentSymbol;
  char targetSymbol;
  int movment; // 0:left 1:right
public:
  Delta();
  void setFunction(string chain);
  char getCurrentState(){return currentState;}
  char getTargetState(){return targetState;}
  char getCurrentSymbol(){return currentSymbol;}
  char getTargetStateSymbol(){return targetSymbol;}
  int getMovment(){return movment;}
  void printFunction();
};

class MaquinaTuring{
private:
  int states;
  int accept;
  Delta *table;
  int nFunctions;
public:
  MaquinaTuring();
  ~MaquinaTuring();
  Delta getDelta(int i){return table[i];}
};

#endif
