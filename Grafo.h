
#ifndef GRAFO_H
#define GRAFO_H
#include <string>
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
    void insertarVertice(T vert);
    void setAristas(std::vector<std::list<std::pair<int, U>>> a);
    std::vector<T> getVertices();
    std::vector<std::list<std::pair<int, U>>> getAristas();
    int cantVertices();
    int cantAristas();
    int buscarVertice(T vert);
    U buscarArista(T ori, T des);
    bool eliminarVertice(T vert);
    bool eliminarArista(T ori, T des);
    std::vector<U>dijkstra(T inicio);
    T extraerCoordenada(std::string& coordenada);
    void agregarArista(int u, int v);
    void agregarAristaPesada(T ori, T des, U cos);
    std::vector<std::vector<int>> organizarAgujeros();
  
};
#include "Grafo.hxx"
#endif // GRAFO_H
