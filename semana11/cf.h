// use ifndef define

#ifndef CF_H
#define CF_H

#include <iostream>
#include <thread>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

template <typename Iterator, typename T = typename Iterator::value_type>
void frequence(Iterator start, Iterator stop, map<T, size_t>& result){
    while (start != stop){
        result[*start]++;
        ++start;
    }
}



template <typename Iterator>
auto count_frequence(Iterator start, Iterator stop){
    // Variables auxiliares
    auto nh = thread::hardware_concurrency();
    auto sz = distance(start,stop);
    auto range = sz/nh;
    using T = typename Iterator::value_type;
    map<T, int> result;
    // Vector de hilos
    vector<thread> vh(nh);
    for (int i = 0; i < nh; ++i){
        // iteradores del hilos
        auto r_start = next(start, i*range);
        auto r_stop = i <= nh-1? next(start, (i+1)*range) : stop;
        // Asignar la tarea al hilo
        vh[i] = thread(frequence<Iterator>, r_start, r_stop, ref(result));
    }
    // Unir los hilos
    for (int i = 0; i < nh; ++i){
        vh[i].join();
    }
    return result;
}

template <typename KType, typename VType>
ostream& operator << (ostream& out, const map<KType, VType> mp){
    for (const auto& [k, v] :mp)
        out << k << ": " << v << endl;
    return out;
}



#endif // CF_H