/**
 * @file   estado.h
 * @Author Carlos de armas Hernández (alu0100816167@ull.edu.es)
 * @date   November 2016
 * @brief  Clase estado de la máquina de Turing (cada estdo es un nodo de lista).
 * @param next_ puntero al siguiente elemento
 * @param prev_ puntero a elemento previo.
 * @param transiciones_ vector de vectore que almacena las transiciones
 * @param ticket_ identificador del estado
 * @param accept_ indica si es de aceptacion o no
 * @param n_tuplas es la cantidad de tuplas, es decir, el número total de transiciones
 *
 */

#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

class estado{
    private:
    estado* next_;
    estado* prev_;
    vector<vector<char> > transiciones_;
    vector<int> next_q;
    int ticket_;
    bool accept_;
    int n_tuplas;
    public:
    estado(int i);
    ~estado(void);
    void set_ticket(int i); 
    int get_ticket(void);
    void set_accept(void);
    bool get_accept(void);
    int get_n_tuplas(void);
    void set_n_tuplas(int i);
    estado* get_next(void);
    void set_next(estado* e);
    estado* get_prev(void);
    void set_prev(estado* e);
    void set_tuplas(char a, char b, char x, int q);
    char get_item(int x,int y);
    int get_next_q(int x);
};