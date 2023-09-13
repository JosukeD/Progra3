#include <iostream>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

// stack, que son adaptadores de deque por deafult
// priority_que es adaptador del vector por default

void ejemplo_pq1(){
    vector<int> v = {1,2,3,4};
    // priority_queue<int> q(std::move(v));
    priority_queue q(less<int>(), std::move(v)); // Copy constructor
    cout << size(v) <<endl;
    priority_queue q2(begin(v1), end(v1)); // Copy constructor
    cout << size(v1) <<endl;

    priority_queue<int, vector<int>, less<>> q3(less<>(), std::move(v1));
}

void ejemplo_pq2(){
    vector<int>  v = {4, 2, 1,3};
    priority_queue q(less<int>(), std::move(v));

    while(!q.empty()){
        cout << q.top() << " "; 
        q.pop();
    }

    vector v2 = {4, 2, 1,3};
    priority_queue q2(greater<int>(), std::move(v2));
    while (!q2.empty()){
        cout << q2.top() << " ";
        q2.pop();
    }
}

class Persona{
    string nombre;
    string apellido;
    bool operator>(const Persona& p) const{
        return nombre > other.nombre;
    }
    bool operator<(const Persona& p) const{
        return nombre > other.nombre;
    }
};

void ejemplo_pq3(){
    vector v ={ Persona{"Ana", "Zapata"},
                Persona{"Juan", "Perez"},
                Persona{"Maria", "Gomez"},
                Persona{"Pedro", "Gonzales"}
            };
    priority_queue q(less<>(),move(v));
    while (!q.empty()){
        cout << q.top().nombre << " " << q.top().apellido << endl;
        q.pop();
    }
}

void ejemplo_pq4(){
    vector v ={ Persona{"Ana", "Zapata"},
                Persona{"Juan", "Perez"},
                Persona{"Maria", "Gomez"},
                Persona{"Pedro", "Gonzales"}
            };
    auto compare_less_apellido = [](auto a, auto b){return a.apellido > b.apellido;};
    auto compare_less_apellido = [](auto a, auto b){return a.apellido > b.apellido;};
    priority_queue q(less<>(),move(v));
    while (!q.empty()){
        cout << q.top().nombre << " " << q.top().apellido << endl;
        q.pop();
    }
}