#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

template <typename T>
class BSTNode
{
protected:
    T key;              // valore nodo
    BSTNode<T> *left;   // sottoalbero sinistro
    BSTNode<T> *right;  // sottoalbero destro
    BSTNode<T> *parent; // padre nodo

    template <typename U>
    friend class BST;

public:
    BSTNode(T key) : key(key) // costruttore
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    void setLeft(BSTNode<T> *left) // modifica sottoalbero sinistro
    {
        this->left = left;
    }

    void setRight(BSTNode<T> *right) // modifica sottoalbero destro
    {
        this->right = right;
    }

    void setParent(BSTNode<T> *parent) // modifica padre
    {
        this->parent = parent;
    }

    BSTNode<T> *getLeft() // ritorna sottoalbero sinistro
    {
        return this->left;
    }

    BSTNode<T> *getRight() // ritorna sottoalbero destro
    {
        return this->right;
    }

    BSTNode<T> *getParent() // ritorna padre
    {
        return this->parent;
    }

    void setKey(T key) // modifica chiave
    {
        this->key = key;
    }

    T getKey()
    {
        return this->key; // ritorna chiave
    }

    friend std::ostream &operator<<(std::ostream &out, BSTNode<T> &node) // operatore <<
    {
        out << "key= " << node.key;
        return out;
    }
};

#endif