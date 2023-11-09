#include "Vertice.h"

template <class T>
Vertice<T>::Vertice() {}

template <class T>
Vertice<T>::Vertice(T val) {
    valor=val;
}

template <class T>
T Vertice<T>::getValor() {
    return valor;
}

template <class T>
void Vertice<T>::setValor(T val) {
    valor = val;
}
