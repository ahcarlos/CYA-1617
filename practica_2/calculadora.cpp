#include "calculadora.hpp"



    calculadora_t::calculadora_t(set<string> A, set<string> B):
    L1_(A),
    L2_(B)
    {}

    calculadora_t::~calculadora_t(void)
    {}

    void calculadora_t::potencia(int n)
    {
        if(n == 0)
        {
            cout << "{&}" << endl;
        }
        else
        {
            set<string> C;

            for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
            {
                if((*i) != "&"){
                    C.insert(*i);
                }
            }

            int numero = L1_.size();
            for(int i = 1; i < n; i++)
            {
                numero *= L1_.size();
            }

        while(C.size() < numero)
        {
            C = potencia_(C, L1_);
        }
        print(C);
        }
    }

    void calculadora_t::potencia(int n, set<string> A)
    {
        if(n == 0)
        {
            cout << "{&}" << endl;
        }
        else
        {
            set<string> C;

            for (set<string>::iterator i = A.begin(); i != A.end(); i++)
            {
                if((*i) != "&"){
                    C.insert(*i);
                }

            }

            int numero = A.size();
            for(int i = 1; i < n; i++)
            {
                numero *= A.size();
            }

        while(C.size() < numero)
        {
            C = potencia_(C, A);
        }
        print(C);
        }
    }

    set<string> calculadora_t::potencia_(set<string> C1, set<string> C2)
    {
        string aux;
        string aux2;
        set<string> resultado;
            for (set<string>::iterator i = C1.begin(); i != C1.end(); i++){
                for (set<string>::iterator j = C2.begin(); j != C2.end(); j++){
                    aux = (*i);
                    aux2 = (*j);
                    aux.insert(aux.size(), aux2);
                    resultado.insert(aux);
                }
            }
        return resultado;
    }

    void calculadora_t::inversa(void)
    {
            string aux;
            int iaux=0;

            cout << "L^-1 = {";
            for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
            {
                 aux = (*i);

                 for (string::reverse_iterator rit= aux.rbegin(); rit!= aux.rend(); rit++)
                 cout << *rit;

                 if (iaux != L1_.size()-1)
                 {
                        cout << "," ;
                 }
                 iaux++;
            }
            cout << "}" << endl << endl;

    }

     void calculadora_t::inversa(set<string> A)
    {
            string aux;
            int iaux=0;

            cout << "L^-1 = {";
            for (set<string>::iterator i = A.begin(); i != A.end(); i++)
            {
                 aux = (*i);

                 for (string::reverse_iterator rit= aux.rbegin(); rit!= aux.rend(); rit++)
                 cout << *rit;

                 if (iaux != A.size()-1)
                 {
                        cout << "," ;
                 }
                 iaux++;
            }
            cout << "}" << endl << endl;

    }



    void calculadora_t::concatenacion(void)
    {
        cout << "L1 * L2 = {";
        int iaux=0;
        string cvacio="&";
        for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
        {
             for (set<string>::iterator j = L2_.begin(); j != L2_.end(); j++)
             {
                    if (*i == cvacio)
                    {
                            cout << *j;
                    }
                    else if ( *j == cvacio)
                    {
                            cout << *i;
                    }
                    else
                    {
                            cout << *i << *j;
                    }

                   if (iaux < L1_.size()*L2_.size())
                    {
                        cout << "," ;
                    }

                    iaux++;
             }
            iaux++;
        }


        cout << "}" << endl << endl;
    }

    void calculadora_t::unions(void)
    {
    	cout << "Unión: ";
	    ostream_iterator <string> iter( cout, " " );
	    set_union(L1_.begin(), L1_.end(), L2_.begin(), L2_.end(), iter );
        cout << endl;

    }

    void calculadora_t::interseccion(void)
    {
        cout << "Intersección: ";
        ostream_iterator <string> iter( cout, " " );
	    set_intersection(L1_.begin(), L1_.end(), L2_.begin(), L2_.end(), iter);
	    cout << endl;
    }

    void calculadora_t::diferencia(void)
    {
        ostream_iterator <string> iter( cout, " " );
        set <string> C;

	    set_difference(L1_.begin(), L1_.end(), L2_.begin(), L2_.end(), inserter(C, C.begin()));

	    cout << "Diferencia de A y B: ";
	    copy(C.begin(), C.end(), iter);
	    cout << endl;
    }

    bool calculadora_t::sublenguajes(void)
    {
        int aux=0;

        for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
        {
                for (set<string>::iterator j = L2_.begin(); j != L2_.end(); j++)
                {
                    if((*i) == (*j))
                    {
                        aux++;

                    }
                }

                if (aux == L2_.size()-1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
        }
        cout << "}" << endl;
    }

  bool calculadora_t::igualdad_lenguajes(void)
    {
       int aux= 0;


        if(L1_.size() != L2_.size())
        {
            return false;
        }

        else{

            for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
                for (set<string>::iterator j = L2_.begin(); j != L2_.end(); j++)
                    if((*i) == (*j))
                        aux ++;


            if(aux == L1_.size())
             {

                return true;
             }
            else
            {

                return false;
            }


        }


    }






    void calculadora_t::print(set <string> C)
    {
        cout << "Potencia L^" <<": {";
        int iaux=0;
	    for (set<string>::iterator i = C.begin(); i != C.end(); i++)
	    {
	        cout << (*i);

	        if (iaux != C.size()-1)
            {
                    cout << "," ;
            }
            iaux++;
	    }

	   cout << "}" << endl << endl;

    }

    void calculadora_t::cierre_kleene(void)
    {
        cout << "L* = { &,";
        int iaux=0;
        for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
        {
             cout << *i <<",";
             cout << *i << *i <<",";
        }


        cout << ", ...}" << endl << endl;
    }
