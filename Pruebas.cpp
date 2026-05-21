#include <iostream>
#include <random>
#include <chrono> // Nueva librería necesaria para medir el tiempo

int main() {
    // 1. Obtener los microsegundos actuales del reloj del sistema
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    // 2. Inicializar el motor usando esa semilla temporal
    std::mt19937 gen(seed);

    // 3. Definir la distribución (rango de 1 a 100)
    std::uniform_int_distribution<int> distr(1, 100);

    // 4. Declarar y asignar las variables aleatorias
    int var1 = distr(gen);
    int var2 = distr(gen);

    std::cout << "Variable 1: " << var1 << std::endl;
    std::cout << "Variable 2: " << var2 << std::endl;

    return 0;
}

