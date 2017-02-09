#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#include "TuringMachine.h"

using namespace std;

int main (int argc, char *argv[]){
    
    
        int x;
        char file[80];
        char file2[80];
        strcpy(file,argv[1]);
        strcpy(file2,argv[2]);
        TuringMachine MT(file,file2);
        bool over=true;
    
        while(over){
        cout << endl;
        cout << "[1]. Mostrar MT" << endl;
        cout << "[2]. Mostrar Cinta"<< endl;
        cout << "[3]. Analizar Cinta"<<endl;
        cout << "[0]. Salir" <<endl;
        cout << "Introduzca opción >> ";
        cin >> x;
        
    
        switch (x){
            case 0: over=false;break;
            case 1: MT.mostrar();break;
            case 2: MT.mostrar_cinta();break;
            case 3: MT.analizar_cadena();break;
            default: break;
        }
        } 
 
    
}