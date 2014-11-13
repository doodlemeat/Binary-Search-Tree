#include <iostream>

#include "BinarySearchTree.h"
#include "BinarySearchTreeTest.h"


int main()
{
	BinarySearchTree<int> bst; // std::initalizer_list do also work; bst = {5,2,7}

	insert(bst, 8, true, "Insert 8");
	insert(bst, 3, true, "Insert 3");
	insert(bst, 1, true, "Insert 1");
	insert(bst, 6, true, "Insert 6");
	insert(bst, 4, true, "Insert 4");
	insert(bst, 7, true, "Insert 7");
	insert(bst, 10, true, "Insert 10");
	insert(bst, 14, true, "Insert 14");
	insert(bst, 13, true, "Insert 13");

	traverseInOrder(bst, "Travese in order(expected 1,4,6,7,13,14)");
	traversePreOrder(bst, "Traverse pre order(expected 8,3,1,6,4,7,10,14,13)");
	traversePostOrder(bst, "Traverse post order(expected 1,4,7,6,3,13,14,10,8)");

	size_equal_to(9, bst);
	
	erase(bst, 14, true, "Erase 14 (one child)");
	erase(bst, 13, true, "Erase 13 (no children)");
	erase(bst, 6, true, "Erase 6 (two children)");
	erase(bst, 8, true, "Erase 8 (root)");

	size_equal_to(5, bst);

	traverseInOrder(bst, "Traverse in order(expected 1,3,4,7,10)");
	traversePreOrder(bst, "Traverse pre order(expected 10,3,1,7,4)");
	traversePostOrder(bst, "Traverse post order(expected 1,4,7,3,10)");

	search(bst, 10, true, "Search 10 (root)");
	search(bst, 3, true, "Search 3 (two children)");
	search(bst, 7, true, "Search 7 (one child)");
	search(bst, 1, true, "Search 1 (no children)");
	search(bst, 8, false, "Search 8");
	search(bst, 13, false, "Search 13");

	return 0;
}