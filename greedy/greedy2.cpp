#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <unordered_map>


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


void mostrar_soluciones(vector<int> cantidades, set<int> res)
{
  int inicio=0;
  for (std::set<int>::reverse_iterator rit=res.rbegin(); rit != res.rend(); ++rit)
  {
      if((*rit) <= 50)
      {
        int aux_= (*rit);
        cout << cantidades.at(inicio) <<"x" << (*rit) <<"¢";
        inicio++;
      }
      else
      {
        int aux = (*rit);
        cout << cantidades.at(inicio) <<"x" << aux/100 <<"€";
        inicio++;
      }
      if(*rit != res.size())
        cout << ",";

  }
  cout << endl;
}


void calcular_cambio(int n, vector<int> cartera)
{
  set<int> resultados;
  int suma=0;
  int pos=0;
  int cantidad=0;
  vector<int> cuantos;
  int i=0;
  while(suma < n)
  {
    pos= buscar_mayor(suma, n, cartera, pos);

    if(pos ==-1)
    {
      cout << "No existe solución" << endl;
      break;
    }
    else{

      resultados.insert(cartera[pos]);
      cuantos.push_back(cartera[pos]);

    }
    suma += cartera[pos];
  }



typedef std::unordered_map<int, int> CounterMap;
CounterMap counts;
for (int j = 0; j < cuantos.size(); j++)
{
   CounterMap::iterator i(counts.find(cuantos[j]));
   if (i != counts.end()){
      i->second++;
   } else {
      counts[cuantos[j]] = 1;
   }
}
for (std::unordered_map<int,int>::iterator it=counts.begin(); it!=counts.end(); ++it)
  std::cout << it->first << " => " << it->second << '\n';
  //mostrar_soluciones( CounterMap cuantos, resultados);

}



int main (void)
{
    const vector <int> cartera = {200,100,50,20,10,5,2,1};
    //const vector <int> cartera = {50000,20000,10000,5000,1000,500,200,100,50,20,10,5,2,1};
    //list<int> solucion;
    //set<int> result;
    //vector<int> numeros;
    float cant;
    cout << "Introduzca la cantidad n:  ";
    cin >> cant;
    int n = (int) ceil(cant * 100);
     //cout << " A ver que hace en el cout: " << n;
     cout << endl;

    calcular_cambio(n, cartera);
    cout << endl;

}
