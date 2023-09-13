#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
using namespace std;

void sumar_rango(vector<int>& vdatos, int& resultado, int start, int stop){
    for(int i = start; i < stop; ++i){
        resultado += vdatos[i];
    }
}

void sumatoria_vector(){
    int nhilos = 4;
    vector<int> v1 = {1,7,8,20,3,-5,4,2,10,11,20,21};
    cout << accumulate(begin(v1), end(v1), 0) << endl;  
    // Resultados
    vector<int> resultado(nhilos);
    // Hilos
    vector<thread> vhilos;
    int rango = v1.size()/nhilos;

    // para asignar la tarea a cada hilo
    for (int j = 0; j < vhilos.size(); ++j){
        vhilos[j] = (thread(sumar_rango, ref(v1), ref(resultado[j]), j*rango, (j+1)*rango));
    }

    // join
    for (int j = 0; j < vhilos.size(); ++j){
        vhilos[j].join();
    }

    auto total = accumulate(begin(resultado), end(resultado), 0);
    cout << "Total: " << total << endl;

}

//======================================================================ITERADORES=====================================================


template <typename Iterator>
void sumar_rango_iteradores(int& resultado, Iterator start, Iterator stop){
    resultado = accumulate(start, stop, 0);
}
void sumatoria_vector_iteradores(){
    int nhilos = 4;
    vector<int> v1 = {1,7,8,20,3,-5,4,2,10,11,20,21};
    cout << accumulate(begin(v1), end(v1), 0) << endl;  
    // Resultados
    vector<int> resultado(nhilos);
    // Hilos
    vector<thread> vhilos;
    int rango = v1.size()/nhilos;

    // Crear lambda
    auto res_lambda = [j,&resultado, &v1, rango](){
        sumar_rango_iteradores(
            resultado[j];
            next(begin(v1),j*rango),
            next(begin(v1),(j+1)*rango)
        );
    }; 


    for (int j = 0; j < vhilos.size(); ++j){
        vhilos[j] = thread{
            [j,&resultado, &v1, rango]()(
                sumar_rango_iteradores( resultado[j], next(begin(v1),j*rango), next(begin(v1),(j+1)*rango)
            );
        });
    }

    // join
    for (int j = 0; j < vhilos.size(); ++j){
        vhilos[j].join();
    }

    auto total = accumulate(begin(resultado), end(resultado), 0);
    cout << "Total: " << total << endl;
}

int main(){
    sumatoria_vector();
    return 0;
}

