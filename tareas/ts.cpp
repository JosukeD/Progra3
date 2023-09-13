#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>

using namespace std;

/*
Crear la función template suma_producto del tipo variadic que permita tomar de 2 en 2 los parámetros de la función template, calcule el producto y que realice la suma de todos los productos. En caso la cantidad de valores variados sea impar el último valor será considerado en la suma.

Use Case #1:

    std::cout << suma_producto(1, 10, 3, 5) << endl; // El resultado seria: 25
Use Case #2:

    std::cout << suma_producto(1) << endl; // El resultado seria: 1
Use Case #3:

    std::cout << suma_producto(2, 10.5, 14.0, 1, 11.0) << endl; // El resultado seria: 46
Use Case #4:

    std::cout << suma_producto(-2, 0, 1, 0, 0) << endl; // El resultado seria: 0
*/

// Que pueda recibir doubles y tambien ints, y si recibe solo un valor x que el resultado sea x
#include <tuple>
#include <iostream>


template <typename T>
T suma_producto(T value) {
    return value;
}

template<typename T, typename... Args>
T suma_producto(T value, Args... args) {
    if constexpr(sizeof...(args) == 0) {
        return value;
    } else if constexpr(sizeof...(args) % 2 == 0) {
        return value * suma_producto(args...) + suma_producto(T{});
    } else  {
        T last_value = std::get<sizeof...(args) - 1>(std::make_tuple(args...));
        return value * suma_producto(args...) + last_value;
    }
}

int main()
{
    std::cout << suma_producto(1, 10, 3, 5) << endl; // El resultado seria: 25
    std::cout << suma_producto(1) << endl;           // El resultado seria: 1
    std::cout << suma_producto(2, 10.5, 14.0, 1, 11.0) << endl; // El resultado seria: 46
    std::cout << suma_producto(-2, 0, 1, 0, 0) << endl; // El resultado seria: 0
    return 0;
}

