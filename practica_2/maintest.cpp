#include <iostream> 
#include <string>
#include <vector>
#include <stdlib.h>
#include "regexp.hpp"

#include "calculadora.hpp"


using namespace std;

int main(void)
{
    int eleccion;
    int tam_l1; //tamaño lenguaje 1
    int tam_l2; //tamaño lenguaje 2
    int reg_o_l;
    
    string aux;
    set<string> Len1;
    set<string> Len2;
    
    string regexp1;
    string regexp2;
    
    cout << endl;
    cout << "\tIndique si va a trabajar con lenguajes[1] o expresiones regulares[2] >> ";
    cin >> reg_o_l;
    cout << endl;
    
    if(reg_o_l == 2)
    {
        cout << "Escriba la primera expresion regular >>  ";
        cin >> regexp1;
        cout << endl;
        
        cout << "Escriba la segunda expresion regular >>  ";
        cin >> regexp2;
        
        cout << endl;
        
        expreg_t REGEX1_(regexp1); //instanciamos las expresiones regular en la clase
        expreg_t REGEX2_(regexp2);
        
        REGEX1_.calcular_simbolos();
        REGEX1_.matching();
        
        REGEX2_.calcular_simbolos();
        REGEX2_.matching();
        
        Len1 = REGEX1_.get_validas();
        Len2 = REGEX2_.get_validas();
        
        
        cout << endl << "Len1= {";
		int comas=0;
		for (set<string>::iterator it = Len1.begin(); it != Len1.end(); it++)
	    {
		    cout << (*it);
			if (comas != Len1.size()-1)
			{
				cout << "," ; 
			}
			comas++;
		}
		cout << "}" << endl;
		
		cout << endl << "Len2= {";
		comas=0;
		for (set<string>::iterator it = Len2.begin(); it != Len2.end(); it++)
	    {
		    cout << (*it);
			if (comas != Len2.size()-1)
			{
				cout << "," ; 
			}
			comas++;
		}
		cout << "}" << endl;
    }
    else
    {
         do
      {  
      
        	cout << "\t %%%%%%%%%%%%%%%%%%%% CALCULADORA DE LENGUAJES FINITOS %%%%%%%%%%%%%%%%%%%%" << endl;
        cout << endl;
        cout << "1. Calcular potencia del lenguaje" << endl;
        cout << "2. Calcular la inversa del lenguaje" << endl;
        cout << "3. Calcular concatenacion de L1 y L2" << endl;
        cout << "4. Calcular la union de L1 y L2" << endl;
        cout << "5. Calcular la interseccion de L1 y L2" << endl;
        cout << "6. Calcular la diferencia de lenguajes L1 y L2" << endl;
        cout << "7. Calcular sublenguajes" << endl;
        cout << "8. Comprobar igualdad de lenguajes" << endl;
        cout << "9. Cierre de Kleene" << endl;
        cout << "10. Salir del programa" << endl;
        cout << endl;
        cout << "\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    
        cout << ">>> Introduzca el numero del menu:  ";
        cin >> eleccion;
    
        
    
        if( (eleccion == 1) || (eleccion == 2))
        {
            if(eleccion== 1)
            cout << "Introduzca el numero de cadenas para hacer la potencia:  ";
        
            if(eleccion == 2)
            cout << "Introduzca el numero de cadenas para hacer la inversa:  ";
        
            cin >> tam_l1;
        
        
            for(int i= 0; i< tam_l1; i++)
            {
                cout << "Introduzca la cadena: " << i+1 << endl;
                cin >> aux;
                Len1.insert(aux);
            
            }
            
            cout << endl << "L1= {";
            int coma=0;
		    for (set<string>::iterator it = Len1.begin(); it != Len1.end(); it++)
		    {
			    cout << (*it);
			    if(coma !=(tam_l1-1)) {cout <<",";}
			    
				coma++; 		
		    }
		    cout << "}" << endl;
            
        }
    
        else if((eleccion >= 3) || (eleccion <= 8))
        {
            cout << "Introduzca el numero de cadenas del lenguaje L1"<< endl;
            cin >> tam_l1;
        
            for(int i=0; i< tam_l1; i++)
            {
                cout << "Introduzca la cadena: " << i+1 << endl;
                cin >> aux;
                Len1.insert(aux);
            }
        
            cout << endl << "L1= {";
            int coma1=0;
		    for (set<string>::iterator it = Len1.begin(); it != Len1.end(); it++)
		    {
			    cout << (*it);
			    if( coma1 !=(tam_l1-1)) {cout <<",";}
			    
				coma1++; 		
		    }
		    cout << "}" << endl;
        
        
            cout << "Introduzca el numero de cadenas del lenguaje L2" << endl;
            cin >> tam_l2;
        
            for(int i=0; i< tam_l2; i++)
            {
                cout << "Introduzca la cadena: " << i+1 << endl;
                cin >> aux;
                Len2.insert(aux);
            }
        
            cout << endl << "L2= {";
            int coma2=0;
		    for (set<string>::iterator it = Len2.begin(); it != Len2.end(); it++)
		    {
			    cout << (*it);
			    if(coma2 !=(tam_l2-1)) {cout <<",";}
			    
				coma2++; 		
		    }
		    cout << "}" << endl;
        }
       
		    calculadora_t CLF(Len1, Len2);
		  
		    switch(eleccion)
		    {
		        case 1:
		            int n;
		            cout <<"Indique la potencia n-esima:  ";
		            cin >> n;
		            cout << endl;
		            CLF.potencia(n);
		        break;
		        
		        case 2:
		             CLF.inversa();
		        break;
		        
		        case 3:
		            CLF.concatenacion();
		        break;
		        
		        case 4:
		            CLF.unions();
		        break;
		        
		        case 5:
		            CLF.interseccion();
		        break;
		        
		        case 6:
		            CLF.diferencia();
		        break;
		            
		        case 7:
		            if(CLF.sublenguajes())
		            {
		                cout << "L2 es sublenguaje de L1" << endl;
		            }
		            else
		            {
		                cout << "L2 no es sublenguaje de L1" << endl;
		            }
		        break;
		        
		        case 8:
		            if(CLF.igualdad_lenguajes())
		            {
		                cout << "Los Lenguajes L1 y L2 son iguales" << endl;
		            }
		            else
		            {
		                cout << "Los Lenguajes L1 y L2  no son iguales" << endl;
		            }
		        break;
		        
		        case 9:
		        	CLF.cierre_kleene();
		        break;
		        
		        default: 
				cout << "Opción no soportada." << endl;
				break;
		        
		       
		             
		            
		    }
      }
      
      while(eleccion != 10);
    }
}