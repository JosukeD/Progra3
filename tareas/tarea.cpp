// dos partes que contienen la declaración (.h) y definición (.cpp)
/*
Crear la función template sumarizar que permita sumar el contenido de un contenedor con valores numéricos, que incluya un parámetro que defina un valor inicial.

Caso:
// Contenedor 
std::list<double> lst = {10.5, 20.4, 30.2, 40.5, 50.9, 60.5};
cout << "Total: " << sumarizar(begin(lst), end(lst), 0) << endl;
// Calcular la mitad de valores inferior
auto last_it = next(begin(lst), size(lst) / 2);
cout << "Sumatoria de la mitad: " << sumarizar(begin(lst), last_it, 0) << endl;
.h declaras funciones en el .cpp defines la función
*/


// Hacer que el archivo cpp y el archivo .h funcionen con este main
// archivo tarea.cpp
#include <iostream>
#include <list>
using namespace std;

template <typename T>
T sumarizar(T begin, T end, T valor_inicial)
{
    T suma = valor_inicial;
    for (auto it = begin; it != end; ++it)
    {
        suma += *it;
    }
    return suma;
}

// archivo tarea.h
template <typename T>
T sumarizar(T begin, T end, T valor_inicial);

// archivo main.cpp
#include <iostream>
#include <list>

using namespace std;

int main()
{
    // Contenedor 
    std::list<double> lst = {10.5, 20.4, 30.2, 40.5, 50.9, 60.5};
    cout << "Total: " << sumarizar(begin(lst), end(lst), 0) << endl;
    // Calcular la mitad de valores inferior
    auto last_it = next(begin(lst), size(lst) / 2);
    cout << "Sumatoria de la mitad: " << sumarizar(begin(lst), last_it, 0) << endl;
    return 0;
}
