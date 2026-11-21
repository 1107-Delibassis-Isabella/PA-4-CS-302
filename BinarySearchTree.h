#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <stdio.h>
#include <iostream>
#include <string> //for string variable
#include <queue>
#include <vector>
#include <fstream>
#include "Node.h"
using namespace std;


class BinarySearchTree {
    private: 
        Node* root;

        Node* insertRecursive(Node* current, int value) {
            if (current == nullptr) {
                return new Node(value);
            }
            if (current->data > value) {
                current->left = insertRecursive(current->left, value);
            } else if (current->data < value) {
                current->right = insertRecursive(current->right, value);
            }

            return current;
        }
        Node* deleteRecursive(Node* current, int value) {
            if (current == nullptr) {
                return nullptr;
            }

            if (current->data == value) {
                if (current->left == nullptr && current->right == nullptr) {
                    delete current;
                    return nullptr;
                }
                if (current->left == nullptr) {
                    Node* temp = current->right;
                    delete current;
                    return temp;
                }
                if (current->right == nullptr) {
                    Node* temp = current->left;
                    delete current;
                    return temp;
                }

                Node* successor = findMin(current->right);
                current->data = successor->data;
                current->right = deleteRecursive(current->right, successor->data);
            } else {
                current->left = deleteRecursive(current->left, value);
                current->right = deleteRecursive(current->right, value);
            }
            return current;
        }

        Node* findMin(Node* n) {
            while (n->left == nullptr) {
                return n;
            }

            return findMin(n->left);
        }

        bool searchRecursive(Node* current, int value) {
            if (current == nullptr) {
                return false;
            }
            if (current->data == value) {
                return true;
            }
            if (current->data > value) {
                return searchRecursive(current->left, value);
            } 
            if (current->data < value) {
                return searchRecursive(current->right, value);
            }
            return false; //not sure if I should include this
        }

        void inorderRecursive(Node* n) {
            if (n != nullptr) {
                inorderRecursive(n->left);
                cout << n->data << " ";
                inorderRecursive(n->right);
            }
        }
        
        void preorderRecursive(Node* n) {
            if (n != nullptr) {
                cout << n->data << " ";
                preorderRecursive(n->left);
                preorderRecursive(n->right);
            }
        }

        void postorderRecursive(Node* n) {
            if (n != nullptr) {
                postorderRecursive(n->left);
                postorderRecursive(n->right);
                cout << n->data << " ";
            }
        }

        int countHelper(Node* n) {
            if (n == nullptr) {
                return 0;
            }
            return 1 + countHelper(n->left) + countHelper(n->right);
        }

        void inSortedOrder(Node* n, vector<int>& sorted) { //will be used for the balanceTree() 
            if (n == nullptr) {
                return;
            }
            inSortedOrder(n->left, sorted);
            sorted.push_back(n->data);
            inSortedOrder(n->right, sorted);
        }

        void destroyTree(Node* n) {
            if (n == nullptr) {
                return;
            }
            destroyTree(n->left);
            destroyTree(n->right);
            delete n;
        }

        Node* buildBalancedTree(const vector<int>& sorted, int start, int end) {
            if (start > end) {
                return nullptr;
            }
            int mid = (start + end) / 2;
            Node* newNode = new Node(sorted[mid]);
            newNode->left = buildBalancedTree(sorted, start, mid-1);
            newNode->right = buildBalancedTree(sorted, mid+1, end);
            return newNode;
        }

        void savePreorderTree(Node* n, ofstream& file) {
            if (n == nullptr) {
                return;
            }
            file << n->data << endl;
            savePreorderTree(n->left, file);
            savePreorderTree(n->right, file);
        }

    public:
        BinarySearchTree();
        void insert(int value);
        bool search(int value);
        bool deleteValue(int value); //return false if value not found
        void displayInorder();
        void displayPreorder();
        void displayPostorder();
        int findMin(); //find and return the value of the minimum
        int findMax(); //find and return the value of the maximum
        void balanceTree(); //balance the tree by putting it an array in sorted order and then inserting elements appropriately (like discussed in class)
        void saveTree(string fname); //save tree in preorder so it can be restored
        int countItems(); //count and return the number of items in the tree
};
#endif