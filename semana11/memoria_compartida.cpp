#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex> // 1. Incluir la libreria
#include <algorithm>
#include <map>
#include "cf.h"
using namespace std;

mutex mtx; // 2. Crear una variable global (Cerrojo de una puerta)

class guardia {
    mutex &_mtx;
public:
    guardia(mutex &mtx) : _mtx(mtx) {
        _mtx.lock();
    }

    ~guardia() {
        _mtx.unlock();
    }
};

void incrementar(int &value) {
    this_thread::sleep_for(std::chrono::milliseconds(10));
    //guardia g(mtx); // esto hace que el hilo espere hasta que el otro hilo termine de usar la variable

    unique_lock ul(mtx); // esto hace que el hilo espere hasta que el otro hilo termine de usar la variable

    //mtx.lock();
    // 3.
    value++;
    ul.unlock();
    ul.lock();
    value++;
    //mtx.unlock(); // esto hace que el hilo libere la variable para que otro hilo pueda usarla
}


void calcular_total_variable_compartida() {
    int nh = 130;
    int nr = 100;
    for (int i = 0; i < nr; ++i) {
        int rep = 100;
        int x = 0;
        // Creando los hilos
        vector<thread> vh(nh);
        // Asignarle la tarea a los hilos
        for (auto &h: vh)
            h = thread(incrementar, ref(x));
        // Usar los hilos
        for (auto &h: vh)
            h.join();
        cout << x << " ";
    }
}
void ejemplo_contar_frecuencia(){
    vector v = {1,2,3,4,5,6,7,8,9,10};
    auto r = count_frequence(begin(v), end(v));
    cout << r << endl;
}

int main() {
    calcular_total_variable_compartida();
    ejemplo_contar_frecuencia();
}