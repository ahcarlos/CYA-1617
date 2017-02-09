#include <iostream>
#include <list>
#include <cmath>
#include <vector>


using namespace std;

int buscar_mayor(int s, int n, const vector<int> cartera, int p)
{
    int v = -1;
    //n cantidad a cambiar
    //s guarda la suma de las monedas
    // v posicion del ultimo elemento devuelto
    for(int i = p; i < cartera.size(); i++)
    {
        if( s + cartera[i] <= n)
        {
           
            //break;
	    return i;
        }
    }
    
    return v;
}
list<int> devolver_cambio(int n, const vector<int> cartera)
{
    list <int> Sols;
    int suma = 0;
    int pos = 0;
    
    while( suma < n )//&& solucion_encontrada= 0)
    {
        pos = buscar_mayor(suma,n,cartera,pos);
        if(pos == -1)
        {
            cout << "No hay solución" << endl;
            break;
        }
        else
        {
            //http://www.cplusplus.com/reference/list/list/?kw=list <-- metodos lista consulta
            Sols.push_back(cartera[pos]);
        }
        suma += cartera[pos];
    }
    return Sols;
}

void imprimir_sols(list <int> Sols)
{
    
    while(!Sols.empty())
    {
        if(Sols.front() <= 50)
        {
            cout << Sols.front() << "¢"; //alt+0162  
            Sols.pop_front();
        }
        else
        {
            cout << Sols.front() / 100 << "€" ;
            Sols.pop_front();   
        }
        if(Sols.size() != 0)
            cout << ",";
    }
    
    cout << endl;
}

int main (void)
{
    const vector <int> cartera = {50000,20000,10000,5000,1000,500,200,100,50,20,10,5,2,1};
    list<int> solucion;
    float cant;
    cout << "Introduzca la cantidad n:  ";
    cin >> cant;
    int n = (int) ceil(cant * 100);
    
    solucion = devolver_cambio(n, cartera);
    imprimir_sols(solucion);
}