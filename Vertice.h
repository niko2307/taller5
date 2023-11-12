
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


#endif // VERTICE_H
