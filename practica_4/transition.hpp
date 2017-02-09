
/**
 * @file   transition.hpp
 * @Author Carlos de armas Hernández (alu0100816167@ull.edu.es)
 * @date   October 2016
 * @brief  Clase transicion.
 * @param caracter_ almacena el caracter con el que transita el estado
 * @param next_state_ nos indica cual es el estado al que se transita (el id)
 */




#pragma once
#include <iostream>
using namespace std;
class transition_state_t
{
  private:
    char caracter_;
    int next_state_;

  public:
    transition_state_t(void);
    transition_state_t(const transition_state_t &cp);

    transition_state_t(char caracter, int next_state);
    ~transition_state_t(void);
    
    bool reconocido(char x);
    bool reconocido(char x) const;
    
    char get_char(void);
    char get_char(void) const;

    int get_next_state(void);
    int get_next_state(void) const;
    
    void mostrar(void);
    void mostrar(void) const;
    
    transition_state_t& operator=(const transition_state_t &x);
    int operator<(const transition_state_t &x) const;
  private:
    friend ostream &operator<<(ostream &, const transition_state_t &);
};

