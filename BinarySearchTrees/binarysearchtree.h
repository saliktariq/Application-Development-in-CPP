#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include "node.h"
#include <cmath>

using namespace std;

class BinarySearchTree{
	private:
		TreeNode* root;
		int level;
		
		TreeNode* insertRec(TreeNode* root, int key, int curLevel) {
        if (root == nullptr) {
        	level = max(level, curLevel);
            return new TreeNode(key);
        }
        if (key < root->key) {
            root->left = insertRec(root->left, key, curLevel + 1);
        }
        else if (key > root->key) {
            root->right = insertRec(root->right, key, curLevel + 1);
        }
        return root;
    }
	public:
		BinarySearchTree(){
			
			root = nullptr;
			level = 0;
		}
		
		void getLevel(){
			cout<< "level: " << level << endl;
			cout<< "\n Maximum elements at this level: " << (pow(2, level+1)-1) << endl;
		}
		
		void insert(int key) {
        root = insertRec(root, key, 0);
    }
		
		void inOrderTraversal(TreeNode* root){
		
			if(root!= nullptr){
				
			inOrderTraversal(root->left);
			std::cout << root->key << " ";
			inOrderTraversal(root->right);
			}
		}
		
		void inOrderTraversal(){
		
			inOrderTraversal(root);
		}
};

#endif
