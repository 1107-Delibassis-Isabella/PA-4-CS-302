PA4: BinarySearchTree.o Node.o main.o
	g++ BinarySearchTree.o Node.o main.o -o PA4

main.o: main.cpp BinarySearchTree.h Node.h
	g++ -c main.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h Node.h
	g++ -c BinarySearchTree.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean: 
	rm -f *.o PA4