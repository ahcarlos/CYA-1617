#include "CFG.hpp"

Gramatica::Gramatica(char* entrada)
{
    ifstream fichero;
    fichero.open(entrada);
    
    if (fichero.is_open()) {
                
        fichero >> (int &) terminales;
        
        for(int i = 0; i<terminales; i++) {
            char aux;
            fichero >> (char &) aux;
            sTerminales.insert(aux);
        }
        
        fichero >> (int &) noTerminales;
        
        for(int i = 0; i<noTerminales; i++) {
            char aux;
            fichero >> (char &) aux;
            snoTerminales.insert(aux);
        }
        
        
        for(int i = 0; i<noTerminales; i++) {
            
            char notermi;
            int contador = 0;
            string flecha;
            string line;
            
            fichero >> (char &) notermi;
            fichero >> flecha;
            getline (fichero,line);

            char *cadena = strdup(line.c_str());
            char *subcadena = strtok (cadena," | ");
            
            while (subcadena != NULL) {
                
                string prod(subcadena);
                producciones.push_back(make_pair(notermi,prod));
                subcadena = strtok (NULL, " | ");
                
            }

        }
        fichero.close();
    }
    else {
        
        cout << "Error en la apertura del fichero" << endl;
    }
}

void Gramatica::exportar(char* salida)
{
    
    for (set<char>::iterator i = snoTerminales.begin(); i != snoTerminales.end(); i++) {
        int cnt = 0;
        for(int j = 0; j < producciones.size(); j++) {
            
            if(producciones[j].first == (*i)) {
                
                cnt++;
            }
        }
        tamProducciones.push_back(make_pair((*i),cnt));
    }
    
    ofstream fichero(salida);
    
    fichero << terminales << endl;
    
    for (set<char>::iterator i = sTerminales.begin(); i != sTerminales.end(); i++) {
        
        fichero << (*i) << " ";
    }
    
    fichero << endl;
    fichero << noTerminales << endl;
    
    for (set<char>::iterator i = snoTerminales.begin(); i != snoTerminales.end(); i++) {
        
        fichero << (*i) << " ";
    }
    
    fichero << endl;
    
    int k = 0;
    for (set<char>::iterator i = snoTerminales.begin(); i != snoTerminales.end(); i++) {
        
        fichero << (*i) << " -> ";
        
        int sz = tamProducciones[k].second;
        int princ = 0;
        
        for(int j = 0; j < producciones.size(); j++) {
            if(producciones[j].first == (*i)) {  
                princ++;
                if(sz == princ) {
                    
                    fichero << producciones[j].second;
                }
                else {
                    fichero << producciones[j].second << " | ";
                }
                     
            }
        }
        
        k++;
        fichero << endl;
    }
}

void Gramatica::primeraEtapa(void)
{
    set<char> vPrima;
    set<char> sInutiles;
    
    for (set<char>::iterator i = snoTerminales.begin(); i != snoTerminales.end(); i++) {
        
        for(int j = 0; j < producciones.size(); j++) {
            
            if(producciones[j].first == (*i)) {
                
                vPrima.insert((*i));
            }
        }
    }
    
    sInutiles = snoTerminales;
    
    for (set<char>::iterator i = vPrima.begin(); i != vPrima.end(); i++) {
        
        sInutiles.erase((*i));
    }
    
    snoTerminales = vPrima; 
    noTerminales = snoTerminales.size();
    
    for (set<char>::iterator i = sInutiles.begin(); i != sInutiles.end(); i++) {
        
        char inutil = (*i);
        string auxi(1,inutil);
        
        for(int j = 0; j<producciones.size(); j++) {
            
            if(auxi == producciones[j].second) {
                
                producciones.erase(producciones.begin()+j,producciones.begin()+j+1);
            }
            if(producciones[j].second.size() > 1) {
                
                for(int k = 0; k<producciones[j].second.size(); k++) {
                    
                    if(producciones[j].second[k] == inutil) {
                        
                        producciones[j].second[k] = ' ';
                    }
                }
            }
        }
    }
    

}

void Gramatica::segundaEtapa(void) {
    
    set<char> vPrima;
    set<char> sInutiles;
    set<char> noTermaux;
    vPrima.insert('S');
    
    for (set<char>::iterator i = snoTerminales.begin(); i != snoTerminales.end(); i++) {
        
        for(int j = 0; j < producciones.size(); j++) {
            
            for(int k = 0; k < producciones[j].second.size(); k++)
                
                if(producciones[j].second[k] == (*i)) {
                
                    vPrima.insert((*i));
                }
        }
    }
    
    set_difference(snoTerminales.begin(), snoTerminales.end(), vPrima.begin(), vPrima.end(), inserter(noTermaux, noTermaux.begin()));
    
    snoTerminales.clear();
    snoTerminales = vPrima;
    noTerminales = snoTerminales.size();
    
       for (set<char>::iterator i = noTermaux.begin(); i != noTermaux.end(); i++) {
        
        for(int j = 0; j < producciones.size(); j++) {
                
                if(producciones[j].first == (*i)) {
                
                    producciones.erase(producciones.begin()+j,producciones.begin()+j+1);
                }
        }
    }
}


void Gramatica::imprimirSet(set <char> C)
{
    for (set<char>::iterator i = C.begin(); i != C.end(); i++) {
        
        cout << (*i) << " ";
    }
}

void Gramatica::imprimirVector( vector <pair <char,string> >  C) {

    for(int i = 0; i < C.size(); i++) {
        cout << "No terminal: " << C[i].first << " Producción: " << C[i].second << endl;
        
    }
}

