#include <iostream>
#include <fstream>
#include "Grafo.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " archivo_entrada.txt\n";
        return 1;
    }

    // Crear un objeto Grafo
    Grafo<int, int> miGrafo;

    // Cargar datos desde el archivo de entrada
    std::ifstream archivoEntrada(argv[1]);
    if (!archivoEntrada.is_open()) {
        std::cerr << "No se pudo abrir el archivo de entrada.\n";
        return 1;
    }

    // Supongamos que el archivo de entrada tiene el formato correcto
    // y ya has implementado la lógica para cargar el grafo.
    // Aquí deberías agregar la lógica para cargar los vértices y aristas al grafo.

    // Resolver el problema y obtener la secuencia óptima de agujeros
    std::vector<std::vector<int>> ordenAgujeros = miGrafo.;

    // Generar un nombre de archivo de salida predefinido
    std::string nombreSalida = "salida_";
    nombreSalida += argv[1];  // Añadir el nombre de entrada al nombre de salida
    nombreSalida += ".txt";

    // Guardar la secuencia óptima en el archivo de salida
    std::ofstream archivoSalida(nombreSalida);
    if (!archivoSalida.is_open()) {
        std::cerr << "No se pudo abrir el archivo de salida.\n";
        return 1;
    }

    for (const std::vector<int>& circuito : ordenAgujeros) {
        for (const int& agujero : circuito) {
            archivoSalida << agujero << " ";
        }
        archivoSalida << "\n";
    }

    archivoSalida.close();

    // Mostrar información adicional en pantalla
    std::cout << "Cantidad de circuitos: " << ordenAgujeros.size() << "\n";
    for (const std::vector<int>& circuito : ordenAgujeros) {
        std::cout << "Cantidad de agujeros en el circuito: " << circuito.size() - 1 << "\n";
    }

    // Calcular y mostrar la distancia total recorrida por el taladro para cada circuito
    for (const std::vector<int>& circuito : ordenAgujeros) {
        int distanciaTotal = 0;
        for (size_t i = 0; i < circuito.size() - 1; ++i) {
            distanciaTotal += miGrafo.buscarArista(circuito[i], circuito[i + 1]);
        }
        std::cout << "Distancia total recorrida por el taladro: " << distanciaTotal << " mm\n";
    }

    return 0;
}
