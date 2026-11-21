#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::insert(int value) {
    root = insertRecursive(root, value);
}

bool BinarySearchTree::search(int value) {
    return searchRecursive(root, value);
}

bool BinarySearchTree::deleteValue(int value) {
    bool deleted = false;
    root = deleteRecursive(root, value);
    return deleted;
}

void BinarySearchTree::displayInorder() {
    inorderRecursive(root);
    cout << endl;
}

void BinarySearchTree::displayPreorder() {
    preorderRecursive(root);
    cout << endl;
}

void BinarySearchTree::displayPostorder() {
    postorderRecursive(root);
    cout << endl;
}

int BinarySearchTree::findMin() {
    if (root == nullptr) {
        throw runtime_error("Empty array so cannot run findMin()");
    }
    Node* current = root;
    while (current->left) {
        current = current->left;
    }
    return current->data;
    
}

int BinarySearchTree::findMax() {
    if (root == nullptr) {
        throw runtime_error("Empty array so cannot run findMax()");
    }
    Node* current = root; 
    while(current->right) {
        current = current->right;
    }
    return current->data;
}

void BinarySearchTree::balanceTree() {
    vector<int> nodes;
    inSortedOrder(root, nodes);
    destroyTree(root);
    root = buildBalancedTree(nodes, 0, nodes.size() - 1);
}

void BinarySearchTree::saveTree(string fname) {
    ofstream file(fname);
    if (!file.is_open()) {
        cout << "Could not open file" << endl;
        return;
    }
    savePreorderTree(root, file);
    file.close();
}

int BinarySearchTree::countItems() {
    return countHelper(root);
}