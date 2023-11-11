#include "Vertice.h"

template <class T>
vertice<T>::vertice() {

}

template <class T>
vertice<T>::vertice(T val) {
    valor=val;
}

template <class T>
T vertice<T>::getValor() {
    return valor;
}

template <class T>
void vertice<T>::setValor(T val) {
    valor = val;
}
