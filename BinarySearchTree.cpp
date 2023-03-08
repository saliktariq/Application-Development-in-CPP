#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

TreeNode *root = NULL;

TreeNode* insert(TreeNode* node, int data){

    if(node == NULL){
        TreeNode *treeNode = new TreeNode();
        treeNode->data = data;
        treeNode->leftChild = NULL;
        treeNode->rightChild = NULL;
        return treeNode;
    }

    if ( data < node->data ){
        node->leftChild = insert(node->leftChild, data);
    } else {
        node->rightChild = insert(node->rightChild, data);
    }

    return node;
}



void inOrderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->leftChild);
    cout << root->data << " ";
    inOrderTraversal(root->rightChild);
}

void preOrderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->leftChild);
    preOrderTraversal(root->rightChild);
}

void postOrderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }

    postOrderTraversal(root->leftChild);
    postOrderTraversal(root->rightChild);
    cout << root->data << " ";
}

bool search(TreeNode* tree, int searchKey){
	
	if(tree == NULL){
	   return false;
	}
	
	if(tree->data == searchKey){
		return true;
	} else {
		return	search(tree->leftChild,searchKey) || search(tree->rightChild, searchKey);
		
	}

}

TreeNode* findAndReturnNode(TreeNode* tree, int searchKey){
	
	TreeNode* tempNode = root;
	
	if(tempNode->data == searchKey){
		return tempNode;
	}
	while(tempNode->leftChild != NULL){
		if(tempNode->leftChild->data ==searchKey){
			return tempNode->leftChild;
		}
		tempNode = tempNode->leftChild;
	}
	
	TreeNode* tempNode2 = root;
	
		while(tempNode2->rightChild != NULL){
		if(tempNode2->rightChild->data ==searchKey){
			return tempNode2->rightChild;
		}
		tempNode2 = tempNode2->rightChild;
	}
	


}



int main(){

    TreeNode* t = NULL;
    for(int i = 1; i < 20; i++){
        t = insert(t, i);
    }
    
    cout<<"\nINORDER TRAVERSAL\n";
    inOrderTraversal(t);
    cout<<"\nPOSTORDER TRAVERSAL\n";
    postOrderTraversal(t);
    cout<<"\nPREORDER TRAVERSAL\n";
    preOrderTraversal(t);
    
//    bool result = search(t, 85);
//    if(result){
//    	cout <<"\n\n\n Match found! \n";
//	} else {
//		cout <<"\n\n\n Match NOT found! \n";
//	}

TreeNode* temp = findAndReturnNode(t,1);
cout<< "\n\n" << temp->data << "\n";
cout<< "\n Left Child of found node: " << temp->leftChild->data << "\n";
cout<< "\n Left Child of found node: " << temp->rightChild->data << "\n";


    return 0;
}

