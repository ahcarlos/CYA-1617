#include "regexp.hpp"




expreg_t::expreg_t(string e):
P_(e),
E_(e) 
{}

expreg_t::~expreg_t(void)
{}




void expreg_t::print(set <string> C)
{
        cout <<" {";
        int iaux=0;
	    for (set<string>::iterator i = C.begin(); i != C.end(); i++)
	    {
	        cout << (*i);
	        
	        if (iaux != C.size()-1)
            {
                    cout << "," ; 
            }
            iaux++;
	    }
	   cout << "}" << endl << endl;
}



void expreg_t::calcular_simbolos(void){

    for(std::string::iterator it = P_.begin(); it != P_.end(); ++it) {
        if(isalpha(*it) != 0)
        {
            string aux(1,(*it));
            cadenas.insert(aux);
        }
    }
    
    
    set<string> flag;
    for(set<string>::iterator i = cadenas.begin(); i != cadenas.end(); i++)
    {
        
        for(set<string>::iterator j = cadenas.begin(); j != cadenas.end(); j++)
        {
            string aux1 = (*i);
            string aux2 = (*j);
            string aux3 = aux1+aux2;
        
            flag.insert(aux3);
            
        }
    }
    
    set<string> flag2;
    for(set<string>::iterator z = flag.begin(); z != flag.end(); z++)
    {
        for(set<string>::iterator x = cadenas.begin(); x != cadenas.end(); x++)
        {
            string aux1 = (*z);
             
            string aux2 = (*x);
            
            string aux4 = aux1+aux2; 
            
           
            
            flag2.insert(aux4);
            
        }
    }
    
    cadenas.insert(flag.begin(),flag.end());
    cadenas.insert(flag2.begin(),flag2.end());
    //print(cadenas);
    
}


void expreg_t::matching(void)
{
    
   
    for(set<string>::iterator i = cadenas.begin(); i != cadenas.end(); i++)
    {
        if(regex_match ((*i), E_))
        {
            cadenas_validas.insert((*i)); 
        }
    }
}



bool expreg_t::kleene_closure(void)
{
    bool valor;
    for (int i = 0; i < P_.size(); i++)
    {
       if(P_[i] == '*')
       {
          valor = true;
       }
       else
       {
           valor = false;
       }
    }
    return valor;
}


set<string> expreg_t::get_validas(void)
{
    if(kleene_closure())
    {
        string cad_vac = "&";
        cadenas_validas.insert(cad_vac);
    }
    return cadenas_validas;
}