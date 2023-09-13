#include <iostream>

using namespace std;

template <typename ...TypePack>
void fun1(TypePack... param_pack){
    // cout << __PRETTY_FUNCTION__ << endl;
    //cout << param_pack[0] << endl;
}

// Condicion base
template <typename T>
T sumar(T a){
    return a;   
}

template <typename T, typename ...TypePack>
T sumar(T a,TypePack... param_pack){
    // cout << __PRETTY_FUNCTION__ << endl;
    return a + sumar(param_pack...);
}

// Fold Expression
template <typename ...TypePack>
auto sumar2(TypePack... pack){
    return(... + pack);
}

// Fold Expression
template <typename ...TypePack>
auto sumar3(TypePack... pack){
    return(pack + ...);
}

int main(){
    // fun1(1,2,3,4);
    // fun1("a","b","c");
    // fun1(1,2.0,5.3f);
    cout << sumar(10,20,30) << endl;
    cout << sumar2(10,20,30) << endl;
    cout << sumar3(10,20,30) << endl;
}   