#include <iostream>
#include <cstdlib>
#include <queue>
#include "arbin.h"
#include "abb.h"
#include "Excep_Ej6.h"

// Recorridos

template <typename T>
void inorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        inorden(a, a.subIzq(r));
        cout << r.observar() << " ";
        inorden(a, a.subDer(r));
    }
}

template <typename T>
void preorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        cout << r.observar() << " ";
        preorden(a, a.subIzq(r));
        preorden(a, a.subDer(r));
    }
}

template <typename T>
void postorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        postorden(a, a.subIzq(r));
        postorden(a, a.subDer(r));
        cout << r.observar() << " ";
    }
}

template <typename T>
void anchura(const Arbin<T>& a) {
    if (!a.esVacio()) {
        queue<typename Arbin<T>::Iterador> c;
        typename Arbin<T>::Iterador ic = a.getRaiz();
        c.push(ic);
        while (!c.empty()) {
             ic = c.front();
             c.pop();
             cout << ic.observar() << " ";
             if (!a.subIzq(ic).arbolVacio())
                c.push(a.subIzq(ic));
             if (!a.subDer(ic).arbolVacio())
                c.push(a.subDer(ic));
        }
    }
}


/***************************************************************************/
/****************************** EJERCICIOS *********************************/
/***************************************************************************/
//Ejercicio 1

int numHojas(const Arbin<char> &a, const typename Arbin<char>::Iterador &r){
    if(a.subDer(r).arbolVacio() && a.subIzq(r).arbolVacio()){
        return 1;
    }

    return 0;
}


int numHojas(const Arbin<char>& a){
    return (numHojas(a, a.subDer(a.getRaiz())) + numHojas(a,a.subIzq(a.getRaiz())));
}

/****************************************************************************/
//Ejercicio 2
void simetrico(const Arbin<char> &a, const typename Arbin<char>::Iterador r){
    if(!a.esVacio())
        throw ArbolVacioExcepcion();
    //intercambio


    simetrico(a, a.subDer(a.getRaiz()));
    simetrico(a, a.subIzq(a.getRaiz()));
}


Arbin<char> simetrico(const Arbin<char> &a){
    simetrico(a, a.getRaiz());
}

/****************************************************************************/
//Ejercicio 3


/******************************************************************************/
//Ejercicio 4



/*****************************************************************************/
//Ejercicio 5
void palabra(const Arbin<char>& a, const Arbin<char>::Iterador r, char** pbr, int filas = 0, int columnas = 0){


    if(a.esVacio())
        throw ArbolVacioExcepcion();

    if(a.subDer(a.getRaiz()).arbolVacio() && a.subIzq(a.getRaiz()).arbolVacio()){
        filas++;
        columnas = 0;
    }


    columnas++;

    char** pbr;
    char** tmp = pbr;
    pbr = new char*[filas+1];
    for(int i = 0; i < filas; i++)
        pbr[filas] = new char[columnas+1];
    for(int i = 0; i < filash-1; i++)
        for(int j = 0; j < columnas-1; j++)
            pbr[i][j] = aux[i][j];
    pbr[filas][columnas] = a.getRaiz().observar();


    pbr[0][0] = a.getRaiz().observar();

    palabra(a, a.subDer(a.getRaiz()), pbr, filas, columnas);
    palabra(a, a.subIzq(a.getRaiz()), pbr, filas, columnas);

}

void palabra(const Arbin<char>& a){
    char** pbr;
    palabra(a, a.getRaiz(), pbr);
    for(int i = 0; i < pbr)
}



/******************************************************************************/
//Ejercicio 6
/*int siguienteMayor(const ABB<int> & a, int x)throw (NoHaySiguienteMayor){
    int sm = siguiente;
    eRaiz= r.observat();
    if(eRaiz == x){
        if(!a.subDer(r).arbolVacio()){
            sm = minimo (a, a.subDer(r));
        }
        else{
            if(eRaiz < x){
                siguienteMayor(a, a.subDer(r), x, sm);
            }
            else{
                sm = eRaiz;
                siguienteMayor(a, a.subIzq(r),x,sm);
            }
        }
    }

}
*/

/******************************************************************************/
//Ejercicio 7


/******************************************************************************/
//Ejercicio 8



/****************************************************************************/
/****************************************************************************/
int main(int argc, char *argv[])
{
    Arbin<char> A('t', Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()));

    Arbin<char> B('t', Arbin<char>('n', Arbin<char>(),
                                        Arbin<char>('d', Arbin<char>('e', Arbin<char>(), Arbin<char>()),
                                                         Arbin<char>())),
                       Arbin<char>('m', Arbin<char>('f', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('n', Arbin<char>(), Arbin<char>())));

    Arbin<char> D('t', Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()),
                       Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())));

    Arbin<char> E('o', Arbin<char>('r', Arbin<char>(),
                                        Arbin<char>('o', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('l', Arbin<char>('a', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('e', Arbin<char>(), Arbin<char>())));

    Arbin<int> F(2, Arbin<int>(7, Arbin<int>(2, Arbin<int>(), Arbin<int>()),
                                  Arbin<int>(6, Arbin<int>(5, Arbin<int>(), Arbin<int>()),
                                                Arbin<int>(11, Arbin<int>(), Arbin<int>()))),
                    Arbin<int>(5, Arbin<int>(),
                                  Arbin<int>(9, Arbin<int>(),
                                                  Arbin<int>(4, Arbin<int>(), Arbin<int>()))));

    ABB<int> BB6, BB7;



    // NUMERO HOJAS //
    cout << "Num. hojas del arbol B: " << numHojas(B) << endl;
    cout << "Num. hojas del arbol E: " << numHojas(E) << endl << endl;



 /*

    // COPIA SIMETRICA //
    Arbin<char> C = simetrico(B);
    cout << "Recorrido en inorden del arbol B: " << endl;
    inorden(B, B.getRaiz());
    cout << endl << "Recorrido en inorden del arbol C: " << endl;
    inorden(C, C.getRaiz());
    cout << endl << endl;



    // RECORRIDO EN ZIG-ZAG //
    cout << "Recorrido en zigzag I de B:\n";
    recorridoZigzag(B, 'I');
    cout << endl;
    cout << "Recorrido en zigzag D de C:\n";
    recorridoZigzag(C, 'D');
    cout << endl << endl;


    // COMPENSADO //
    cout << "Esta A compensado?:";
    cout << (compensado(A) ? " SI" : " NO") << endl;
    cout << "Esta B compensado?:";
    cout << (compensado(B) ? " SI" : " NO") << endl << endl;

    // PALABRAS DE UN ARBOL //
    cout << "PALABRAS DE A:\n";
    palabras(E);
    cout << "PALABRAS DE B:\n";
    palabras(B);
    cout << endl;

    // SIGUIENTE MAYOR
    BB6.insertar(8); BB6.insertar(3); BB6.insertar(10); BB6.insertar(1); BB6.insertar(6);
    BB6.insertar(14); BB6.insertar(4); BB6.insertar(7); BB6.insertar(13);
    try
    {
        cout << "Siguiente mayor en BB6 de 5: " << siguienteMayor(BB6, 5) << endl;
        cout << "Siguiente mayor en BB6 de 8: " << siguienteMayor(BB6, 8) << endl;
        cout << "Siguiente mayor en BB6 de 13: " << siguienteMayor(BB6, 13) << endl;
        cout << "Siguiente mayor en BB6 de 14: " << siguienteMayor(BB6, 14) << endl;
    }
    catch(const NoHaySiguienteMayor& e)
    {
        cout << e.Mensaje() << endl << endl;
    }

    // POSICION INORDEN //
    BB7.insertar(5); BB7.insertar(1); BB7.insertar(3); BB7.insertar(8); BB7.insertar(6);
    cout << "Posicion Inorden en BB7 de 3: ";
    cout << posicionInorden(BB7, 3);
    cout << endl << "Posicion Inorden en BB7 de 8: ";
    cout << posicionInorden(BB7, 8);
    cout << endl << "Posicion Inorden en BB7 de 7: ";
    cout << posicionInorden(BB7, 7);
    cout << endl << endl;

    // SUMA CAMINO
    cout << "Hay un camino de suma 26 en F?:";
    cout << (haySumaCamino(F, 26) ? " SI" : " NO") << endl;
    cout << "Hay un camino de suma 9 en F?:";
    cout << (haySumaCamino(F, 9) ? " SI" : " NO") << endl;
*/

    system("PAUSE");
    return 0;
}
