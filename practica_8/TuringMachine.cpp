#include "TuringMachine.h"

TuringMachine::TuringMachine(char textfile[],char textfile2[]):
c(textfile2),
cabezal(1),
inicio_(NULL),
fin_(NULL),
t_uplas(0),
n_estados(0)
{
    ifstream fichero;
	fichero.open(textfile);
	if(!fichero.is_open()){
		cout << "Error de apertura." << endl;
	}
	else{
	    int n,acepta,tuplas,cont,verifica;
	    verifica=0;
	    fichero >> n;
	    set_sz(n);
	    int dest;
	    char r,w,m;
	    fichero >> n;
	    fichero >> acepta;
	    fichero >> tuplas;
	    t_uplas=tuplas;
	    int ticket1;
	    fichero >> ticket1;
	    estado* aux;
	    
	    for(int i=0; i < get_sz() ; i++){
	        aux=new estado(i);
	            if(acepta==aux->get_ticket())
	                aux->set_accept();
	       cont=0;
	        while((ticket1==i) && (verifica != t_uplas)){
	            fichero >> r >> w >> m;
	            fichero >> dest;
	            aux->set_tuplas(r,w,m,dest);
	            fichero >> ticket1;
	            cont++;
	            verifica++;
	        }
	        
	        aux->set_n_tuplas(cont);
	        
	        if(n==aux->get_ticket())
	            insertar_inicio(aux);
	        else 
	            insertar_fin(aux);
	    }
	    if(t_uplas!=verifica)
	    cout << "Error al crear la MT";
	}
}

TuringMachine::~TuringMachine(void){
    c.~cinta_t();
    estado* aux=inicio_;
	while(aux!=NULL){

		inicio_= inicio_->get_next();
		delete aux;
		aux=inicio_;
	}
}

int TuringMachine::get_cabezal(void){
    return cabezal;
}

void TuringMachine::set_cabezal(int i){
    cabezal=i;
}

void TuringMachine::insertar_inicio(estado* e){
	
	if(empty()){
		inicio_=e;
		fin_=e;
	}
	else{
		e->set_next(inicio_);
		inicio_->set_prev(e);
		inicio_ = e;
	}
}

void TuringMachine::insertar_fin(estado* e){

	if(empty()){
		inicio_=e;
		fin_=e;
	}
	else{
		e->set_prev(fin_);
		fin_->set_next(e);
		fin_ = e;
	}
}

estado* TuringMachine::extraer_inicio(void){

	if (inicio_==fin_){
		estado* aux = inicio_;
		inicio_ = NULL;
		fin_ = NULL;
		return aux;
	}
	else {
		estado* aux = inicio_;
		inicio_=inicio_->get_next();
		inicio_->set_prev(NULL);
		return aux;
	}
}

estado* TuringMachine::extraer_fin(void){
	
	if (inicio_==fin_){
		estado* aux = fin_;
		inicio_ = NULL;
		fin_ = NULL;
		return aux;
	}
	else {
		estado* aux = fin_;
		fin_=fin_->get_prev();
		fin_->set_next(NULL);
		return aux;
	}
}


int TuringMachine::get_sz(void){
    return n_estados;
}
void TuringMachine::set_sz(int i){
    n_estados=i;
}

void TuringMachine::mostrar(void){
    
    cout << endl;
    cout << get_sz() << endl;
    cout << inicio_->get_ticket() << endl;
    estado* aux;
    for(int i=0 ; i < get_sz() ; i++){
        aux = apuntar_destino(i);
        if(aux->get_accept())
            cout << aux->get_ticket() << " ";
    }
    cout << endl << t_uplas << endl;
    for(int i=0 ; i < get_sz() ; i++){
        aux=apuntar_destino(i);
        for(int x=0 ; x < aux->get_n_tuplas() ; x++){
            cout << aux->get_ticket() << " ";
            for(int y=0 ; y < 3 ; y++){
                cout << aux->get_item(x,y) << " ";
            }
            cout << aux->get_next_q(x) << endl;
        }
    }
}


bool TuringMachine::empty(void){
    if(inicio_==NULL)
    return true;
    else
    return false;
}

estado* TuringMachine::apuntar_destino(int i){
    estado* pointer = inicio_;
    while(pointer!=NULL){
        if(pointer->get_ticket()==i)
            return pointer;
        pointer=pointer->get_next();
    }
}

bool TuringMachine::analizar_cadena(void){
	
	cout << endl;
	int q_global=inicio_->get_ticket();
	char move;
	estado* aux;
	char temp;
	bool over=false;
	
	c.mostrar(1,q_global);
	while(over==false){
		over=true;
		aux=apuntar_destino(q_global);
		temp=c.get_data(cabezal);
		for(int i=0 ; i < aux->get_n_tuplas() ; i++){
			if(aux->get_item(i,0)==temp){
				over=false;
				c.set_data(cabezal,aux->get_item(i,1));
				move=aux->get_item(i,2);
				q_global=aux->get_next_q(i);
				switch (move){
					case 'L': cabezal--;break;
					case 'R': cabezal++;break;
					case 'S': {
						if(apuntar_destino(q_global)->get_accept()){
							c.mostrar(cabezal,q_global);
							cout << "Cadena Aceptada"<< endl;
							return true;
						}
						else{
							c.mostrar(cabezal,q_global);
							cout << "Cadena No Aceptada" << endl;
							return false;
						}
						break;
					}
					
				}
				c.mostrar(cabezal,q_global);
				
			}
		}
		
	}
		
	cout << "Cadena No Aceptada" << endl;
	return false;

}

void TuringMachine::mostrar_cinta(void){
	cout << endl;
	c.mostrar(-1,-1);
}