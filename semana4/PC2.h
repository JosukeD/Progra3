/*
TEMPLATE DE FUNCIONES Y LIBRERIA ESTANDAR

Escribir la función de template get_maximum_product_range que reciba como parámetro un contenedor genérico y que genere un contenedor con los elementos que produzcan el máximo producto que se puede obtener de multiplicar elementos del contenedor.

La función debe retornar un contenedor, que por default será std::vector, pero que podría ser personalizado.

Use Case #1:
std::list<int> lst1 = {3, 3, -3, 5, 4, -4, 0, -4, -4, -5};
std::deque f1 = get_maximum_product_range<std::deque>(lst1);
for (const auto& row: f1) {
	for(const auto& value: row)
		std::cout << value << " ";
	std::cout << std::endl;
}

/*
 Se imprimirá:
    3 3 5 4 -4 -4 -4 -5


Use Case #2:
std::forward_list<int> flst1 = {1, 2, -3, 0, 0, -3, -2, 5, -1, -5};
std::vector f1 = get_maximum_product_range(flst1); // En este caso sera vector
for (auto row: f1) {
	for(auto value: row)
		std::cout << value << " ";
	std::cout << std::endl;
}
/*
 Se imprimirá:
    1 2 -3 -3 -2 5 -5
*/


// Recordar que el archivo fuente sera el cpp y el archivo de cabecera sera el h

// archivo de cabecera

#ifndef GET_MAXIMUM_PRODUCT_RANGE_H
#define GET_MAXIMUM_PRODUCT_RANGE_H

#include <iostream>
#include <vector>
#include <algorithm>


// utilizar vector
namespace utec{
template <typename T>
T get_maximum_product_range(T v1){
    T v2;
    int max = 0;
    int aux = 1;
    for(auto i = v1.begin(); i != v1.end(); i++){
        if(*i == 0){
            aux = 1;
            continue;
        }
        aux *= *i;
        if(aux > max){
            max = aux;
            v2.clear();
            v2.push_back(*i);
        }
        else if(aux == max){
            v2.push_back(*i);
        }
    }
    return v2;
}

// utilizar deque

template <typename T>

T get_maximum_product_range(std::deque<T> v1){
    T v2;
    int max = 0;
    int aux = 1;
    for(auto i = v1.begin(); i != v1.end(); i++){
        if(*i == 0){
            aux = 1;
            continue;
        }
        aux *= *i;
        if(aux > max){
            max = aux;
            v2.clear();
            v2.push_back(*i);
        }
        else if(aux == max){
            v2.push_back(*i);
        }
    }
    return v2;
}

// utilizar forward_list

template <typename T>

T get_maximum_product_range(std::forward_list<T> v1){
    T v2;
    int max = 0;
    int aux = 1;
    for(auto i = v1.begin(); i != v1.end(); i++){
        if(*i == 0){
            aux = 1;
            continue;
        }
        aux *= *i;
        if(aux > max){
            max = aux;
            v2.clear();
            v2.push_back(*i);
        }
        else if(aux == max){
            v2.push_back(*i);
        }
    }
    return v2;
}
}

#endif

// archivo fuente

// #include "get_maximum_product_range.h"

using namespace std;

int main(){
    std::list<int> lst1 = {3, 3, -3, 5, 4, -4, 0, -4, -4, -5};
    std::deque<int> f1 = get_maximum_product_range<std::deque<int>>(lst1);
    for (const auto& row: f1) {
        std::cout << row << " ";
    }
    std::cout << std::endl;
    std::forward_list<int> flst1 = {1, 2, -3, 0, 0, -3, -2, 5, -1, -5};
    std::vector<int> f2 = get_maximum_product_range(flst1); // En este caso sera vector
    for (auto row: f2) {
        std::cout << row << " ";
    }
    std::cout << std::endl;
    return 0;
}
