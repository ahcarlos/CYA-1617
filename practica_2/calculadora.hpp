#include <set>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <string.h>
#include <iterator>  



using namespace std; 

class calculadora_t
{
    private:
    
    set<string> L1_;
    set<string> L2_;
    
    public:
    
    calculadora_t(set<string> A, set<string> B);
    ~calculadora_t(void);
    
    
    void potencia(int n);
    void potencia(int n, set<string> A);
    set<string> potencia_(set<string> Set1, set<string> Set2);
    void inversa(set<string> A);
    void inversa(void);
    void concatenacion(void);
    void unions(void);
    void interseccion(void);
    void diferencia(void);
    bool sublenguajes(void);
    bool igualdad_lenguajes(void);
    
    void print(set <string> C);
    void cierre_kleene(void);
    
};