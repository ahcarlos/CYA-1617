
/**
 * @file   transicion.hpp
 * @Author Carlos de armas Hernández (alu0100816167@ull.edu.es)
 * @date   October 2016
 * @brief  Clase transicion.
 * @param caracter_ almacena el caracter con el que transita el estado
 * @param soguiente_ nos indica cual es el estado al que se transita (el id)
 */



#pragma once
#include <iostream>
using namespace std;
class transicion_t
{
  private:
    char caracter_;
    int siguiente_;

  public:
  
    transicion_t(void);
    transicion_t(const transicion_t &cp);
    transicion_t(char caracter, int siguiente);
    ~transicion_t(void);
    
    char get_char(void);
    int get_siguiente(void);
    
    char get_char(void) const;
    int get_siguiente(void) const;
     void  set_transicion( char simb,  int siguiente);
    void mostrar(void);
    void mostrar(void) const;
    
    transicion_t& operator=(const transicion_t &x);
    int operator<(const transicion_t &x) const;
    
  private:
    
    friend ostream &operator<<(ostream &, const transicion_t &); 
}; 