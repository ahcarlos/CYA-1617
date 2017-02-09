#include "NFA.hpp"

NFA_t::NFA_t(void):
  estados_(),
  estado_inicial_()
  {}

NFA_t::~NFA_t(void)
{}


    
bool NFA_t::leer_fichero(void)
{
  char fichero[80];
  cout<<"Introduzca el nombre del fichero a leer: ";
  cin>>fichero;
  ifstream f_entrada;
  f_entrada.open(fichero);
  if (f_entrada.is_open())
  {
    if(!estados_.empty())
		  estados_.erase(estados_.begin(),estados_.end());
    int n_estados_;
    int auxi;
    bool auxb;
    char auxc;
    int useless;
    f_entrada>>(int &) auxi;
    n_estados_=auxi;
    f_entrada>>(int &) auxi;
    int estado_inicial=auxi;
    for(int i=0; i<n_estados_; i++)
    {
      int sz;
      f_entrada>>(int &) useless;
      f_entrada>>(bool &) auxb>>(int &) auxi;
      sz=auxi;
      set<transition_state_t> transiciones;
      for(int j=0; j<sz; j++)
      {
        
        f_entrada>>(char &) auxc>>(int &) auxi;
          alfabeto_.insert(auxc); 
        transition_state_t dummy(auxc,auxi);
        transiciones.insert(dummy);
      }
      state_t tmp(transiciones,auxb,useless);
      estados_.insert(tmp);
      if(useless==estado_inicial)
      {
        estado_inicial_=get_state(useless);
      }

    }
    f_entrada.close();
  }
  else
  {
    cout<<"Error en la apertura del fichero."<<endl;
    return(0);
  }
  return(1);
}



ostream& operator<<(ostream &output, const NFA_t &x)
{
  output<<"\n"<<x.get_n_estados()<<"\n"<<x.get_inicial().get_id()<<"\n";
  for(set<state_t>::iterator i=x.get_estados().begin(); i!=x.get_estados().end(); i++)
    output<<(*i)<<"\n";
  return(output);
}


set<state_t> NFA_t::get_estados(void) const
{
  return(estados_);
}


int NFA_t::get_n_estados(void)
{
  return(estados_.size());
}


int NFA_t::get_n_estados(void) const
{
  return(estados_.size());
}



void NFA_t::mostrar(void)
{
  cout<<estados_.size()<<endl;
  cout<<estado_inicial_.get_id()<<endl;
  for(set<state_t>::iterator i=estados_.begin(); i!=estados_.end(); i++)
  {
    (*i).mostrar();
    cout<<endl;
  }
  
  bool comprueba = es_dfa();
  
  if(comprueba)
  {
    cout << "Corresponde a un DFA el formato" << endl;
  }
  else
  {
    cout << "El formato introducido no corresponde a un DFA" << endl;
  }
}

state_t NFA_t::get_inicial(void)
{
  return(estado_inicial_);
}

state_t NFA_t::get_inicial(void) const
{
  return(estado_inicial_);
}



void NFA_t::analizar_cadena(void)
{
  char cadena[85];
  cout<<"Introduzca la cadena que desea analizar: ";
  cin>>cadena;
 
  cout<<"Cadena de entrada: "<<cadena<<endl;
  state_t aux=estado_inicial_;
  int n=0;
  bool baux=0;
  stringbuf buffer;
  ostream os (&buffer);
  analizar_cadena_recursivo(n,cadena,-1,buffer,os,estado_inicial_,baux);
  cout<<"Decisión final:"<<endl;
  cout<<"Cadena de entrada ";
  if(baux)
    cout<<"ACEPTADA";
  else
    cout<<"NO ACEPTADA";
  cout<<endl;
}



void NFA_t::analizar_cadena_recursivo(int &n, char cadena [], int i,const stringbuf &buffer, const ostream &os, state_t estado, bool &baux)
{
  if(cadena[i+1]!='\0') // si es solo un simbolo o va por el ultimo
  {
    set<int> transiciones=estado.get_epsilon_clausura();
    if(transiciones.size()!=0)
    {
      for(set<int>::iterator x=transiciones.begin(); x!=transiciones.end(); x++)
      {
        stringbuf buffer2;
        ostream os2(&buffer2);
        
        os2<<left<<buffer.str()<<left<<setw(17)<<setfill(' ')<<estado.get_id()<<setw(11)<<setfill(' ')<<"~"<<(*x)<<endl;
        analizar_cadena_recursivo(n,cadena,i,buffer2,os2,get_state((*x)), baux);
      }
    }
    if(!transiciones.empty())
		  transiciones.erase(transiciones.begin(),transiciones.end());
    transiciones=estado.get_conjunto_transiciones(cadena[i+1]);
    if(transiciones.size()==0)
    {
      n++;
      cout<<"Camino "<<n<<":"<<endl;
      cout<<"Estado actual    Entrada    Siguiente estado"<<endl;
      cout<<left<<buffer.str();
      cout<<left<<setw(17)<<setfill(' ')<<estado.get_id()<<setw(11)<<setfill(' ')<<cadena[i+1]<<estados_.size()<<endl;
      for(int j=i+2; cadena[j]!='\0'; j++)
        cout<<left<<setw(17)<<setfill(' ')<<estados_.size()<<setw(11)<<setfill(' ')<<cadena[j]<<estados_.size()<<endl;
      cout<<"Cadena de entrada ";
      cout<<"NO ACEPTADA."<<endl;
    }
    else
    {
      for(set<int>::iterator x=transiciones.begin(); x!=transiciones.end(); x++)
      {
        stringbuf buffer2;
        ostream os2(&buffer2);
        os2<<left<<buffer.str()<<left<<setw(17)<<setfill(' ')<<estado.get_id()<<setw(11)<<setfill(' ')<<cadena[i+1]<<(*x)<<endl;
        analizar_cadena_recursivo(n,cadena,i+1,buffer2,os2,get_state((*x)), baux);
      }
    }
  }
  else //comprobamos las e-transiciones
  {
    set<int> epsilon_transiciones=estado.get_epsilon_clausura();
    if(epsilon_transiciones.size()!=0)
    {
      for(set<int>::iterator x=epsilon_transiciones.begin(); x!=epsilon_transiciones.end(); x++)
      {
        stringbuf buffer2;
        ostream os2(&buffer2);
        os2<<left<<buffer.str()<<left<<setw(17)<<setfill(' ')<<estado.get_id()<<setw(11)<<setfill(' ')<<"~"<<(*x)<<endl;
        analizar_cadena_recursivo(n,cadena,i,buffer2,os2,get_state((*x)), baux);
      }
    }
    n++;
    cout<<"Camino "<<n<<":"<<endl;
    cout<<"Estado actual    Entrada    Siguiente estado"<<endl;
    cout<<left<<buffer.str()<<endl;
    cout<<"Cadena de entrada ";
    if(estado.aceptacion()) //si cae en estado de aceptacion devolvemos aceptada, si no se rechaza
    {
      cout<<"ACEPTADA."<<endl;
      if(!baux)
        baux=1;
    }
    else
      cout<<"NO ACEPTADA."<<endl;
  }
}

state_t NFA_t::get_state(const int x)
{
  for(set<state_t>::iterator i=estados_.begin(); i!=estados_.end(); i++)
   if((*i).get_id()==x)
     return(*i);
  cout<<x<<endl;
  cout<<"Estado no encontrado."<<endl;
}

void NFA_t::mostrar_estados_muerte(void)
{
  for(set<state_t>::iterator i=estados_.begin(); i!=estados_.end(); i++)
    if((*i).estado_muerte())
      cout<<"q"<<(*i).get_id()<<" es un estado de muerte."<<endl;
  
  cout<<"q"<<estados_.size()<<" es un estado de muerte."<<endl;
}


/*
void NFA_t::es_dfa(void)
{
  
  if(transiciones_.size() == alfabeto_.size())
  {
      for(set<state_t>::iterator i=estados_.begin(); i!=estados_.end(); i++)
    {
    
    
      state_t auxs = (*i);
      transition_state_t auxt = auxs.get_transiciones();
      
      for(set<transition_state_t>::iterator j=auxt.begin(); j!=auxt.end(); j++)
      {
        for(set<transition_state_t>::iterator j=alfabeto_.begin(); j!=alfabeto_.end(); j++) 
        {
            
          if((*j).get_char() == (*k))
          {
            
          }
        }  
      }
    
    
    }
  
  }
  
} 

*/

bool NFA_t::es_dfa(void)
{
    set<transition_state_t> aux2; 
    for (set<state_t>::iterator i = estados_.begin(); i != estados_.end(); i++)
     {
        state_t aux; 
        aux = (*i);
        aux2 =  aux.get_transiciones();
     
     
        vector<int> contador(alfabeto_.size());
        vector<char> alfabeto(alfabeto_.size());
        int cnt = 0;
        
        for (set<char>::iterator j = alfabeto_.begin(); j!= alfabeto_.end(); j++)
        {
            char crt = (*j);
            alfabeto[cnt] = crt;
            cnt++;
        }
        
        
        cnt = 0;
        for (set<transition_state_t>::iterator j = aux2.begin(); j!= aux2.end(); j++)
        {
            char crt = (*j).get_char();
            if(alfabeto[cnt] == crt)
            {
                contador[cnt]++;
            }
            cnt++;
        }
        
        for(int i = 0; i<contador.size(); i++)
        {
            
            if(contador[i] != 1)
                return false;
        }
     }
     
     return true;
}