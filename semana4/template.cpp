#include <iostream>
#include <vector>
#include <array>
#include <deque>
using namespace std;

template <typename T>
T sumar (T a, T b) {
    return a + b;
}

/*
template<typename T, typename U>
auto sumar(T a, U b) -> decltype(a + b) {
    return a + b;
}
*/

// Parametro de template no tipo
template <int a, int b>
int sumar(){
    return a+b;
}

template <typename T>
T sumar (T a, T b) {
    return a + b;
}

// Sobrecarga por medio de función
char* sumar(const char* a, const char* b) {
}

// Sobrecarga por medio de otro template
template <typename T>
T* sumar(const T* a, const T* b){

}

void ejemplo_parametro_tipo() { 
    // Llamadas implicitar
    auto total1 = sumar(10, 20); // Deduce que T = int
    auto total2 = sumar(10.4, 20.3); // Deduce que T = double
    auto total3 = sumar(10.5f, 20.5f); // Deduce que T = float

    // Llamadas explicitas
    auto total4 = sumar<int>(10, 20.5);

    auto cadena1 = sumar("Hola ", "Mundo"); // Deduce T = const char*
}

/*
template <typename T, int sz>
int len(T (&arr)[sz]) {
    return sz;
}

T* begin(T (&arr)[sz]) {
    return &arr[0];
}

T* end(T (&arr)[sz]) {
    return &arr[sz];
}
*/


void ejemplo_parametro_no_tipo(){
    auto total = sumar<10, 20>();
    cout << total << endl;
}

/*
1ra regla: Solo se deducen parametros de template que se encuentren en la lista de parametros de la función
2da regla: Se deduce de derecha a izquierda (del ultimo al primero)
3ra regla: Se detiene si no se puede deducir y el resto no se deduce
    Si no se dedude se llama de forma explicita
*/


// Cabecera del template
template<
        typename T,
        template<typename ...> class SourceContainer,
        template<typename ...> class TargetContainer
    >
// Cabecera de la función
TargetContainer<T> filter2(SourceContainer<T> cnt, T value_filter){

}

template<
        template<class ...> class TargetContainer,
        typename T,
        template<typename ...> class SourceContainer
    >

//Cabecera de la función 
TargetContainer<T> filter(SourceContainer<T> cnt, T value_filter){

}

// Sobrecarga
template<typename T,
        template<typename ...> class SourceContainer>
// Cabecera de la función
SourceContainer<T> filter(SourceContainer<T> cnt, T value_filter){

}

// // Especializacion de Templates
// template<typename T,
//         template <typename ...> class SourceContainer>
// // Cabecera de la funcion
// SourceContainer<T> filter<SourceContainer, T, SourceContainer>(
//       SourceContainer<T> cnt, T value_filter) {
  
// }


int main() {
    //ejemplo_parametro_no_tipo();
    vector<int> v1 = {1, 2, 2, 3, 3, 2, 2};
    auto r1 = filter<deque>(v1,2);
    auto r2 = filter2<int, vector, deque>(v1,2)
    auto r3 = filter(v1,3)
}