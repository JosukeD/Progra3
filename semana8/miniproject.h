#ifndef MINIPROJECT_H
#define MINIPROJECT_H

// Clase Node
namespace UTEC {
    template <typename T>
    struct node {
        T data{};
        node<T>* next =nullptr;
    };

    template <typename T>
    class single_linked_list{
        node<T>* head = nullptr;
    public:
        single_linked_list() = default;
        single_linked_list(initializer_list<T> il){
            for(const auto& item: il){
                push_front(item);
            }
        }

    struct sll_iterator{
        node<T>* current;
        bool operator==(const sll_iterator& other){re       turn this -> current == other.current;}

        bool operator!=(const sll_iterator& other){return this -> current != other.current;}

        T& operator*(){return current->data;}

        T* operator->(){return &current->data;}

        bool operator == (const sll_iterator& other) const{return this -> current == other.current;}

        sll_iterator& operator++(){
            current = current->next;
            return *this;
        }
    };
    single_linked_list() = default;
    ssinglelinked_list(std::initializer_list<T> il){}
    
    void push_front(T value){
        //auto temp = new node<T>{value, nullptr};
        //temp->next = head;
        //head = temp;
        head = new node<T>{value, head};
    }
    void pop_front(){
        auto temp = head->next;
        delete head;
        head = temp;
    }

    sll_iterator begin(){return sll_iterator{head};}
    sll_iterator end(){return sll_iterator{};}

    template <typename ...TParams>
    void emplace_front(TParams... params){
        head = new node<T>{T{params...}, head};
    }

    private:
        node head;        
};
};
#endif