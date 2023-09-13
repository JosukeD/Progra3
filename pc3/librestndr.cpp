/*
Diseñar y desarrollar el template de función join_containers que permita unir
varios contenedores (en una cantidad variada de contenedores) y que genere un
contener que por default sea vector.
Los contenedores podrian ser: list, vector, std::deque, std::forward_list

Si se tiene los siguientes containers :
list lst = {1, 2, 3, 4, 5}
vector vec = {6, 7, 8, 9, 10, 11, 12}
deque deq = {13, 14}
Y si se llama:
result = join_containers(lst, vec, deq)
result contendria:
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
*/

/*
Casos de  uso donde tiene que correr sin errores:
Caso 1:
vector 

*/

#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <deque>












int main(){
    vector v1 = {1, 2, 3};
    vector v2 = {4, 5, 6};
}