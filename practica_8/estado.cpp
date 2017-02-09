#include "estado.h"

estado::estado(int i):
next_(NULL),
prev_(NULL),
ticket_(i),
accept_(false),
n_tuplas(0)
{}

estado::~estado(void){
}
  
  
void estado::set_ticket(int i){
    ticket_=i;
}  

int estado::get_ticket(void){
    return ticket_;
}

void estado::set_accept(void){
    accept_=true;
}

bool estado::get_accept(void){
    return accept_;
}

int estado::get_n_tuplas(void){
    return n_tuplas;
}

void estado::set_n_tuplas(int i){
    n_tuplas=i;
}

estado* estado::get_next(void){
    return next_;
}

void estado::set_next(estado* e){
    next_=e;
}

estado* estado::get_prev(void){
    return prev_;
}

void estado::set_prev(estado* e){
    prev_=e;
}

void estado::set_tuplas(char a,char b, char x, int q){
    vector<char> stiches;
    stiches.push_back(a);
    stiches.push_back(b);
    stiches.push_back(x);
    next_q.push_back(q);
    transiciones_.push_back(stiches);
}

char estado::get_item(int x,int y){
    return transiciones_[x][y];
}

int estado::get_next_q(int x){
    return next_q[x];
}
