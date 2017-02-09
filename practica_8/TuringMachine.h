/**
 * @file   TuringMachine.h
 * @Author Carlos de armas Hernández (alu0100816167@ull.edu.es)
 * @date   November 2016
 * @brief  Clase Máquina de Turing que simula el comportamiento de la máquina de Turing.
 * @param c es la cinta de la máquina.
 * @param cabezal donde está apuntando la cinta.
 * @param inicio_ es el estado de arranque de la máquina.
 * @param fin_ es el estado final de la máquina.
 * @param n_estados almacena la cantidad de estados que tiene la máquina.
 * @param t_uplas almacena la cantidad de transiciones que tiene la máquina.
*/





#pragma once

#include "cinta_t.h"
#include "estado.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

class TuringMachine{
    private:
    cinta_t c;
    int cabezal;
    estado* inicio_;
    estado* fin_;
    int n_estados;
    int t_uplas;
    public:
    TuringMachine(char textfile[],char textfile2[]);
    ~TuringMachine(void);
    int get_cabezal(void);
    void set_cabezal(int i);
    void insertar_inicio(estado* e);
    void insertar_fin(estado* e);
    estado* extraer_inicio(void);
    estado* extraer_fin(void);
    bool empty(void);
    int get_sz(void);
    void set_sz(int i);
    void mostrar(void);
    int devolver_arranque(void);
    estado* apuntar_destino(int i);
    bool analizar_cadena(void);
    void mostrar_cinta(void);
};