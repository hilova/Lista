#ifndef LISTAORDENADAARREGLO_H
#define LISTAORDENADAARREGLO_H
#include <Posicion.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int posicion;
class ListaOrdenadaArreglo
{
    public:
        ListaOrdenadaArreglo() {}
        ~ListaOrdenadaArreglo() {}
        void Iniciar();
        void Destruir();
        void Vaciar();
        bool Vacia();
        void Agregar(elemento e);
        void Borrar(posicion p);
        posicion Primero();
        posicion Siguiente(posicion p);
        posicion Ultimo();
        posicion Anterior(posicion p);
        void Listar();
        int NumElem();
        posicion posNula;
        elemento arreglo[17];
        int ultimoLleno;

    protected:

    private:
};

#endif // LISTAORDENADAARREGLO_H



/**
Nombre: Iniciar
Parámetros: L
Efecto: Inicializa la lista
Requiere: Lista no inicializada
Modifica:

*/
void ListaOrdenadaArreglo::Iniciar()
{
    ultimoLleno = -1;
    posNula = -1;
}

/**
Nombre: Destruir
Parámetros: L
Efecto: Destruye la lista
Requiere: Lista inicializada
Modifica:

*/
void ListaOrdenadaArreglo::Destruir()
{
    ultimoLleno = -1;
}

/**
Nombre: Vaciar
Parámetros: L
Efecto: Elimina los elementos dentro de una Lista
Requiere: Lista inicializada
Modifica: Lista, NumElem

*/
void ListaOrdenadaArreglo::Vaciar()
{
    ultimoLleno = -1;
}

/**
Nombre: Vacia
Parámetros: L
Efecto: Devuelve true si la lista esta vacia o false si no lo esta
Requiere: Lista inicializada
Modifica:

*/
bool ListaOrdenadaArreglo::Vacia()
{
    if(ultimoLleno == -1){
        return true;
    }
    else{
        return false;
    }
}

/**
Nombre: Agregar
Parámetros: L, elemento e
Efecto: Inserta el elemento e en orden
Requiere: Lista inicializada
Modifica: Lista, NumElem

*/
void ListaOrdenadaArreglo::Agregar(elemento e)
{
    int i = 0;
//    if(ultimoLleno == -1)
//    {
//        arreglo[0] = e;
//        ultimoLleno++;
//    }
//    if(arreglo[0]>e)
//    {
//        int j = ultimoLleno+1;
//        while(j!= 0)
//        {
//            arreglo[j]=arreglo[j-1];
//            j--;
//        }
//        arreglo[0] = e;
//        ultimoLleno++;
//    }
    while(arreglo[i] < e)
    {
        i++;
    }
    if(arreglo[i-1]<e)
    {
        int j = ultimoLleno+1;
        while(j>i)
        {
            arreglo[j] = arreglo[j-1];
            j--;
        }
        arreglo[i]=e;
        ultimoLleno++;
    }
    else if(arreglo[i] == posNula)
    {
        arreglo[i] = e;
        ultimoLleno++;
    }

}

/**
Nombre: Borrar
Parámetros: L, posicion p
Efecto: Borra el elemento en la posicion p de la lista
Requiere: Lista inicializada, p tiene que ser una posicion valida
Modifica: Lista, NumElem

*/
void ListaOrdenadaArreglo::Borrar(posicion p)
{
    while(p < ultimoLleno)
    {
        arreglo[p] = arreglo[p+1];
        p++;

    }
    ultimoLleno--;
}

/**
Nombre: Primero
Parámetros: L
Efecto: Retorna el primer elemento en la lista
Requiere: Lista inicializada
Modifica:

*/
elemento ListaOrdenadaArreglo::Primero()
{
    return arreglo[0];
}

/**
Nombre: Siguiente
Parámetros: L, posicion p
Efecto: Devuelve el siguiente elemento despues de la posicion p en la lista
Requiere: Lista inicializada, p debe ser una posicion valida
Modifica:

*/
elemento ListaOrdenadaArreglo::Siguiente(posicion p)
{
    return arreglo[p+1];
}

/**
Nombre: Ultimo
Parámetros: L
Efecto: Devuelve el ultimo elemento en la lista
Requiere: Lista inicializada
Modifica:

*/
elemento ListaOrdenadaArreglo::Ultimo()
{
    return arreglo[ultimoLleno];
}

/**
Nombre: Anterior
Parámetros: L, posicion p
Efecto: Devuelve el elemento anterior a la posicion p en la lista
Requiere: Lista inicializada, p debe ser una posicion valida en la lista
Modifica:

*/
elemento ListaOrdenadaArreglo::Anterior(posicion p)
{
    return arreglo[p-1];
}


/**
Nombre: NumElem
Parámetros: L
Efecto: Devuelve un entero con la cantidad de elementos en la lista
Requiere: Lista inicializada
Modifica:

*/
int ListaOrdenadaArreglo::NumElem()
{
    return ultimoLleno+1;
}

void ListaOrdenadaArreglo::Listar()
{
    int i=0;
    cout<< "Los elementos en la lista son" <<endl;
    while(i!= ultimoLleno+1)
    {
        cout<< arreglo[i] << " ";
        i++;
    }
    cout<<endl;
}
