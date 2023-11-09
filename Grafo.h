#ifndef GRAFO_H
#define GRAFO_H
#include "Grafo.hxx"
#include "Vertice.h"
#include <vector>
#include <list>
#include <utility>

template <class T, class U>
class Grafo {
private:
    std::vector<T> vertices;
    std::vector<std::list<std::pair<int, U>>> aristas;

public:
    Grafo();
    void setVertices(std::vector<T> v);
    void setAristas(std::vector<std::list<std::pair<int, U>>> a);
    std::vector<T> getVertices();
    std::vector<std::list<std::pair<int, U>>> getAristas();
    int cantVertices() { return vertices.size(); }
    int cantAristas();
    int buscarVertice(T vert);
    bool insertarVertice(T vert);
    bool insertarArista(T ori, T des, U cos);
    U buscarArista(T ori, T des);
    bool eliminarVertice(T vert);
    bool eliminarArista(T ori, T des);
};

#endif // GRAFO_H
