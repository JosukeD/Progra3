/*
Cada pregunta deberá ser respondida en un archivo fuente (.cpp) y un archivo cabecera (.h) con el número de la pregunta:

Pregunta 1 : template de función

Crear un template de función generate_matrix que tenga adicionalmente 2 parámetros no-tipo que representen el número de filas (r) y columnas (c) y que cuente con un parámetro de función del tipo vector, deque con valores numéricos. La función generará una matriz de tamaño r x c que sera un contenedor de contenedores del tipo similar al contenedor original, si el parámetro de función tiene una cantidad menor de valores que el tamaño de la matriz el resto debe ser llenado con ceros (0), si es mayor el resto de valores sera descartado.

Caso 1:
vector v1 = {1, 2, 3, 4};
auto m1 = generate_matrix<3, 2>(v1);
for (auto row: m1) {
    for (auto item: row)
        cout << setw(3) << item;
    cout << endl;
    }
/* Resultado:
1  2  
3  4
0  0

Caso 2:deque d1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
deque m1 = generate_matrix<3, 3>(d1);
for (auto row: m1) {
    for (auto item: row)
        cout << setw(3) << item;
    cout << endl;
}
/* Resultado:
1  2  3
4  5  6
7  8  9
*/

// en el .h solo las declaraciones

// en el .cpp solo las definiciones

// generate_matrix funciona para vector y deque y recibe <r,c>(vector)
// que sea separado para vector y deque
// usar: string stream y size_T
// que no sea fijo el valor y que pueda ser o vector o deque
// que sea un template de funcion

// que funcione como // generate_matrix<3, 2>(v1);
// que sea un template de funcion
// que sea separado para vector y deque

// .h
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <sstream>
#include <string>

using namespace std;

template <size_t r, size_t c>
auto generate_matrix(T &v1) {
    vector<vector<int>> m1;
    int i = 0;
    for (int j = 0; j < r; j++) {
        vector<int> row;
        for (int k = 0; k < c; k++) {
            if (i < v1.size()) {
                row.push_back(v1[i]);
                i++;
            } else {
                row.push_back(0);
            }
        }
        m1.push_back(row);
    }
    return m1;
}


int main() {
    vector<int> v1 = {1, 2, 3, 4};
    auto m1 = generate_matrix< 3, 2>(v1);
    for (auto row: m1) {
        for (auto item: row)
            cout << setw(3) << item;
        cout << endl;
    }
    cout << endl;

    deque<int> d1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto m2 = generate_matrix<3, 3>(d1);
    for (auto row: m2) {
        for (auto item: row)
            cout << setw(3) << item;
        cout << endl;
    }
    cout << endl;

    return 0;
}

