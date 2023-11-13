#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>
#include <sstream>
using namespace std;
stringstream s;
template <typename T>
class BST
{
    BSTNode<T> *root;

public:
    BST()
    {
        root = nullptr;
    }

    void clear()
    {
        root = nullptr;
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

    // la mia procedura ricorsiva deve avere due parametri:
    // il valore da inserire e la radice del sottoalbero

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
        s<<*node;
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

    BSTNode<T> *successor()
    {
        return successor(root);
    }

    BSTNode<T> *predecessor()
    {
        return predecessor(root);
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
        if (x->parent != nullptr && x->right == nullptr)
        {
            BSTNode<T> *y = x->parent;

            while (y != nullptr && x == y->right)
            {
                x = y;
                y = y->parent;
            }
            return y;
        }
        else
        {
            return nullptr;
        }
    }

    BSTNode<T> *predecessor(BSTNode<T> *x)
    {
        if (this->isEmpty())
        {
            return nullptr;
        }

        // 1. x ha un sottoalbero sinistro

        if (x->left)
            return this->max(x->left);

        // 2. x non ha un sottoalbero sinistro
        // il successore di x è l'antenato più prossimo di x
        // il cui figlio sinistro è anche un antenato di x

        BSTNode<T> *y = x->parent;

        while (x != nullptr && x == y->left)
        {
            x = y;
            y = y->parent;
        }

        return y;
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

    string Ritornas()
    {
        return s.str();
    }
    void Puliscis()
    {
        s.str("");
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
};
#endif