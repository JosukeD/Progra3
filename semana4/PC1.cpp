#include "PC1.h"
#include <iostream>
#include <random>
using namespace std;

int main(){
    std::vector<int> v1 = {1, 5, 3, 8, 2};
    std::vector<int> v2 = {4, 9, 7, 6, 10, 1};
    symmetric_difference_t<int> sd1 (v1, v2);
    std::copy(sd1(), sd1() + sd1.size(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;
    !sd1;
    std::copy(sd1(), sd1()+sd1.size(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;
    std::vector<double> v3 = {1.0, 10.0, 3.0, 6.0, 2.0, 1.0};
    std::vector<double> v4 = {4.0, 9.0, 7.0, 6.0, 10.0, 1.0};
    symmetric_difference_t<double> sd2 (v3, v4);
    std::copy(sd2(), sd2() + sd2.size(), std::ostream_iterator<double>(std::cout," "));
    std::cout << std::endl;
    !sd2;
    std::copy(sd2(), sd2() + sd2.size(), std::ostream_iterator<double>(std::cout," "));
    std::cout << std::endl;
    return 0;
}
