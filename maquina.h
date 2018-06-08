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
  int movment; // -1:left 1:right
public:
  Delta();
  void setFunction(string chain);
  char getCurrentState(){return currentState;}
  char getTargetState(){return targetState;}
  char getCurrentSymbol(){return currentSymbol;}
  char getTargetSymbol(){return targetSymbol;}
  int getMovment(){return movment;}
  void getFunction();
};

class MaquinaTuring{
private:
  int states;
  char accept;
  Delta *table;
  int nFunctions;
  string cadena="";


public:
  MaquinaTuring(string file);
  ~MaquinaTuring();
  Delta getDelta(int i){return table[i];}
  int findDelta(char state, char symbol);
  int getStates(){return states;}
  char getAccept(){return accept;}
  string getCadena(){return cadena;}
  void setCadena(string c){cadena = c;}

  //Funciones Auxiliares///
  void printTable();
};

#endif
