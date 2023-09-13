#include <iostream>
#include <vector>
#include <deque>

using namespace std;


template<typename IterSource, typename IterTarget>
void copiar(IterSource start, IterSource stop, IterTarget dest){
    for (const auto& item: cnt){
        out << item << " ";
    }
    return out;
}

template<typename T, template<typename ...> class Container>
ostream operator<<(ostream& os, const Container<T>& cnt){
    for(const auto& x : cnt;){
        os << x << " ";
    }
    return os;
}

template<typename Iter>
auto promediar(Iter start, Iter stop){
    auto sum = 0.0;
    auto n = 0;
    for (auto p = start; p != stop; ++p){
        sum += *p;
        ++n;
    }
    return sum / n;
}

template<typename IterSource, typename IterTarget, typename UnaryPredicate>
void copiar_if(IterSource start, IterSource stop, IterTarget dest, UnaryPredicate p){
    while(start != stop){
        if (p(*start)){
            *dest = *start;
            ++dest;
        }
        ++start;
    }
}
    

void ejemplo_1(){
    vector<int> v1 = {10, 20, 30, 40, 50};
    vector<int> v2(size(v1));
    copiar(begin(v1), end(v1), begin(v2));
    cout << v2 << endl;
    vector<int> v3(size(v1));
    copy (begin(v1), end(v1), begin(v3));
    cout << v3 << endl;
    auto p1 = promediar(begin(v1), end(v1));
}

int main(){
    ejemplo_1();
}