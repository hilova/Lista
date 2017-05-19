#include <iostream>
#include <stdlib.h>
#include "include/Posicion.h"
//#include "include/ListaOrdenadaArreglo.h"
#include "include/ListaOrdenadaLSE.h"


using namespace std;

int main()
{
//    ListaOrdenadaArreglo lista;
    ListaOrdenadaLSE lista;
    lista.Iniciar();
    lista.Agregar(7);
    posicion pos = lista.Agregar(3);
    lista.Agregar(2);
    //lista.Agregar(8);
    lista.Agregar(3);
    lista.Agregar(0);
    //lista.Agregar(20);
//    posicion pos = lista.Agregar(2);
    lista.Borrar(pos);
    lista.Listar();



    return 0;
}
