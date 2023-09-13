#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string text, char delimiter){
    stringstream ss(text);
    vector<string> result;
    string token;
    while (std::getline(ss, token, delimiter))
        result.emplace_back(token);
    return result;
}

void lectura_archivo(string file_name){
    // Abrir el archivo
    ifstream file(file_name);
    // Validando la apertura
    if (!file.is_open())
        throw runtime_error("Error de aperutura de archivo");


string line;
getline(file,line);
cout << line << endl;

auto tokens = split(line, '|');

if(tokens.front() != "Tuit")
    throw runtime_error("Error primer token no es Tuit");

for (const auto& tk:tokens)
    cout << tk << endl;
    
}   

int main(){
    //lectura_archivo("archivo.txt");
    // Captura de error
    try{
        lectura_archivo("archivo.txt");
    }catch (runtime_error error){
        cout << "Error capturado: " << error.what() << endl;
    }
}