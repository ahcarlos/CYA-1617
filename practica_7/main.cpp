#include "CFG.hpp"

using namespace std;

int main (int argc, char* argv[]) {

  char* fichero_entrada = argv[1];
  char* fichero_salida = argv[2];
  
  if((fichero_entrada!=NULL) && (fichero_salida!=NULL)) {
    
    Gramatica A(fichero_entrada);
    A.primeraEtapa();
    A.segundaEtapa();
    A.exportar(fichero_salida);
    cout << "Fichero exportado con éxito" << endl;
  }
  else {
    cout << "Este programa implementa la función de línea de comandos, por favor vuelva a ejecutar con el siguiente formato: " << endl;
    cout << "./CFG nombre_fichero.cfg nombre_fichero.cfg" << endl;
  }

}