#include <iostream>

using namespace std;

template <typename T>
class median{
    T *arr;
    int size;
    int capacity;
    int median;
public:

    median(){
        arr = new T[1];
        size = 0;
        capacity = 1;
    }

    median(initializer_list<T> list){
        size = list.size();
        capacity = size;
        arr = new T[size];
        int i = 0;
        for(auto &item : list){
            arr[i] = item;
            i++;
        }
    }

    void push(T item){
        if(size == capacity){
            capacity *= 2;
            T *temp = new T[capacity];
            for(int i = 0; i < size; i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[size] = item;
        size++;
    }

    void sort(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size - 1; j++){
                if(arr[j] > arr[j + 1]){
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        if(size % 2 == 0){
            median = (arr[size / 2] + arr[(size / 2) - 1]) / 2;
        }
        else{
            median = arr[size / 2];
        }
    }

    T getMedian(){
        sort();
        return median;
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, median<T> m){
        m.print();
        return os;
    }
};


int main(){
        // Caso de uso #1
    median<int> m {1, 2, 3, 5};
    cout << m << endl;
    // Caso de uso #2
    median<double> m {1, 2, 2.4, 5};
    cout << m << endl;
    // Caso de uso #3
    median<float> m {1, 2, 5, 6, 7, 3, 11, 2, 4, 3, 7};
    cout << m << endl;
    // Caso de uso #4
    median<int> m {1};
    cout << m << endl;
}