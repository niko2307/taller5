#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "Grafo.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <archivo_entrada.txt> <archivo_salida.txt>" << std::endl;
        return 1;
    }

    std::ifstream archivoEntrada(argv[1]);

    if (!archivoEntrada) {
        std::cerr << "Error al abrir el archivo de entrada: " << argv[1] << std::endl;
        return 1;
    }

    int numCircuitos;
    archivoEntrada >> numCircuitos;

    std::vector<Grafo<int, int>> grafos;

    for (int i = 0; i < numCircuitos; ++i) {
        Grafo<int, int> grafo;

        int numAgujeros;
        archivoEntrada >> numAgujeros;

        for (int j = 0; j < numAgujeros; ++j) {
            int x, y;
            archivoEntrada >> x >> y;
            grafo.insertarVertice(x);
            grafo.insertarVertice(y);
            grafo.agregarAristaPesada(x, y, 0);
        }

        grafos.push_back(grafo);
    }

    std::cout << "Cantidad de circuitos: " << grafos.size() << std::endl;

    for (size_t i = 0; i < grafos.size(); ++i) {
        std::cout << "\nCircuito " << i + 1 << ":\n";
        std::cout << "Cantidad de agujeros: " << grafos[i].cantVertices() / 2 << std::endl;

        std::vector<std::vector<int>> ordenAgujeros = grafos[i].organizarAgujeros();
        double distanciaTotal = 0.0;

        for (size_t j = 0; j < ordenAgujeros.size() - 1; ++j) {
            double x1 = ordenAgujeros[j][0];
            double y1 = ordenAgujeros[j][1];
            double x2 = ordenAgujeros[j + 1][0];
            double y2 = ordenAgujeros[j + 1][1];

            // Calcular la distancia utilizando Dijkstra
            double distanciaDijkstra = grafos[i].dijkstra(x1)[grafos[i].buscarVertice(y2)];

            distanciaTotal += distanciaDijkstra;
        }

        std::cout << "Distancia total recorrida: " << distanciaTotal << " unidades\n";

    }
    archivoEntrada.close();
    std::ofstream archivoSalida(argv[2]);

    if (!archivoSalida) {
        std::cerr << "Error al abrir el archivo de salida: " << argv[2] << std::endl;
        return 1;
    }

    for (size_t i = 0; i < grafos.size(); ++i) {
        archivoSalida << "\nCircuito " << i + 1 << ":\n";
        archivoSalida << "Cantidad de agujeros: " << grafos[i].cantVertices() / 2 << std::endl;
        
        std::vector<std::vector<int>> ordenAgujeros = grafos[i].organizarAgujeros();
        double distanciaTotal = 0.0;

        for (size_t j = 0; j < ordenAgujeros.size() - 1; ++j) {
            double x1 = ordenAgujeros[j][0];
            double y1 = ordenAgujeros[j][1];
            double x2 = ordenAgujeros[j + 1][0];
            double y2 = ordenAgujeros[j + 1][1];

            // Calcular la distancia utilizando Dijkstra
            double distanciaDijkstra = grafos[i].dijkstra(x1)[grafos[i].buscarVertice(y2)];

            distanciaTotal += distanciaDijkstra;
        }

        archivoSalida << "Distancia total recorrida: " << distanciaTotal << " unidades\n";
    }
    archivoSalida.close();
    std::cout << "Datos guardados en " << argv[2] << std::endl;
  
  
return 0;
}