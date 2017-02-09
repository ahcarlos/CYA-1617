#include "regexp.hpp"

int main (void)
{
    string e ="a*";
    
    
    expreg_t A(e);
    A.calcular_simbolos();
   // A.matching();
   
}