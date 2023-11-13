#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>
#include <sstream>
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

    void postorder(BSTNode<T> *ptr, T arr[], int cont, fstream &out)
    {
        if (ptr == nullptr)
            return;
        postorder(ptr->left, arr, cont, out);
        postorder(ptr->right, arr, cont, out);
        for (int i = 0; i < cont; i++)
        {
            if (ptr->getKey() == arr[i])
            {
                out << ptr->getKey() << " ";
            }
        }
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
    /*
    void postorder()
    {
        postorder(root);
    }
    */
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

    BSTNode<T> *max()
    {
        return max(root);
    }

    BSTNode<T> *max(BSTNode<T> *from)
    {
        if (isEmpty())
        {
            return NULL;
        }

        BSTNode<T> *ptr = from;
        while (ptr->right)
        {
            ptr = ptr->right;
        }

        return ptr;
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

        while (y != nullptr && x == y->right)
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

    void SuccessoriPari(fstream &out)
    {
        BSTNode<T> *aux = min(root);
        int cont = 0;
        while (successor(aux) != nullptr)
        {
            if (aux != nullptr)
            {
                T val = aux->getKey();
                BSTNode<T> *aux2 = successor(aux);
                if ((int)(aux2)->getKey() % 2 == 0)
                {
                    cont++;
                }
                aux = successor(aux);
            }
        }
        aux = min(root);
        T arr[cont]{0};
        int v = 0;
        while (successor(aux) != nullptr)
        {
            if (aux != nullptr)
            {
                T val = aux->getKey();
                BSTNode<T> *aux2 = successor(aux);
                if ((int)(aux2)->getKey() % 2 == 0)
                {
                    arr[v] = val;
                    v++;
                }
                aux = successor(aux);
            }
        }
        postorder(root, arr, cont, out);
    }
};
#endif