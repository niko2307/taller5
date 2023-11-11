#include <iostream>
#include <fstream>
#include "Grafo.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " archivo_entrada.txt archivo_salida.txt\n";
        return 1;
    }

    // Crear un objeto Grafo
    Grafo<int,int>miGrafo;

    // Cargar datos desde el archivo de entrada
    std::ifstream archivoEntrada(argv[1]);
    if (!archivoEntrada.is_open()) {
        std::cerr << "No se pudo abrir el archivo de entrada.\n";
        return 1;
    }

    // Cargar el grafo desde el archivo según el nuevo formato
    miGrafo.cargarGrafoDesdeArchivo(archivoEntrada);

    // Resolver el problema y obtener la secuencia óptima de agujeros
    std::vector<std::vector<int>> ordenAgujeros = miGrafo.organizarAgujeros();

    // Generar un nombre de archivo de salida predefinido
    std::ofstream archivoSalida(argv[2]);
    if (!archivoSalida.is_open()) {
        std::cerr << "No se pudo abrir el archivo de salida.\n";
        return 1;
    }
    // Guardar la secuencia óptima en el archivo de salida
    for (const std::vector<int>& circuito : ordenAgujeros) {
        for (const int& agujero : circuito) {
            archivoSalida << agujero << " ";
        }
        archivoSalida << "\n";
    }

    archivoSalida.close();

    // Mostrar información adicional en pantalla
    std::cout << "Cantidad de circuitos en el archivo: " << ordenAgujeros.size() << "\n";
    for (const std::vector<int>& circuito : ordenAgujeros) {
        std::cout << "Cantidad de agujeros en el circuito: " << circuito.size() - 1 << "\n";
    }

    // Calcular y mostrar la distancia total recorrida por el taladro para cada circuito
    for (const std::vector<int>& circuito : ordenAgujeros) {
        std::cout << "Circuito: ";
        for (const int& agujero : circuito) {
            std::cout << agujero << " ";
        }

        std::vector<int> distanciaTotal = miGrafo.dijkstra(circuito[0]);
        std::cout << "\nDistancia total recorrida por el taladro: " << distanciaTotal[circuito.back()] << " mm\n";
    }

    return 0;
}
