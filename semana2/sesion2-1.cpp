#include <iostream>
using namespace std;

/*
struct Estatica{
    int Estatica::x = 0;
    int Estatica::y = 0;
    
    //inline static int x = 0;
    //inline static int y = 0;
};
// Estatica::x = 0
// Estatica::y = 0

void ejemplo_estatico(){
    Estatica::x = 10;
    cout << Estatica::x << endl;
    Estatica obj_e;
    cout << obj_e.x << endl;
}
*/
class Point {
    int x = 0;
    int y = 0;
public:
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
    int get_x() const { return x;}
    int get_y() const { return y;}
    void set_x(int value) { x = value;}
    void set_y(int value) { y = value;}
};

void ejemplo_objetos_constantes(){
    Point p1;
    p1.set_x(10);
    p1.set_y(20);
    cout << p1.get_x() << " " << p1.get_y() << endl;

    const Point p2(100, 200);
    cout << p2.get_x() << " " << p2.get_y() << endl;
}

int main(){
    //ejemplo_estatico();
    ejemplo_objetos_constantes();
}