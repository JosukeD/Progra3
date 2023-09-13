#include <iostream>
#include <string>
using namespace std;

class Singleton{
    string data;
    inline static Singleton* unique_instance {};
    explicit Singleton(string d): data(std::move(d)) {} // Reemplazar el constructor
public:
    static Singleton* get_instance(const string&  d){
        if (unique_instance == nullptr)
            unique_instance = new Singleton(d);
        return unique_instance;
    }
    string get_data() {return data;}
};

void ejemplo_singleton(){
    auto s1 = Singleton::get_instance("data1");
    auto s2 = Singleton::get_instance("data2");
    cout << s1.get_data() << endl;
    cout << s2.get_data() << endl;
}