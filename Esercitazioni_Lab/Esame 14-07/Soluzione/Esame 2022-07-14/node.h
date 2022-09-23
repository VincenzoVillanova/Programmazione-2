#ifndef LNODE_H
#define LNODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node
{
    T val;
    Node<T> *next;
    bool verbose;

    template <typename U>
    friend class List;

public:
    Node(T val, bool verbose = false) : val(val), verbose(verbose)
    {
        next = nullptr;
    }

    Node<T> *getNext() const { return this->next; }

    T &getVal() { return this->val; }

    friend ostream &operator<<(ostream &out, Node<T> &node)
    {

        out << node.val;

        return out;
    }
};

#endif