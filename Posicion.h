#ifndef POSICION_H
#define POSICION_H

typedef int elemento;
class Posicion
{
    public:
        Posicion();
        Posicion(elemento e);
        elemento elem;
        Posicion *siguiente;
        virtual ~Posicion(){}

    protected:

    private:
};

Posicion::Posicion()
{
    elem = 0;
    siguiente = 0;
}

Posicion::Posicion(elemento e) {
    elem = e;
    siguiente = 0;
}

#endif // POSICION_H
