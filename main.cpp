#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Grafo.hxx"

struct Punto
{
    float X, Y;
    float distanciaA(const Punto &b) const
    {
        float x = X - b.X;
        float y = Y - b.Y;
        return (std::sqrt((x * x) + (y * y)));
    }
    const bool operator==(const Punto &other)
    {
        return (this->X == other.X && this->Y == other.Y);
    }
};

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Uso: " << argv[0] << " <archivo_entrada.txt> <archivo_salida.txt>" << std::endl;
        return 1;
    }

    std::ifstream archivoEntrada(argv[1]);

    if (!archivoEntrada)
    {
        std::cerr << "Error al abrir el archivo de entrada: " << argv[1] << std::endl;
        return 1;
    }

    int numCircuitos;
    archivoEntrada >> numCircuitos;

    std::vector<Grafo<Punto, float>> grafos;
    Punto puntoTemporal;

    // Abrir el archivo de salida una vez antes del bucle de circuitos
    std::ofstream archivoSalida(argv[2]);

    if (!archivoSalida)
    {
        std::cerr << "Error al abrir el archivo de salida: " << argv[2] << std::endl;
        return 1;
    }

    for (int i = 0; i < numCircuitos; ++i)
    {
        Grafo<Punto, float> grafo;
        int numAgujeros;
        archivoEntrada >> numAgujeros;
        for (int j = 0; j < numAgujeros; ++j)
        {
            float x, y;
            archivoEntrada >> x >> y;
            puntoTemporal.X = x;
            puntoTemporal.Y = y;
            grafo.insertarVertice(puntoTemporal);
        }

        grafo.redimensionarAristas();
        for (int i = 0; i < grafo.getVertices().size(); i++)
        {
            for (int j = 0; j < grafo.getVertices().size(); j++)
            {
                Punto puntoTemp1 = grafo.getVertices()[i];
                Punto puntoTemp2 = grafo.getVertices()[j];
                if (puntoTemp1 == puntoTemp2)
                {
                }
                else
                {
                    float distancia = grafo.getVertices()[i].distanciaA(grafo.getVertices()[j]);
                    grafo.agregarAristaPesada(i, j, distancia);
                }
            }
        }

        grafos.push_back(grafo);

        // Obtener las distancias después de aplicar Dijkstra
        std::vector<float> distancias = grafo.dijkstra(grafo.getVertices()[0]);

        // Ordenar los vértices según las distancias
        std::vector<std::pair<float, size_t>> distanciasConIndice;
        for (size_t j = 0; j < distancias.size(); ++j)
        {
            distanciasConIndice.push_back({distancias[j], j});
        }

        std::sort(distanciasConIndice.begin(), distanciasConIndice.end(), [](const std::pair<float, size_t> &a, const std::pair<float, size_t> &b) {
            return a.first < b.first;
        });

        // Imprimir en pantalla
        std::cout << "\nCircuito " << i + 1 << ":\n";
        std::cout << "Cantidad de agujeros: " << numAgujeros << std::endl;

        float distanciaTotal = 0.0;

        for (size_t j = 0; j < distanciasConIndice.size(); ++j)
        {
            size_t indiceOrdenado = distanciasConIndice[j].second;
            std::cout << "Distancia al agujero " << indiceOrdenado + 1 << ": " << std::fixed << std::setprecision(1) << distancias[distanciasConIndice[j].second] << " unidades" << std::endl;
            // Sumar las distancias al calcular la distancia total
            distanciaTotal += distancias[distanciasConIndice[j].second];
        }

        std::cout << "Distancia total recorrida: " << std::fixed << std::setprecision(1) << distanciaTotal << " unidades\n";

        // Escribir en el archivo de salida
        archivoSalida << "\nCircuito " << i + 1 << ":\n";
        archivoSalida << "Cantidad de agujeros: " << numAgujeros << std::endl;

        for (size_t j = 0; j < distanciasConIndice.size(); ++j)
        {
            size_t indiceOrdenado = distanciasConIndice[j].second;
            archivoSalida << std::fixed << std::setprecision(1) << grafos[i].getVertices()[indiceOrdenado].X << "|" << grafos[i].getVertices()[indiceOrdenado].Y << std::endl;
        }

        archivoSalida << "Distancia total recorrida: " << std::fixed << std::setprecision(1) << distanciaTotal << " unidades\n";
    }

    archivoSalida.close();

    archivoEntrada.close();

    std::cout << "Datos guardados en " << argv[2] << std::endl;

    return 0;
}
