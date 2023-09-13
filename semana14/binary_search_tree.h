#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <utility>

using namespace std;

template <typename KeyType, typename ValueType, typename Compare = less<KeyType>>
class BinarySearchTree{
    struct node_t{  
        pair<KeyType, ValueType> data;
        shared_ptr<node_t> left;
        shared_ptr<node_t> right;
        weak_ptr<node_t> parent;
        node_t(pair<keyType, ValueType>item, shared_ptr<node_t> parent): item(item), parent(parent){}
    };
    shared_ptr<node_t> root;

public:
    BinarySearchTree() = default;
    void insert(pair<KeyType, ValueType> item){
        // Verificar si tiene root
        if(!root){
            root = make_shared<node_t>(item);
            return;
        }
        // Creo el concurrente
        auto current = root;
        while(current){
            if (item.first < current.item.first){
                // Colocar a la izquierda
                if(current->left){current = current->left;}
                else{
                    current->left = make_shared<node_t>(item);
                    current->left->parent = current;
                    return;
                }
            }
            else {
                // Colocar a la derecha
                if(current->right) {current = current->right;}
            }
        }
    }

};

#endif // BINARY_SEARCH_TREE_H