#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data=d;
        left=right=NULL;
    }
};

void preOrderTraversal(node* root,vector<int> & preOrder) {
    if(root==NULL) return;
    preOrder.push_back(root->data);
    preOrderTraversal(root->left,preOrder);
    preOrderTraversal(root->right,preOrder);
}

void inOrderTrav(node* root, vector < int > & inOrder) {
  if (root == NULL) return;
  inOrderTrav(root->left,inOrder);
  inOrder.push_back(root->data);
  inOrderTrav(root->right,inOrder);
}

void postOrderTrav(node* root, vector < int > & postOrder) {
  if (root == NULL) return;
  postOrderTrav(root->left,postOrder);
  postOrderTrav(root->right,postOrder);
  postOrder.push_back(root-> data);
}

int main() {
	class node * root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> left -> right = new node(5);
	root -> left -> right -> left = new node(8);
	root -> right -> left = new node(6);
	root -> right -> right = new node(7);
	root -> right -> right -> left = new node(9);
	root -> right -> right -> right = new node(10);

	vector<int> preOrder;
	preOrderTraversal(root, preOrder);
    cout << "The preOrder Traversal is : ";
	for (int i = 0; i < preOrder.size(); i++) cout << preOrder[i] << " ";

    	cout<<endl;

    vector < int > inOrder;
    inOrderTrav(root, inOrder);
    cout << "The inOrder Traversal is : ";
    for (int i = 0; i < inOrder.size(); i++) cout << inOrder[i] << " ";

        cout<<endl;

    vector < int > postOrder;
    postOrderTrav(root, postOrder);
    cout << "The postOrder Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++) cout << postOrder[i] << " ";

}
