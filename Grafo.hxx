
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>
#include "Grafo.h"

template <class T, class U>
Grafo<T , U>::Grafo() {

}
template <class T, class U>
void Grafo<T , U>::setVertices(std::vector<T> v) {
    vertices = v;
}

template <class T, class U>
void Grafo<T , U>::setAristas(std::vector<std::list<std::pair<int, U>>> a) {
    aristas = a;
}

template <class T, class U>
std::vector<T> Grafo<T , U>::getVertices() {
    return vertices;
}

template <class T, class U>
std::vector<std::list<std::pair<int, U>>> Grafo<T, U>::getAristas() {
    return aristas;
}

template <class T, class U>
int Grafo<T, U>::buscarVertice(T vert) {
    int ind = -1;
    for (int i = 0; i < cantVertices(); i++) {
        if (vertices[i] == vert) ind = i;
    }
    return ind;
}

template <class T, class U>
U Grafo<T , U>::buscarArista(T ori, T des) {
    U res = -1;
    int i_ori = buscarVertice(ori);
    int i_des = buscarVertice(des);
    if (i_ori != -1 && i_des != -1) {
       typename std::list<std::pair<int, U>>::iterator itList = aristas[i_ori].begin();
        for (; itList != aristas[i_ori].end(); itList++) {
            if (itList->first == i_des) res = itList->second;
        }
    }
    return res;
}

template <class T, class U>
bool Grafo<T, U>::eliminarVertice(T vert) {
    bool res = false;
    int i_vert = buscarVertice(vert);
    if (i_vert != -1) {
       typename std::vector<std::list<std::pair<int, U>>>::iterator posE = aristas.begin() + i_vert;
        aristas.erase(posE);
        vertices.erase(vertices.begin() + i_vert);
        res = true;
    }
    return res;
}


template <class T, class U>
int Grafo<T, U>::cantVertices() {
    return vertices.size();
}

template <class T, class U>
void Grafo<T, U>::insertarVertice(T vert) {
    vertices.push_back(vert);
}

template <class T, class U>
std::vector<U> Grafo<T, U>::dijkstra(T inicio) {
    int numVertices = vertices.size();
    std::vector<U> distancia(numVertices, INT_MAX);
    int indiceInicio = buscarVertice(inicio);
    if (indiceInicio == -1) {
      
        return distancia;
    }
    distancia[indiceInicio] = 0;
    std::priority_queue<std::pair<U , int>, std::vector<std::pair<U , int>>, std::greater<std::pair<U, int>>> pq;
    pq.push({0, indiceInicio});

    while (!pq.empty()) {
        int u = pq.top().second;
        U distanciaU = pq.top().first;
        pq.pop();

        for ( std::pair<int, U>& vecino : aristas[u]) {
            int v = vecino.first;
            U pesoUV = vecino.second;
            if (distanciaU + pesoUV < distancia[v]) {
                distancia[v] = distanciaU + pesoUV;
                pq.push({distancia[v], v});
            }
        }
    }
    return distancia;
}
template <class T, class U>
T Grafo<T , U>::extraerCoordenada( std::string& coordenada) {
    size_t pos = coordenada.find('|');
    if (pos != std::string::npos) {
        return static_cast<T>(std::stoi(coordenada.substr(pos + 1)));
    }
    return static_cast<T>(std::stoi(coordenada));
}
template <class T, class U>
void Grafo<T , U>::agregarArista(int u, int v) {
    aristas[u].emplace_back(v);
    aristas[v].emplace_back(u); 
}

template <class T, class U>
void Grafo<T, U>::agregarAristaPesada(T ori, T des, U cos) {
    int i_ori = buscarVertice(ori);
    int i_des = buscarVertice(des);
    if (i_ori != -1 && i_des != -1) {
        aristas[i_ori].emplace_back(i_des, cos);
    }
}
template <class T, class U>
std::vector<std::vector<int>> Grafo<T, U>::organizarAgujeros() {
    std::vector<std::vector<int>> ordenAgujeros;

    for (int i = 0; i < cantVertices(); ++i) {
        std::vector<T> ordenCircuito;
        ordenCircuito.push_back(vertices[i]);

        std::vector<U> distancias = dijkstra(vertices[i]);

        // Ordenar los agujeros del circuito según las distancias mínimas
        std::vector<std::pair<U, T>> distanciasAgujeros;
        for (int j = 0; j < cantVertices(); ++j) {
            if (j != i) {
                distanciasAgujeros.emplace_back(distancias[j], vertices[j]);
            }
        }

        // Ordenar según las distancias mínimas utilizando Dijkstra
        std::sort(distanciasAgujeros.begin(), distanciasAgujeros.end(),
                  [](const std::pair<U, T>& a, const std::pair<U, T>& b) {
                      return a.first < b.first;
                  });

        for (const std::pair<U, T>& par : distanciasAgujeros) {
            ordenCircuito.push_back(par.second);
        }

        ordenAgujeros.push_back(ordenCircuito);
    }
    return ordenAgujeros;
}


