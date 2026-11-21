#include "BinarySearchTree.h"


int main() {
    BinarySearchTree BST;

    BST = BinarySearchTree();

    int array[] = {1, 5, 29, 64, 8, 2, 0, 44, 27, 9, 15, 30};

    cout << "Testing the Binary Search Tree" << endl;


    

    //Inserting array into Binary Search Tree one by one from the array
    cout << "Inserting array into Binary Search Tree" << endl;
    for (int i = 0; i < 12; i++) {
        BST.insert(array[i]);
    }
   

    int count = BST.countItems();
    cout << "The count and returned number of items in the tree is: " << count << endl;


    bool findSearch;
    cout << "Searching for 27 in the Binary Search Tree" << endl;
    findSearch = BST.search(27);
    if (findSearch) {
        cout << "27 was found successfully in the Binary Search Tree" << endl;
    } else {
        cout << "27 was not found successfully in the Binary Search Tree" << endl;
    }

    cout << "Searching for 12 in the Binary Search Tree" << endl;
    findSearch = BST.search(12);
    if (findSearch) {
        cout << "12 was found successfully in the Binary Search Tree" << endl;
    } else {
        cout << "12 was not found successfully in the Binary Search Tree" << endl;
    }   
    
    bool deleteValueFound;
    cout << "Deleting 2 from the Binary Search Tree" << endl;
    deleteValueFound = BST.deleteValue(2);
    if (deleteValueFound) {
        cout << "2 was found and deleted from the Binary Search Tree" << endl;
    } else {
        cout << "2 was not found and therefore returns false" << endl;
    }

    cout << "Displaying Inorder Traversal: ";
    BST.displayInorder();
    cout << endl;

    cout << "Displaying Preorder Traversal before balancing tree: ";
    BST.displayPreorder();
    cout << endl;

    BST.balanceTree();

    cout << "Displaying Preorder Traversal after balancing tree: ";
    BST.displayPreorder();
    cout << endl;

    cout << "Displaying Postorder Traversal: ";
    BST.displayPostorder();
    cout << endl;

    int minimum = BST.findMin();
    cout << "The minimum value from the Binary Search Tree is " << minimum << endl;
    int maximum = BST.findMax();
    cout << "The maximum value from the Binary Search Tree is " << maximum << endl;

    string file = "saved.txt";
    BST.saveTree(file);
    
    

    return 0;
}