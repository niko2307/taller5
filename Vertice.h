#ifndef VERTICE_H
#define VERTICE_H
#include "Vertice.hxx"

template <class T>
class Vertice {
private:
    T valor;

public:
    Vertice();
    Vertice(T val);
    T getValor();
    void setValor(T val);
};

#endif // VERTICE_H
