#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm> // #include <numeric>
#include <iterator> // next, prev
#include <fstream> // ifstream, ofstream
using namespace std;

void ejemplo_array(){
    // Crear un arreglo
    // array arr = {10, 20, 30};
    array<int, 3> arr = {10, 20 ,30};
    int arr2[3] = {10, 20, 30};
    // Iterador de inicio
    auto it = arr.begin(); // Equivalente a un puntero
    // auto it2 = begin(arr2);

    cout << *it << endl;    // De referencia
    cout << it[2] << endl;  // Por sub-índice
    it = arr.end();
    cout << *it << endl; // No tiene sentido // ERROR
    auto rit = arr.rbegin();
    cout << *rit << endl; // Recorre del final



    array<int, 3>::iterator it2 = arr.begin();

    for (auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // Buscar un elemento
    auto find_iterator = find(begin(arr), end(arr), 40);
    if (find_iterator != end(arr)){
        cout << *find_iterator << endl;
    } else {
        cout << "No encontrado" << endl;
    }
}

template <typename Iterator>
void print(Iterator start, Iterator stop){
    while (start != stop) {
    // cout << *start++ << " ";
    cout << *start << " ";
    ++start;
  }
  cout << endl;
}

void ejemplo_deque(){
    deque<int> dq = {10, 20, 30, 40, 50};
    print(begin(dq), end(dq));
    // Insertar en cualquier posición
    dq.insert(begin(dq) +2, 25);
    print(begin(dq), end(dq));
    // Insertar al inicio
    dq.push_front(5);
    print(begin(dq), end(dq));
    // Insertar al final
    dq.push_back(60);
    print(begin(dq), end(dq));
    
    // Borrar
    dq.pop_back();
    print(begin(dq), end(dq));
    dq.pop_front();
    print(begin(dq), end(dq));
    dq.erase(begin(dq)+2);
    print(begin(dq), end(dq));
}

void ejemplo_lst(){
    list<int> lst = {10, 20, 30, 40, 50};
    print(begin(lst), end(lst));
    // Insertar en cualquier posición
    lst.insert(next(lst.begin(), 2), 25);
    print(begin(lst), end(lst));
    // Insertar al inicio
    lst.push_front(5);
    print(begin(lst), end(lst));
    // Insertar al final
    lst.push_back(60);
    print(begin(lst), end(lst));
    
    // Borrar
    lst.pop_back();
    print(begin(lst), end(lst));
    lst.pop_front();
    print(begin(lst), end(lst));
    lst.erase(next(lst.begin(),2));
    print(begin(lst), end(lst));
}

void print_cin(){
    auto it = istream_iterator<double>(cin);
    cout << "El valor del iterador: " << *it;
}

void print_out(){
    fstream file("archivo.txt");
    copy{
        istream_iterator<int>(file),
        istream_iterator<int>(),
        ostream_iterator<int>(cout, "|")
    };
}

int main(){
    // ejemplo_array();
    // ejemplo_deque();
    //ejemplo_lst();
    // print_cin();
    print_cout();
}