/**
 * @file   estado_t.hpp
 * @Author Carlos de armas Hernández (alu0100816167@ull.edu.es)
 * @date   October 2016 
 * @brief  Clase estado.
 * @param transiciones_ set que almacena las transiciones de cada estado
 * @param aceptacion_ variable bool que indica si un estado es de aceptacion o no
 * @param identificador_ identificador del estado
 * @param n_transiciones numero total de transiciones
 * 
 */

#pragma once
#include <set>
#include <iterator>
#include "transicion.hpp" 

class estado_t
{
  private:
    bool aceptacion_;
    int identificador_;
    set <transicion_t> transiciones_; 
    int ntransiciones_;
    
  public:
    estado_t(void);
    estado_t(const estado_t &);
   estado_t(bool aceptacion, int identificador, set<transicion_t> transiciones);
    ~estado_t(void);
  
    void mostrar(void);
    void mostrar(void) const;
    
    set <transicion_t> get_transiciones(void) const;
    
    int operator==(const estado_t& state) const; 
    int operator=(const estado_t& state);
    int operator<(const estado_t &x) const;
    
    int get_siguiente(char simbolo);
    bool aceptacion(void);
    bool aceptacion(void) const;
    
    bool estado_muerte(void);
    bool estado_muerte(void) const;

    int get_identificador(void);
    int get_identificador(void) const;
    
    void set_identificador(int n);
    int get_transicion(void);
    void set_transicion(int t);
    bool get_tipo_estado(void);
    void set_tipo_estado(bool acep);
    
    set<transicion_t> get_cjtotransicion(void);
    void insert_transicion(transicion_t transit);
  
  private:
    friend ostream &operator<<(ostream &, const estado_t &);
};