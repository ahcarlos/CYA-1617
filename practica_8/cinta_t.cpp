#include "cinta_t.h"

cinta_t::cinta_t(char textfile[]):
cinta(NULL),
sz_(0)
{
    ifstream fichero;
	fichero.open(textfile);
	string a;
	
	if(!fichero.is_open())
	{
		cout << "Error de apertura." << endl;
	}
	else{
	    getline(fichero,a);
	    sz_=a.length()+2;
	    
	    cinta = new char [sz_];
	    
	    set_data(0,'$');
	    set_data(sz_-1,'$');
	    int x=0;
	    
	    for(int i=1; i< sz_-1 ; i++){
	        set_data(i,a[x]);
	        x++;
	    }
	}
	
}

cinta_t::~cinta_t(void){
    if(cinta!=NULL)
        delete [] cinta;
    cinta=NULL;
}

char cinta_t::get_data(int i){
    return cinta[i];
}

void cinta_t::set_data(int i, char x){
	cinta[i]=x;
}

void cinta_t::mostrar(int interrupcion,int muestra){
	for(int i=0; i < sz_ ; i++){
		if(interrupcion==i){
			cout << " q"<<muestra << " ";
        	cout << cinta[i];
		}
		else{
			cout << cinta[i];
		}
    }
    cout << endl;
}