#include "dfa.hpp"
using namespace std;

int main (void)
{
  dfa_t DFA;
  dfa_t DFA_MIN;
  DFA.leer_dfa();
  
  int opcion;
  do
  {
    cout << "\t----------MENU----------" << endl;
    cout <<endl;
    cout << "1 Leer DFA" << endl;
    cout << "2 Mostrar DFA." << endl;
    cout << "3 Mostrar estados de muerte." << endl;
    cout << "4 Analizar cadena." << endl;
    cout << "5 Minimizar DFA" << endl;
    cout << "6 Exportar el DFA mínimo" << endl;
    cout << "7 Salir."<< endl;
    cout << "Introduzca una opción: ";
    cin >> opcion;

    switch(opcion)
    {
      case 1:
        DFA.leer_dfa();
      break;
      case 2:
        DFA.mostrar_dfa();
        break;
      case 3:
        DFA.estados_de_muerte();
        break;
      case 4:
        DFA.analizar_cadena();
        break;;
      case 5: DFA.minimizar_dfa(DFA_MIN); 
        break;
      case 6:
              DFA_MIN.exportar_dfa();
      break;
      case 7: 
      return 0;
      break; 
      default:
        cout << "Opción incorrecta." <<endl;
        break;
    }
  }while(opcion!=7);
} 