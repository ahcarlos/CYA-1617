/**
 * @file   CFG.hpp
 * @Author Carlos de armas Hernández (alu0100816167@ull.edu.es)
 * @date   November 2106
 * @brief  Clase CFG (Context Free Grammar).
 * @param terminales es el numero de simbolos terminales
 * @param noTerminales numero de simbolos no terminales
 * @param sTerminales es un set que almacena los simbolos terminales
 * @param snoTerminales set para almacenar los simbolos no terminales
 * @param producciones vector de pares (clave-valor) que almacena las producciones
 * @param tamProducciones almacena el numero de producciones para cada simbolo no terminal
 */


#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

class Gramatica {

    private:
    
        int terminales;
        int noTerminales;
        set<char> sTerminales;
        set<char> snoTerminales;
        vector <pair <char,string> > producciones;
        vector <pair <char, int> > tamProducciones;
        
    public:
        
        Gramatica(char* entrada);
        
        void exportar(char* salida);
        
        void primeraEtapa(void);
        void segundaEtapa(void);
        
        void imprimirSet(set <char> C);
        void imprimirVector(vector <pair <char,string> > C);

};