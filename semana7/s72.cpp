#include <iostream>
#include <vector>

using namespace std;

bool is_even(int item){ return item % 2 ==0;}

void ejemplo_puntero_funcion(){
    bool (*ptr_fn)(int) = nullptr;
    ptr_fn = is_even;
    cout << boolalpha << is_even(3) << endl;
    cout << boolalpha << ptr_fn(3) << endl;
}

int sumar(int a, int b){
    return a + b;
}

int restar(int a, int b){
    return a - b;
}

int multiplicar(int a, int b){
    return a * b;
}
using function_type = int (*)(int, int);

using function_type_cnt = vector<int (*)(int, int)>;

int calculo_aritmetico(function_type_cnt& cnt_fns, int a, int b, function_type fn_total = sumar, int initial = 0){
    int total = initial;
    for (const auto& fn : cnt_fns){
        total = fn_total(total, fn(a,b));
    }
    return total;
}

void ejemplo_vector_puntero_funciones(){
    function_type_cnt v1;
    v1.push_back(sumar);
    v1.push_back(restar);
    v1.push_back(multiplicar);
    auto total = calculo_aritmetico(v1, 20, 30, multiplicar,1);
    cout << total << endl;
}

//int sumar(int a, int b){return a + b;}

void ejemplo_lambda_capture(){
    int x = 20;
    int y = 10;

    // Declaracion de lambda l-values (asignar un nombre)
    auto sumar2 = [=](int a, int b) {
        //x += 20;
        auto x1 = x;
        x1 += 20;
        return a + b + x1 + y;
    };
    cout << sumar(10,20) << endl;
    cout << sumar2(10,20) << endl;
    cout << x << endl;

    // Declaración r-value
    cout << [](int a, int b) {return a + b;};(10, 20)<< endl;

}

// Calculo aritmetico  con lambda
int calculo_aritmetico_lambda(function_type_cnt& cnt_fns, int a, int b, auto fn_total = [](int a, int b){return a + b;} , int initial = 0){
    int total = initial;
    for (const auto& fn : cnt_fns){
        total = fn_total(total, fn(a,b));
    }
    return total;
}

void ejemplo_vector_puntero_funciones(){
    function_type_cnt v1;
    v1.push_back(sumar);
    v1.push_back(restar);
    v1.push_back(multiplicar);
    auto total = calculo_aritmetico(v1, 20, 30, multiplicar,1);
    cout << total << endl;
}

int main(){
    //ejemplo_puntero_funcion();
    // ejemplo_vector_puntero_funciones();
    ejemplo_lambda_capture();
}