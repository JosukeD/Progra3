#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <deque>

using namespace std;


template <typename T>
void bubble_sort(T &v){
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        for (auto j = v.begin(); j != v.end(); ++j)
        {
            if (*i < *j)
            {
                iter_swap(i, j);
            }
        }
    }
}




int main()
{
    // Vector
    vector<int> v = {1, 5, 2, 4, 3};
    bubble_sort(v);
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    
    // List
    list<int> l = {1, 5, 2, 4, 3};
    bubble_sort(l);
    for (auto i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    // Deque
    deque<int> d = {1, 5, 2, 4, 3};
    bubble_sort(d);
    for (auto i = d.begin(); i != d.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}
