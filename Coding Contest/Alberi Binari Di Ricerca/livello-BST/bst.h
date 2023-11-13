#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>
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
        std::cout << *node << std::endl;
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

        BSTNode<T> *y = x->parent;

        while (y != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }

        return y;
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

        while (y != nullptr && x == y->left)
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

    BSTNode<T> *remove(BSTNode<T> *node)
    {

        if (node == root)
        {
            if (node->right == nullptr && node->left != nullptr)
            {
                root = node->left;
                return node;
            }
            if (node->left == nullptr && node->right != nullptr)
            {
                root = node->right;
                return node;
            }

            if (node->left == nullptr && node->right == nullptr)
            {
                root = nullptr;
                return node;
            }
        }
        // CASO 1
        // il nodo è una foglia
        if (node->left == nullptr && node->right == nullptr)
        {
            if (node == node->parent->left)
                node->parent->left = nullptr;
            else if (node == node->parent->right)
                node->parent->right = nullptr;

            return node; // proviamo a trasformare il nodo in nullptr
        }

        // CASO 2
        // il nodo da eliminare ha solo un figlio destro
        if (node->left == nullptr && node->right != nullptr)
        {
            node->right->parent = node->parent;

            // il nodo da eliminare è figlio sx
            if (node == node->parent->left)
            {
                node->parent->left = node->right;
            }
            // il nodo da eliminare è figlio dx
            else if (node == node->parent->right)
            {
                node->parent->right = node->right;
            }
            return node;
        }

        // il nodo da eliminare ha solo un figlio sinistro
        if (node->left != nullptr && node->right == nullptr)
        {
            node->left->parent = node->parent;

            // il nodo da eliminare è figlio sx
            if (node == node->parent->left)
            {
                node->parent->left = node->left;
            }
            // il nodo da eliminare è figlio dx
            else if (node == node->parent->right)
            {
                node->parent->right = node->left;
            }
            return node;
        }

        return nullptr;
    }

    BSTNode<T> *remove(T key)
    {
        // Caso 1 e 2, viene richiamata l funzione al quale passiamo il nodo e non il valore (chiave)
        if (this->isEmpty())
        {
            return nullptr;
        }

        BSTNode<T> *node = this->search(key);
        if (node == nullptr)
            return nullptr;

        BSTNode<T> *toDelete = this->remove(node);

        if (toDelete != nullptr)
            return toDelete;

        // CASO 3
        // il nodo da eliminare ha due figli
        // sostituiamo la chiave nel nodo da eliminare con la chiave del suo successore
        BSTNode<T> *next = this->successor(node);
        // sostituzione della chiave
        T swap = node->key;
        node->key = next->key;
        next->key = swap;

        // richiamo la procedura di cancellazione (casi 1 e 2) sul successore
        toDelete = this->remove(next);

        return toDelete;
    }
    void searchKey(BSTNode<T> *&curr, int key, BSTNode<T> *&parent)
    {
        // traverse the tree and search for the key
        while (curr != nullptr && curr->key != key)
        {
            // update the parent to the current node
            parent = curr;

            // if the given key is less than the current node, go to the left subtree;
            // otherwise, go to the right subtree
            if (key < curr->key)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
    void deleteNode(T key)
    {
        BSTNode<T> *node = search(key);

        return deleteNode(node, key);
    }
    /*
    int CalcolaAltezza(int key, int cont)
    {
        return CalcolaAltezza(root, key, cont);
    }

    int CalcolaAltezza(BSTNode<T> *node, int key, int cont)
    {
        if (node->key == key)
        {
            return cont;
        }
        if (node->key > key)
        {
            cont++;
            return CalcolaAltezza(node->getRight(), key, cont);
        }
        else
        {
            cont++;
            return CalcolaAltezza(node->getLeft(), key, cont);
        }
        return -1;
    }

    int getAltezza(T key)
    {
        int cont = 0;

        if (!search(key))
        {
            return 0;
        }
        else
        {
            BSTNode<T> *node = search(key);

            if (!node->parent)
            {
                return 0;
            }

            while (node->parent)
            {
                node = node->parent;
                cont++;
            }
        }

        return cont;
    }
    */

    int getAltezza(T key)
    {
        int altezza = 0;
        BSTNode<T> *aux = root;
        BSTNode<T> *aux2;
        if (root->getKey() == key)
        {
            return altezza;
        }
        while (aux->right != nullptr || aux->left != nullptr)
        {
            if (aux != nullptr)
            {
                if (key > aux->getKey())
                {
                    altezza++;
                    aux2 = aux->right;
                    aux = aux2;
                }
                if (key < aux->getKey())
                {
                    altezza++;
                    aux2 = aux->left;
                    aux = aux2;
                }
                if (key == aux->getKey())
                {
                    return altezza;
                }
            }
        }
        return -1;
    }
};
#endif