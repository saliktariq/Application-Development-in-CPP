#include "binarysearchtree.h"
#include <iostream>

int main(){
	BinarySearchTree tree;
    tree.insert(30); //level 0
    tree.insert(20);//level 1
    tree.insert(40); //level 1
    tree.insert(15);//level 2
    tree.insert(25);//level 2
    tree.insert(35);//level 2

	
	tree.inOrderTraversal();
	
	
	tree.getLevel();
	
	
	return 0;
}
