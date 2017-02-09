/*
#include "calculadora.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
using namespace std;


int main(void)
{
	
    int eleccion;
    
    int tam_l1;
    int tam_l2;
    
    string aux;
	vector<string> Len1;
	vector<string> Len2;
    
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
        cout << "9. Salir del programa" << endl;
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
                Len1.push_back(aux);
            
            }
            
            cout << endl << "L1= {";
		    for( int i=0; i<tam_l1; i++)
		    {
			    cout << Len1[i];
			    if(i!=(tam_l1-1))
			    cout <<",";
				 		
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
                Len1.push_back(aux);
            }
        
            cout << endl << "L1= {";
		    for( int i=0; i<tam_l1; i++)
		    {
			    cout << Len1[i];
			    if(i!=(tam_l1-1))
			    cout <<",";
				 		
		    }
		    cout << "}" << endl;
        
        
            cout << "Introduzca el numero de cadenas del lenguaje L2" << endl;
            cin >> tam_l2;
        
            for(int i=0; i< tam_l2; i++)
            {
                cout << "Introduzca la cadena: " << i+1 << endl;
                cin >> aux;
                Len2.push_back(aux);
            }
        
            cout << endl << "L2= {";
		    for( int i=0; i<tam_l2; i++)
	    	{
			    cout << Len2[i];
			    if(i!=(tam_l2-1))
			    cout <<",";
				 		
		    }
		    cout << "}" << endl;
        }
       
		    calculadora_t CLF(Len1, tam_l1, Len2, tam_l2);
		  
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
		        
		        //case 9:
		        	//cout << "Ha finalizado el programa.";
		        	//exit(0);
		        //break;
		        
		       
		             
		            
		    }
      }
      
      while(eleccion != 9);
} 
*/


#include <iostream> 
#include <string>
#include <vector>
#include <stdlib.h>
#include "regexp.hpp"

#include "calculadora.hpp"


using namespace std; 

int main(void)
{
	int opcion = 9; 
	
	int A; //tamaño lenguaje A
	int B; //tamaño lenguaje B
	
	string aux;
	set<string> L1;
	set<string> L2;
	int a;
	string reg1;
	string reg2;
	
	cout << "¿Va a operar con expresiones regulares? 0-No 1-Sí: ";
	cin >> a;
	
	if(a==1)
	{
		cout << "Introduzca la primera regexp: ";
		cin >> reg1;
		cout << "Introduzca la segunda regexp: ";
		cin >> reg2;
		
		expreg_t A(reg1);
		expreg_t B (reg2);
		A.calcular_simbolos();
    	A.matching();
		B.calcular_simbolos();
    	B.matching();
    	
    	L1 = A.get_validas();
    	L2 = B.get_validas();
    	
    	cout << endl << "L1= {";
		int iaux=0;
		for (set<string>::iterator i = L1.begin(); i != L1.end(); i++)
	    {
		cout << (*i);
			if (iaux != L1.size()-1)
			{
				cout << "," ; 
			}
			iaux++;
		}
		cout << "}" << endl;
		
		cout << endl << "L2= {";
		iaux=0;
		for (set<string>::iterator i = L2.begin(); i != L2.end(); i++)
	    {
		cout << (*i);
			if (iaux != L2.size()-1)
			{
				cout << "," ; 
			}
			iaux++;
		}
		cout << "}" << endl;
	}
	else
	{
		cout << "Introduzca el numero de cadenas del L1" << endl;
			
				cin >> A;
				
				for( int i=0; i<A; i++)
				{
					cout << "Introduzca la cadena: " << i+1 << endl;
				 	cin >> aux;
				 	L1.insert(aux);	
				}
				
				cout << endl << "L1= {";
				int iaux=0;
				for (set<string>::iterator i = L1.begin(); i != L1.end(); i++)
	    		{
		        	cout << (*i);
		        
		        	if (iaux != L1.size()-1)
	            	{
	                    cout << "," ; 
	            	}
	            	iaux++;
	    		}
				cout << "}" << endl;
				
		cout << endl << "Introduzca el numero de cadenas del L2" << endl;
			
				cin >> B;
				
				for( int i=0; i<B; i++)
				{
					cout << "Introduzca la cadena: " << i+1 << endl;
				 	cin >> aux;
				 	L2.insert(aux);	
				}
				
				cout << endl << "L2 = {";
				iaux=0;
				for (set<string>::iterator i = L2.begin(); i != L2.end(); i++)
	    		{
		        	cout << (*i);
		        
		        	if (iaux != L2.size()-1)
	            	{
	                    cout << "," ; 
	            	}
	            	iaux++;
	    		}
				cout << "}" << endl;
				cout << endl;
	}

	
				
				
				calculadora_t S(L1,L2);
	
	    while(opcion != 0) {    
		
			cout << "---- Calculadora de lenguajes finitos -----	" << endl;
			cout << "1. Calcular la potencia n del lenguaje L1 o L2" << endl; 
			cout << "2· Calcular la inversa del lenguaje L1 o L2" << endl; 
			cout << "3· Calcular la concatenación de L1 y L2" << endl; 
			cout << "4· Calcular la unión de L1 y L2" << endl; 
			cout << "5· Calcular la intersección de L1 y L2" << endl; 
			cout << "6· Calcular la diferencia de L1 y L2" << endl; 
			cout << "7· Calcular los sublenguajes de L1 y L2" << endl;
			cout << "8· Calcular si L1 y L2 son iguales" << endl; 
			cout << "0. Para salir del programa " << endl; 
			cout << "----- Introduce la accion a ejecutar ----- "<<endl;
			cin >> opcion;
			cout << endl; 

			
			switch (opcion) 
			{
				case 0:
					cout << "Saliendo del programa..." << endl;
					exit(0);
				break;
				case 1: 
					int n;
					int m;
					cout << "Elija con que lenguaje desea operar [1 o 2] " << endl;
					cin >> m;
					if(m == 1){
						cout << "Introduzca la potencia a calcular: ";
						cin >> n;
						cout << endl;
						//S.potencia(n,1);
						S.potencia(n);
					}
					/*if(m == 2){
						cout << "Introduzca la potencia a calcular: ";
						cin >> n;
						cout << endl;
						S.potencia(n,2);
					}
					*/
				break;
				
				case 2:
					int x;
					cout << "Elija con que lenguaje desea operar [1 o 2] " << endl;
					cin >> x;
					if(x == 1){
						cout << endl; 
						S.inversa();
					}
					/*
					if(x == 2){
						cout << endl;
						S.inversa(2);
					}
					*/
				break;	
				
				case 3: 
					S.concatenacion();
				break; 
				
				case 4: 
					S.unions();
				break;
				
				case 5: 
					S.interseccion();
				break;
				case 6: 
					S.diferencia();
				break;
				case 7: 
					if(S.sublenguajes())
					{
						cout << "L2 es sublenguaje de L1" << endl;
					}
					else
					{
						cout << "L2 no es sublenguaje de L1" << endl;
					}
				break;
				case 8: 
					if(S.igualdad_lenguajes())
					{
						cout << "Los Lenguajes L1 y L2 son iguales" << endl;
					}
					else
					{
						cout << "Los Lenguajes L1 y L2  no son iguales" << endl;
					}
				break;
				case 9:
					 S.cierre_kleene();
				break;
				default: 
				cout << "opción incorrecta" << endl;
				break;

              }
				
			}
			
       }


