#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <chrono> //para medir el tiempo de ejecución en cada ejecución, no tiene que dar siempre lo mismo

using namespace std;
using namespace std::chrono;

void fusionar(vector<int>& sec,vector<int> U,vector<int> V, bool verbose)
{
    int i = 0;
    int j = 0;

    if(verbose)
    {
        cout << "Comparando => ";
        cout << "U: ";
        for(int m = 0; m < U.size(); m++)
            cout << U[m] << " ";
        cout << " con V: ";
        for(int m = 0; m < V.size(); m++)
            cout << V[m] << " ";

        cout << endl;
    }

    for(int k = 0; k < sec.size(); k++)
    {
        if((i < U.size()) && (j < V.size()))
        {
            if(U[i] < V[j])
            {
	            sec[k] = U[i];
	            i++;

            }
            else
            {
	            sec[k] = V[j];
	            j++;

            }
        }
        else
        {
            if(i >= U.size())
            {
        	    sec[k] = V[j];
	            j++;
            }
            else
            {
	            if(j >= V.size())
	            {
	                sec[k] = U[i];
	                i++;
	            }
            }
        }
    }

    if(verbose)
    {
        cout << "Sub-secuencia: ";
        for(int m = 0; m < sec.size(); m++)
            cout << sec[m] << " ";

        cout << endl;
    }

}

//VERSIÓN RECURSIVA DEL MERGESORT
void ordenarPorFusionRecursivo(vector<int>& sec, bool verbose)
{
    if(sec.size() > 1)
    {
        vector<int> U(sec.begin(),(sec.begin()+sec.size()/2));
        vector<int> V((sec.begin()+sec.size()/2), sec.end());

        ordenarPorFusionRecursivo(U, verbose);
        ordenarPorFusionRecursivo(V, verbose);
        fusionar(sec,U,V,verbose);
    }
}

// Funcion que nos permite saber el mínimo entre dos enteros
int min(int x, int y) { return (x<y)? x :y; }


//Funcion para mezclar dos mitades: arr[l..m] y arr[m+1..r] del <vector>arr
void fusion2(vector<int>& arr, int l, int m, int r, bool verbose)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    //L[n1], R[n2] son arrays temporales
    int L[n1], R[n2];

    //Se copian los datos a los arrays temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    //Para ver el contenido de los vectores temporales (como se parten) == true
    if(verbose)
    {
        cout << "Comparando => ";
        cout << "L: ";
        for(int m = 0; m < n1; m++)
            cout << L[m] << " ";
        cout << " con R: ";
        for(int m = 0; m < n2; m++)
            cout << R[m] << " ";

        cout << endl;
    }
    



    //Fusiona/mezcla los arrays temporales otra vez en arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //Si los hay, copia los elementos restantes de L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    //Si los hay, copia los elementos restantes de R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }


    //Si verbose == true se ven las Sub-secuencias de cada etapa
    if(verbose)
    {
        cout << "Sub-secuencia: ";
        for (std::vector<int>::iterator it = arr.begin() ; it != arr.end(); ++it)
          cout << *it << " ";

        cout << endl;
    }


}


  void ordenarPorFusionIterativo(vector<int>& arr, int n, bool verbose)
  {
      int curr_size;  // For current size of subarrays to be merged
                     // curr_size varies from 1 to n/2
      int left_start; // For picking starting index of left subarray
                     // to be merged

      // Merge subarrays in bottom up manner.  First merge subarrays of
      // size 1 to create sorted subarrays of size 2, then merge subarrays
      // of size 2 to create sorted subarrays of size 4, and so on.
      for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
      {
         // Pick starting point of different subarrays of current size
         for (left_start=0; left_start<n-1; left_start += 2*curr_size)
         {
             // Find ending point of left subarray. mid+1 is starting
             // point of right
             int mid = left_start + curr_size - 1;

             int right_end = min(left_start + 2*curr_size - 1, n-1);

             // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
             fusion2(arr, left_start, mid, right_end,verbose);
         }
      }
  }


int main(void)
{
  int op = -1;
  int n = 0;
  bool verbose= false;
  char activarVerbose;

  srand(time(NULL));

  while (n <= 0) {
    cout << "Introduzca el tamaño de la secuencia >> ";
    cin >> n;
  }


  vector<int> Demostracion(n,0);
  for(int i = 0; i < n ; i++)
  {
      Demostracion[i] = rand() % 3000+5000;
      //Demostracion[i] = rand() % 30000000+50000000;
  }

  cout << "--------- Algoritmos: ---------" << endl;
  cout << "[1]. Ordenar por Fusión Recursivo" << endl;
  cout << "[2]. Ordenar por Fusión Iterativo" << endl;
  cout << "Introduzca opción por teclado >> ";
  cin >> op;

  cout << "El parámetro 'verbose' muestra información extra. ¿Activar? (y/n)." << endl;
  cout << "--> ";
  cin >> activarVerbose;
  cout << endl;

  if( activarVerbose == 'y')
   verbose= true;
  else
    verbose= false;


  cout << "Secuencia inicial (sin ordenar): ";
  for(int k = 0; k < Demostracion.size(); k++)
      cout << Demostracion[k] << " ";

  cout << endl;
  cout << endl;


  switch(op)
  {
      case 1:
      {
        ordenarPorFusionRecursivo(Demostracion,verbose);
      }
      break;

      case 2:
      {
        ordenarPorFusionIterativo(Demostracion,n,verbose);
      }
      break;

      default: cout << "La opción introducida no está soportada.";
      break;
  }


  cout << endl;
  cout << "Secuencia final (ordenada): ";
  for(int i = 0; i < Demostracion.size(); i++)
      cout << Demostracion[i] << " ";

    cout << endl;
    cout << endl;

    auto tiempo_ini_recursivo = std::chrono::high_resolution_clock::now();
    ordenarPorFusionRecursivo(Demostracion,false);
    auto tiempo_fin_recursivo = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_recursivo = tiempo_fin_recursivo - tiempo_ini_recursivo;
    std::cout << "El método recursivo tardó => " << duration_recursivo.count() << "ms" << endl;

    auto tiempo_ini_iterativo = std::chrono::high_resolution_clock::now();
    ordenarPorFusionIterativo(Demostracion,n,false);
    auto tiempo_fin_iterativo = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_iterativo = tiempo_fin_iterativo - tiempo_ini_iterativo;
    cout << "El método iterativo tardó => " << duration_iterativo.count() << "ms" << endl;

  cout << endl;
  cout << endl;

  return 0;
}
