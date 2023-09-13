#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
void function_1(T texto){
    cout << __PRETTY_FUNCTION__ << endl;
}

int main(){
    function_1(10);
    function_1("Hola");
    function_1(string("Hola"));
    const char* texto = "Texto";
    cout << texto << endl;
    cout << texto[2] << endl;
    // tamaño del texto
    // cout << sizeof(texto) << endl;
    char* texto2 = new char[6];
    // Copiar el contenido de texto a texto2
    strcpy(texto2, texto);
    cout << texto2 << endl;

}


