#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree BST;

    BST = BinarySearchTree();

    int array[] = {1, 5, 29, 64, 8, 2, 0, 44, 27, 9, 15, 30};

    cout << "Testing the Binary Search Tree with values of: " << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    //Test for Insertion in BST
    // Inserting array into Binary Search Tree one by one from the array
    cout << "\nInserting array into Binary Search Tree one by one" << endl;
    for (int i = 0; i < 12; i++)
    {
        BST.insert(array[i]);
    }

    int count = BST.countItems();
    cout << "Running the countItems() function (the count should be 12)\nThe count and returned number of items in the tree is: " << count << endl;

    //Test for Search function in BST
    cout << "\nTesting for Binary Search Tree search for specific values: " << endl;
    bool findSearch;
    cout << "Searching for 27 in the Binary Search Tree (should be found)" << endl;
    findSearch = BST.search(27);
    if (findSearch)
    {
        cout << "27 was found successfully in the Binary Search Tree" << endl;
    }
    else
    {
        cout << "27 was not found successfully in the Binary Search Tree" << endl;
    }

    cout << "Searching for 30 in the Binary Search Tree (should be found)" << endl;
    findSearch = BST.search(30);
    if (findSearch)
    {
        cout << "30 was found successfully in the Binary Search Tree" << endl;
    }
    else
    {
        cout << "30 was not found successfully in the Binary Search Tree" << endl;
    }

    cout << "Searching for 0 in the Binary Search Tree (should be found)" << endl;
    findSearch = BST.search(0);
    if (findSearch)
    {
        cout << "0 was found successfully in the Binary Search Tree" << endl;
    }
    else
    {
        cout << "0 was not found successfully in the Binary Search Tree" << endl;
    }

    cout << "Searching for 12 in the Binary Search Tree (should not be found)" << endl;
    findSearch = BST.search(12);
    if (findSearch)
    {
        cout << "12 was found successfully in the Binary Search Tree" << endl;
    }
    else
    {
        cout << "12 was not found successfully in the Binary Search Tree" << endl;
    }

    cout << "Searching for 77 in the Binary Search Tree (should not be found)" << endl;
    findSearch = BST.search(77);
    if (findSearch)
    {
        cout << "77 was found successfully in the Binary Search Tree" << endl;
    }
    else
    {
        cout << "77 was not found successfully in the Binary Search Tree" << endl;
    }

    //Test for deletion in Binary Search Tree
    cout << "\nTesting out deletion from the Binary Search Tree: " << endl;
    bool deleteValueFound;
    cout << "Deleting 2 from the Binary Search Tree (should be returned as true and be found)" << endl;
    deleteValueFound = BST.deleteValue(2);
    if (deleteValueFound)
    {
        cout << "2 was found and deleted from the Binary Search Tree" << endl;
    }
    else
    {
        cout << "2 was not found and therefore returns false" << endl;
    }

    cout << "Deleting 29 from the Binary Search Tree (should be returned as true and be found)" << endl;
    deleteValueFound = BST.deleteValue(29);
    if (deleteValueFound)
    {
        cout << "29 was found and deleted from the Binary Search Tree" << endl;
    }
    else
    {
        cout << "29 was not found and therefore returns false" << endl;
    }

    cout << "Deleting 6 from the Binary Search Tree (should be returned as false and not be found)" << endl;
    deleteValueFound = BST.deleteValue(6);
    if (deleteValueFound)
    {
        cout << "6 was found and deleted from the Binary Search Tree" << endl;
    }
    else
    {
        cout << "6 was not found and therefore returns false" << endl;
    }

    //Testing for displaying Preorder, Inorder, and Postorder Traversal displays
    cout << "\nTesting for Displays for Inorder, Preorder, and Postorder Traversals: " << endl;
    cout << "Displaying Inorder Traversal for an unbalanced tree: ";
    BST.displayInorder();
    cout << endl;

    cout << "Displaying Preorder Traversal for an unbalanced tree: ";
    BST.displayPreorder();
    cout << endl;

    cout << "Displaying Postorder Traversal for an unbalanced tree: ";
    BST.displayPostorder();
    cout << endl;


    //Balancing the tree and then displaying the Preorder traversal after
    BST.balanceTree();

    cout << "Displaying Preorder Traversal for a balanced tree: ";
    BST.displayPreorder();
    cout << endl;

    cout << "Displaying Postorder Traversal for a balanced tree: ";
    BST.displayPostorder();
    cout << endl;

    //Tests for findMin() and findMax() in a BST
    cout << "\nTesting for finding the minimum and maximum in the Binary Search Tree: " << endl;
    int minimum = BST.findMin();
    cout << "The minimum value from the Binary Search Tree is " << minimum << endl;
    int maximum = BST.findMax();
    cout << "The maximum value from the Binary Search Tree is " << maximum << endl;


    //Test for saveTree function in a BST

    cout << "\nTesting for saving the tree in preorder and restoring it " << endl;
    string file = "saved.txt";
    BST.saveTree(file);
    cout << "Restore and saved the preorder traversal to the file: " << file << endl;

    BinarySearchTree preorderSaved;
    ifstream inFile(file);
    int value;
    while (inFile >> value) {
        preorderSaved.insert(value);
    }
    
    cout << "\nDisplaying the Preorder, Inorder, and Postorder traversals for the preorder saved in the file" << endl;
    cout << "Inorder traversal from saved and restored preorder traversal: ";
    preorderSaved.displayInorder();
    cout << endl;
    cout << "Preorder traversal from saved and restored preorder traversal: ";
    preorderSaved.displayPreorder();
    cout << endl;
    cout << "Postorder traversal from saved and restored preorder traversal: ";
    preorderSaved.displayPostorder();
    cout << endl;

    return 0;
}