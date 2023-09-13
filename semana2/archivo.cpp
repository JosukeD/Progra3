#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;
int main(){
    ofstream file("archivo.txt");
    file << "Hola mundo" << endl;
}
if (file.is_open()){
    file << "Hola mundo" << endl;
    file.close();
}
else {
    cout << "No se pudo abrir el archivo" << endl;
}