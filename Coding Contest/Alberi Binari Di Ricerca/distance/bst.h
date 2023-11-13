#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>
using namespace std;
template <typename T>
class BST
{
    BSTNode<T> *root;

public:
    BST()
    {
        root = nullptr;
    }

    BSTNode<T> *search(T key)
    {
        return search(root, key);
    }

    BSTNode<T> *search(BSTNode<T> *ptr, T key)
    {
        if (ptr == nullptr)
        {
            std::cout << "Non ho trovato " << key << std::endl;
            return nullptr;
        }

        if (ptr->key == key)
            return ptr;

        if (key <= ptr->key)
            return search(ptr->left, key);
        else
            return search(ptr->right, key);

        return nullptr;
    }
    void clear()
    {
        root = nullptr;
    }
    void preorder(BSTNode<T> *ptr)
    {
        if (ptr == nullptr)
            return;

        visit(ptr);
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void inorder(BSTNode<T> *ptr)
    {
        if (ptr == nullptr)
            return;

        inorder(ptr->left);
        visit(ptr);
        inorder(ptr->right);
    }

    void postorder(BSTNode<T> *ptr)
    {
        if (ptr == nullptr)
            return;

        postorder(ptr->left);
        postorder(ptr->right);
        visit(ptr);
    }

    BSTNode<T> *successor()
    {
        return successor(root);
    }

    void inorder()
    {
        inorder(root);
    }

    void preorder()
    {
        preorder(root);
    }

    void postorder()
    {
        postorder(root);
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    BSTNode<T> *getRoot()
    {
        return this->root;
    }

    void insert(T key)
    {
        if (this->isEmpty())
        {
            root = new BSTNode<T>(key);
            return;
        }
        insert(root, key);
    }

    void insert(BSTNode<T> *ptr, T key)
    {
        if (ptr->left == nullptr && key <= ptr->key)
        {
            ptr->left = new BSTNode<T>(key);
            ptr->left->setParent(ptr);
            return;
        }
        if (ptr->right == nullptr && key > ptr->key)
        {
            ptr->right = new BSTNode<T>(key);
            ptr->right->parent = ptr;
            return;
        }
        else if (key <= ptr->key)
            insert(ptr->left, key);
        else
            insert(ptr->right, key);
    }

    void visit(BSTNode<T> *node)
    {
        std::cout << *node << std::endl;
    }

    BSTNode<T> *min()
    {
        return min(root);
    }

    BSTNode<T> *min(BSTNode<T> *from)
    {
        if (isEmpty())
        {
            return NULL;
        }

        BSTNode<T> *ptr = from;
        while (ptr->left)
        {
            ptr = ptr->left;
        }

        return ptr;
    }
    BSTNode<T> *successor(BSTNode<T> *x)
    {
        if (this->isEmpty())
        {
            return nullptr;
        }

        // 1. x ha un sottoalbero destro

        if (x->right)
        {

            return this->min(x->right);
        }

        // 2. x non ha un sottoalbero destro
        // il successore di x è l'antenato più prossimo di x
        // il cui figlio sinistro è anche un antenato di x

        BSTNode<T> *y = x->parent;

        while (x != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }

        return y;
    }

    int Prova(T x)
    {
        return successor(x);
    }
    BSTNode<T> *remove(BSTNode<T> *ptr)
    {
        // CASO 1
        if (ptr == root && !(ptr->left) && !(ptr->right))
        {
            root = nullptr;
            return ptr;
        }

        if (!(ptr->left) && !(ptr->right))
        {
            if (ptr == ptr->parent->left)
            {
                ptr->parent->left = nullptr;
                return ptr;
            }
            else
            {
                ptr->parent->right = nullptr;
                return ptr;
            }
        }

        // CASO 2
        if (ptr == root && ptr->left && !(ptr->right))
        {
            ptr->left->parent = nullptr;
            root = ptr->left;
            return ptr;
        }

        if (ptr == root && !(ptr->left) && ptr->right)
        {
            ptr->right->parent = nullptr;
            root = ptr->right;
            return ptr;
        }

        if (ptr->left && !(ptr->right))
        {
            ptr->left->parent = ptr->parent;
            if (ptr == ptr->parent->left)
            {
                ptr->parent->left = ptr->left;
                return ptr;
            }
            else
            {
                ptr->parent->right = ptr->left;
                return ptr;
            }
        }

        if (!(ptr->left) && ptr->right)
        {
            ptr->right->parent = ptr->parent;
            if (ptr == ptr->parent->left)
            {
                ptr->parent->left = ptr->right;
                return ptr;
            }
            else
            {
                ptr->parent->right = ptr->right;
                return ptr;
            }
        }

        return nullptr;
    }

    BSTNode<T> *remove(T key)
    {
        if (this->isEmpty())
            return nullptr;

        BSTNode<T> *toDelete = search(key);

        if (!toDelete)
            return nullptr;

        BSTNode<T> *toRemove = remove(toDelete);
        if (toRemove)
            return toRemove;

        BSTNode<T> *next = successor(toDelete);
        T swap = toDelete->key;
        toDelete->key = next->key;
        next->key = swap;

        toRemove = remove(next);
        return toRemove;
    }
    int from_root(BSTNode<T> *nodo_h, BSTNode<T> *partenza)
    {

        // partenza = radice del sottoalbero ottenuto mettendo nodo_k come radice

        if (partenza->getKey() == nodo_h->getKey()) // distanza tra un nodo e se stesso
            return 0;

        BSTNode<T> *tmp = partenza;
        int counter = 0; // distanza tra padre e figlio

        while (tmp && tmp->getKey() != nodo_h->getKey()) // esco quando arrivo ad una foglia
                                                         // oppure quando trovo il nodo
        {
            if (nodo_h->getKey() > tmp->getKey())
                tmp = tmp->right;
            else
                tmp = tmp->left;

            counter++;
        }

        if (!tmp)
            return -1;
        else
            return counter;
    }

    int distanzaChiavi(T k, T h)
    {

        BSTNode<T> *nodo_k = search(k);
        BSTNode<T> *nodo_h = search(h);

        int counter = 0;

        if (!nodo_k || !nodo_h)
            throw("Chiavi errate!");

        if (k <= h)
        {
            BSTNode<T> *tmp = nodo_k;
            bool flag = true;

            while (tmp && flag)
            {
                int distanza = from_root(nodo_h, tmp);

                if (distanza == 0)
                    flag = false;

                else if (distanza == -1)
                {
                    tmp = tmp->parent;
                    counter++;
                }
                else
                {
                    counter += distanza;
                    flag = false;
                }
            }

            return counter;
        }
        else
            return distanzaChiavi(h, k); // inverto per ottenere k <= h
    }
};
#endif