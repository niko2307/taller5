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
    U buscarArista(T ori, T des);
    bool eliminarVertice(T vert);
    bool eliminarArista(T ori, T des);
    std::vector<U> Grafo<T, U>::dijkstra(T inicio);
    T Grafo<T, U>::extraerCoordenada( std::string& coordenada);
    void Grafo<T, U>::agregarArista(int u, int v, int peso);
    void Grafo<T, U>::agregarAristaPesada(T ori, T des, U cos);
    std::vector<T> Grafo<T, U>::organizarAgujeros();
    void Grafo<T, U>::cargarGrafoDesdeArchivo(std::ifstream& archivo);

};

#endif // GRAFO_H
