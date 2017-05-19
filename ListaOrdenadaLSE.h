#ifndef LISTAORDENADALSE_H
#define LISTAORDENADALSE_H
#include "Posicion.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

typedef Posicion* posicion;
class ListaOrdenadaLSE
{
    public:
        ListaOrdenadaLSE(){}
        virtual ~ListaOrdenadaLSE(){}
        void Iniciar();
        void Destruir();
        void Vaciar();
        bool Vacia();
        posicion Agregar(elemento e);
        void Borrar(posicion p);
        elemento Primero();
        elemento Siguiente(posicion p);
        elemento Ultimo();
        elemento Anterior(posicion p);
        int NumElem();
        void Listar();
        posicion posNula;
        int numElem;
        bool vacia;
        posicion primera;


    protected:

    private:
};

#endif // LISTAORDENADALSE_H



/**
Nombre: Iniciar
Parámetros: L
Efecto: Inicializa la lista
Requiere: Lista no inicializada
Modifica:

*/
void ListaOrdenadaLSE::Iniciar()
{
    numElem = 0;
    posNula = 0;
    primera = 0;
    vacia = true;
}

/**
Nombre: Destruir
Parámetros: L
Efecto: Destruye la lista
Requiere: Lista inicializada
Modifica:

*/
void ListaOrdenadaLSE::Destruir()
{
    posicion p = primera;
    while(vacia == false)
    {
        Borrar(p);
        p = p->siguiente;
    }
}

/**
Nombre: Vaciar
Parámetros: L
Efecto: Elimina los elementos dentro de una Lista
Requiere: Lista inicializada
Modifica: Lista, NumElem

*/
void ListaOrdenadaLSE::Vaciar()
{
    posicion p = primera;
    while(vacia == false)
    {
        Borrar(p);
        p = p->siguiente;
    }
    primera = 0;
    posNula = 0;
    vacia = true;
    numElem = 0;
}

/**
Nombre: Vacia
Parámetros: L
Efecto: Devuelve true si la lista esta vacia o false si no lo esta
Requiere: Lista inicializada
Modifica:

*/
bool ListaOrdenadaLSE::Vacia()
{
    return vacia;
}

/**
Nombre: Agregar
Parámetros: L, elemento e
Efecto: Inserta el elemento e en orden
Requiere: Lista inicializada
Modifica: Lista, NumElem

*/
posicion ListaOrdenadaLSE::Agregar(elemento e)
{
    posicion nueva = new Posicion;
    if(vacia == true)
    {
        numElem = 1;
        nueva->elem = e;
        nueva->siguiente = posNula;
        primera = nueva;
        //primera = new Posicion(e);
        //primera->siguiente = posNula;
        vacia = false;
    }
    else
    {
        posicion p1 = primera;
        if(p1->siguiente == posNula && p1->elem <e)
            {
                //posicion nueva = new Posicion(e);
                nueva->elem = e;
                nueva->siguiente = p1->siguiente;
                p1->siguiente = nueva;
                numElem++;
            }
        else if(p1->elem > e)
        {
            //posicion nueva = new Posicion(e);
            nueva->elem = e;
            nueva->siguiente = p1;
            primera = nueva;
            numElem++;

        }
        else
        {
            while(p1->siguiente != posNula && p1->elem <e && p1->siguiente->elem <e)
            {
                p1 = p1->siguiente;
            }
            if(p1->siguiente != posNula && p1->elem <e && p1->siguiente->elem >e)
            {
                //posicion nueva = new Posicion(e);
                nueva->elem = e;
                nueva->siguiente = p1->siguiente;
                p1->siguiente = nueva;
                numElem++;
            }
            else if(p1->siguiente == posNula)
            {
                //posicion nueva = new Posicion(e);
                nueva->elem = e;
                nueva->siguiente = p1->siguiente;
                p1->siguiente = nueva;
                numElem++;

            }

        }
    }
    return nueva;

}

/**
Nombre: Borrar
Parámetros: L, posicion p
Efecto: Borra el elemento en la posicion p de la lista
Requiere: Lista inicializada, p tiene que ser una posicion valida
Modifica: Lista, NumElem

*/
void ListaOrdenadaLSE::Borrar(posicion p)
{
    posicion p1 = primera;
    if(p1->elem == p->elem && p->siguiente == posNula)
    {
        delete p1;
        primera = 0;
        numElem--;
        vacia = true;
    }
    else if(p1->elem == p->elem && p->siguiente != posNula)
    {
        posicion aux = p1->siguiente;
        //p1->siguiente = posNula;
        primera = aux;
        delete p1;
        numElem--;
    }
    if(p1->elem !=p->elem && p->siguiente != posNula)
    {
        while(p1->siguiente != posNula && p1->siguiente->elem != p->elem)
        {
            p1= p1->siguiente;
        }
        if(p1->siguiente->elem == p->elem)
        {
            posicion borrar = p1->siguiente;
            posicion aux = borrar->siguiente;
            p1->siguiente = aux;
            //borrar = posNula;
            delete borrar;
        }
    }
    if(p->siguiente == posNula && p1->elem !=p->elem)
    {
        while(p1->siguiente != posNula && p1->siguiente->elem != p->elem )
        {
            p1= p1->siguiente;
        }
        if(p1->siguiente->elem = p->elem)
        {
            posicion borrar = p1->siguiente;
            p1->siguiente = posNula;
            //borrar = posNula;
            delete borrar;
            numElem--;
        }
    }
}

/**
Nombre: Primero
Parámetros: L
Efecto: Retorna el primer elemento en la lista
Requiere: Lista inicializada
Modifica:

*/
elemento ListaOrdenadaLSE::Primero()
{
    return primera->elem;
}

/**
Nombre: Siguiente
Parámetros: L, posicion p
Efecto: Devuelve el siguiente elemento despues de la posicion p en la lista
Requiere: Lista inicializada, p debe ser una posicion valida
Modifica:

*/
elemento ListaOrdenadaLSE::Siguiente(posicion p)
{
   return p->siguiente->elem;
}

/**
Nombre: Ultimo
Parámetros: L
Efecto: Devuelve el ultimo elemento en la lista
Requiere: Lista inicializada
Modifica:

*/
elemento ListaOrdenadaLSE::Ultimo()
{
    posicion p1 = primera;
    while(p1->siguiente != posNula)
    {
        p1= p1->siguiente;
    }
    if(p1->siguiente == posNula)
    {
        return p1->elem;
    }

}

/**
Nombre: Anterior
Parámetros: L, posicion p
Efecto: Devuelve el elemento anterior a la posicion p en la lista
Requiere: Lista inicializada, p debe ser una posicion valida en la lista
Modifica:

*/
elemento ListaOrdenadaLSE::Anterior(posicion p)
{
    posicion p1 = primera;
    while(p1->siguiente != p)
    {
        p1 = p1->siguiente;
    }
    if(p1->siguiente == p)
    {
        return p1->elem;
    }

}


/**
Nombre: NumElem
Parámetros: L
Efecto: Devuelve un entero con la cantidad de elementos en la lista
Requiere: Lista inicializada
Modifica:

*/
int ListaOrdenadaLSE::NumElem()
{
    return numElem;
}


void ListaOrdenadaLSE::Listar()
{
    cout << "Los elementos en la lista son: ";
    posicion p = primera;
    int i = 0;
    while(i!=numElem)
    {
        cout<< p->elem << " ";
        p = p->siguiente;
        i++;
    }
}
