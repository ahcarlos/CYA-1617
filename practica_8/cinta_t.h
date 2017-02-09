/**
 * @file   cinta_t.h
 * @Author Carlos de armas Hernández (alu0100816167@ull.edu.es)
 * @date   November 2016
 * @brief  Clase cinta de la máquina de Turing.
 * @param cinta donde se almacenarán los símbolos de la cinta.
 * @param sz_ es el tamaño de la cinta
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

class cinta_t{
    private:
    char* cinta;
    int sz_;
    public:
    cinta_t(char textfile[]);
    ~cinta_t(void);
    char get_data(int i);
    void set_data(int i, char x);
    void mostrar(int interrupcion,int muestra);
};