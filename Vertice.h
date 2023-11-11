#ifndef VERTICE_H
#define VERTICE_H

template <class T>
class vertice {
private:
    T valor;

public:
    vertice();
    vertice(T val);
    T getValor();
    void setValor(T val);
};

#include "Vertice.hxx"
#endif // VERTICE_H
