#ifndef NODE_H
#define NODE_H
#include <iostream>


class TreeNode{
	public:
		int key;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int data){
			this->key = data;
			left = nullptr;
			right = nullptr;
		}
};
#endif
