#pragma once
#include <set>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <string.h>
#include <iterator>  
#include <regex>
#include <cctype>


using namespace std; 
using namespace std::regex_constants;  

class expreg_t
{
    private:
    
        regex       E_; // Aqui copias la regexp para hacer el matching
        string      P_; //Aqui almacenas al regexp en forma de string para parsear los simbolos
        set<string> cadenas; //Aqui almacenas todas las cadenas formadas por los símbolos del lemguaje.
        set<string> cadenas_validas; //Aqui se almacenan las cadenas que forman parte del lenguaje reconocido por la expresión regular
    
    public:
    
        expreg_t(string e); //Copias la cadena de entrada en la expresion regular E_ y en la string P_
        ~expreg_t(void);
        void calcular_simbolos(void); //Aqui parseas los simbolos de la regexp y formas varias cadenas con esos simbolos.
        void matching(void); //Aqui haces match de la regexp con las cadenas que generaste arriba
        void print(set <string> C);
        set<string> get_validas(void);
        
        bool kleene_closure(void);
};

