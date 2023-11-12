
#ifndef GRAFO_H
#define GRAFO_H
#include <string>
#include "Vertice.h"
#include <vector>
#include <list>
#include <utility>
template <class T, class U>
class Grafo
{
private:
    std::vector<T> vertices;
    std::vector<std::list<std::pair<int, U>>> aristas;

public:
    Grafo();
    void setVertices(std::vector<T> v);
    void setAristas(std::vector<std::list<std::pair<int, U>>> a);
    void insertarVertice(T vert);
    std::vector<T> getVertices()const;
    std::vector<std::list<std::pair<int, U>>> getAristas();
    void redimensionarAristas();
    int cantVertices();
    int cantAristas();
    int buscarVertice(T vert);
    U buscarArista(T ori, T des);
    bool eliminarVertice(T vert);
    bool eliminarArista(T ori, T des);
    std::vector<U> dijkstra(T inicio);
    T extraerCoordenada(std::string &coordenada);
    void agregarArista(int u, int v);
    void agregarAristaPesada(int ori, int des, U cos);
    std::vector<std::vector<int>> organizarAgujeros();
};



#endif // GRAFO_H
