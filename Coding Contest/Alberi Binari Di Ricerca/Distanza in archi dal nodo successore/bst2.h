#include <iostream>

using namespace std;

template<typename T>
class BSTNode{
    private:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* right;
        BSTNode<T>* parent;

        template<typename U>
        friend class BST;
    public:
        BSTNode(T key): key(key), left(nullptr), right(nullptr), parent(nullptr) {}

        T getKey() {return this->key;}
        friend ostream& operator<<(ostream& os, BSTNode<T>* nodo) {
            os << nodo->key << " ";
            return os;
        }
};


template<typename T>
class BST{
    private:
        BSTNode<T>* root;
    public:
        BST(): root(nullptr) {}

        bool isEmpty() {return this->root == nullptr;}

        void insert(T key, BSTNode<T>* ptr) {

            if(!(ptr->left) && key <= ptr->key) {
                ptr->left = new BSTNode<T>(key);
                ptr->left->parent = ptr;
                return;
            }

            if(!(ptr->right) && key > ptr->key) {
                ptr->right = new BSTNode<T>(key);
                ptr->right->parent = ptr;
                return;
            }


            if(key <= ptr->key)
                insert(key, ptr->left);
            else
                insert(key, ptr->right);
        }


        void insert(T key) {
            if(this->isEmpty()) {
                root = new BSTNode<T>(key);
                return;
            }
            insert(key, root);
        }


        void visit(BSTNode<T>* ptr) {
            cout << ptr;
        }

        void preorder(BSTNode<T>* ptr) {
            if(!ptr)
                return;

            visit(ptr);
            preorder(ptr->left);
            preorder(ptr->right);
            
        }

        void postorder(BSTNode<T>* ptr) {
            if(!ptr)
                return;

            postorder(ptr->left);
            postorder(ptr->right);
            visit(ptr);
        }

        void inorder(BSTNode<T>* ptr) {
            if(!ptr)
                return;
            
            inorder(ptr->left);
            visit(ptr);
            inorder(ptr->right);
        }

        void preorder() {preorder(root);}
        void postorder() {postorder(root);}
        void inorder() {inorder(root);}




        BSTNode<T>* min(BSTNode<T>* ptr, int& countEdge) {
            countEdge = 0;
            
            if(!ptr)
                return nullptr;
            
            while(ptr->left){
                ptr = ptr->left;
                countEdge++;
            }
            countEdge++;
            
            return ptr;
        }

        BSTNode<T>* max(BSTNode<T>* ptr) {
            if(!ptr)
                return nullptr;
            
            while(ptr->right)
                ptr = ptr->right;
            
            return ptr;
        }


        BSTNode<T>* min() {return min(root);}
        BSTNode<T>* max() {return max(root);}


        BSTNode<T>* search(BSTNode<T>* ptr, T key) {
            if(!ptr)
                return nullptr;
            
            if(ptr->key == key)
                return ptr;

            if(key <= ptr->key)
                return search(ptr->left, key);
            else
                return search(ptr->right, key);
            
            return nullptr;
        }


        BSTNode<T>* search(T key) {return search(root, key);}

        BSTNode<T>* successor(BSTNode<T>* ptr, int& countEdge) {
            countEdge = 0;
            
            if(!ptr)
                return nullptr;

            if(ptr == max())
                return nullptr;
            
            if(ptr->right)
                return min(ptr->right, countEdge);
            
            BSTNode<T>* y = ptr->parent;
            while(y && ptr == y->right) {
                ptr = y;
                y = y->parent;
                countEdge++;
            }

            countEdge++;

            return y;
        }

        BSTNode<T>* successor(T key) {return successor(search(key));}


        BSTNode<T>* predecessor(BSTNode<T>* ptr) {
            if(!ptr)
                return nullptr;
            
            if(ptr->left)
                return max(ptr->left);
            
            BSTNode<T>* y = ptr->parent;
            while(ptr && ptr == y->left) {
                ptr = y;
                y = y->parent;
            }

            return y;
        }


        BSTNode<T>* remove(BSTNode<T>* ptr) {
            // CASO 1: il nodo è una foglia

            if(ptr == root && !(ptr->left) && !(ptr->right)) {
                root = nullptr;
                return ptr;
            }

            if(!(ptr->left) && !(ptr->right)) {
                if(ptr == ptr->parent->left) {
                    ptr->parent->left = nullptr;
                    return ptr;
                }else {
                    ptr->parent->right = nullptr;
                    return ptr;
                }
            }


            // CASO 2: il nodo ha un figlio
            if(ptr == root && !(ptr->left) && ptr->right) {
                root = ptr->right;
                return ptr;
            }
            if(ptr == root && ptr->left && !(ptr->right)) {
                root = ptr->left;
                return ptr;
            }

            if(!(ptr->left) && ptr->right) {
                ptr->right->parent = ptr->parent;
                if(ptr == ptr->parent->left) {
                    ptr->parent->left = ptr->right;
                    return ptr;
                }else {
                    ptr->parent->right = ptr->right;
                    return ptr;
                }
            }

            if(ptr->left && !(ptr->right)) {
                ptr->left->parent = ptr->parent;
                if(ptr == ptr->parent->left) {
                    ptr->parent->left = ptr->left;
                    return ptr;
                }else {
                    ptr->parent->right = ptr->left;
                    return ptr;
                }
            }

            return nullptr;
        }


        BSTNode<T>* remove(T key) {
            BSTNode<T>* toRemove = search(key);
            if(!toRemove)
                return nullptr;
            
            BSTNode<T>* deleted = remove(toRemove);

            if(deleted)
                return deleted;
            
            int i;
            BSTNode<T>* next = successor(toRemove, i);

            T swap = toRemove->key;
            toRemove->key = next->key;
            next->key = swap;

            deleted = remove(next);
            return deleted;
        }
};