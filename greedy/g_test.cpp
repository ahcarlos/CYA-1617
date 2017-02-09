#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>


using namespace std;

int buscar_mayor(int s, int n, const vector<int> cartera, int p)
{
    int v = -1;
    //n cantidad a cambiar
    //s guarda la suma de las monedas
    // i posicion del ultimo elemento devuelto
    // v para cuando no hay solucion se indica que es -1
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


void mostrar_soluciones(map<int,int> &cuantos)
{
  std::map<int,int>::reverse_iterator rit;
  cout << "Solución: {";
  for (rit=cuantos.rbegin(); rit!=cuantos.rend(); ++rit)
  {
      if(rit->first <= 50)
      {
          std::cout << rit->second << "x" <<  rit->first << "¢";
      }
      else
      {
        std::cout <<  rit->second<< "x" <<  (rit->first)/100 <<"€";
      }

      std::map<int,int>::reverse_iterator rit2= cuantos.rend();
      --rit2;
      if(rit != rit2)
        cout << ", ";

  }
  cout << "}";
  cout << endl;
}


void calcular_cambio(int n, vector<int> cartera)
{
  set<int> resultados;
  int suma=0;
  int pos=0;
  vector<int> cuantos;
  while(suma < n)
  {
    pos= buscar_mayor(suma, n, cartera, pos);

    if(pos ==-1)
    {
      cout << "No existe solución" << endl;
      break;
    }
    else{
      cuantos.push_back(cartera[pos]);
    }
    suma += cartera[pos];
  }

map<int, int> counts;
for (int j = 0; j < cuantos.size(); j++)
{
   std::map<int,int>::iterator i(counts.find(cuantos[j]));
   if (i != counts.end()){
      i->second++;
   } else {
      counts[cuantos[j]] = 1;
   }
}

  mostrar_soluciones(counts);

}



int main (void)
{
    //const vector <int> cartera = {200,100,50,20,10,5,2,1};
    const vector <int> cartera = {50000,20000,10000,5000,1000,500,200,100,50,20,10,5,2,1};
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
