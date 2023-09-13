#include <iostream>
#include <deque>
#include <vector>
using namespace std;

template<typename IterIn, typename IterOut> //cada contenedor tiene su propio iterador
void copiar(IterIn start, IterIn stop, IterOut dest, Callable caller){
    while(start != stop){
        if(caller(*start)){
            *dest = *start;
            advance(dest, 1);
        }
        *dest = *start;
        advance(start, 1);//podemos hacerlo más genérico con std::advance o std::next
        //start=next(start);
    }



}
//sobrecargamos un template
// funciones parciales, funciones objetos, lambda
template<typename T,template <class...> class Container>
        ostream& operator<<(ostream& out, const Container<T> cnt){
            for(const auto& elem: cnt){
                out << elem << " ";
            }
            return out;
        }

bool is_odd(auto item){
    return fmod(item_2) == 0;
}   

void ejemplo_callable(){
    vector<double> v1 = {1,2,3,4,5};
    deque<double> v2;
    copiar(v1.begin(), v1.end(), begin(v2),is_odd);
}


//----
template<typename Iter>
auto sumar(Iter start, Iter stop, typename Iter::value_type init){
    while(start != stop){
        init += *start;
        advance(start, 1);
    }
    return init;
}

template<typename T, size_t U>
auto sumar(T (&arr)[U], T init){
    for(auto& elem: arr){
        init += elem;
    }
    return init;
}



int main(){
    vector<int> v1={10, 20, 30};
    
    int arr[]={10, 20, 30};
    
    //vector<int> v2;
    //copiar(v1.begin(), v1.end(), back_inserter(v2));
    //cout << v2 << endl;

    // Suma de elementos del vector con una función suma
    auto total = sumar(begin(v1), end(v1), 0);
    cout << total << endl; 
    auto total2 = sumar(arr, 0);
    cout << total2 << endl;
}