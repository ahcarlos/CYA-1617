#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
#include "state.hpp"



/**
 * @file   NFA.hpp
 * @Author Carlos de armas Hernández (alu0100816167@ull.edu.es)
 * @date   October 2106
 * @brief  Clase NFA.
 * @param estados_ es un set para almacenar el conjunto de estados del NFA
 * @param estado_inicial_ variable para guardar el estado de partida (inicial)
 * @param alfabeto_ set para almacenar los simbolos del alfabeto
 */

#pragma once
#include <set>
#include <iterator>
#include <vector>
#include <iostream>


using namespace std;
class NFA_t
{
  private:
    set <state_t> estados_;
    state_t estado_inicial_;
    //bool dfa;
    set <char> alfabeto_; //alamcenar los simbolos del alfabeto
  public:
    NFA_t(void);
    ~NFA_t(void);
    
    void analizar_cadena_recursivo(int &n, char cadena [], int i, const stringbuf &buffer, const ostream &os, state_t estado, bool &baux);
    
    int get_n_estados(void);
    int get_n_estados(void) const;
    
    state_t get_inicial(void);
    state_t get_inicial(void) const;
    
    set<state_t> get_estados(void) const;
    
    bool es_dfa(void);
    
    
    void mostrar_estados_muerte(void);
    bool leer_fichero(void);
    void mostrar(void);
    void analizar_cadena(void);
    state_t get_state(const int x);
    
  private:
    friend ostream &operator<<(ostream &, const NFA_t &);
};