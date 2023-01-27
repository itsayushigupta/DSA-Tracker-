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

vector<int> preOrderTrav(node* root, vector<int> & preOrder) {
    if(root==NULL) return preOrder;
    stack<node*> s;
    s.push(root);
    while(!s.empty()) {
        node* topNode=s.top();
        preOrder.push_back(topNode->data);
        s.pop();
        if(topNode->right != NULL) s.push(topNode->right);
        if(topNode->left != NULL) s.push(topNode->left);
    }
    return preOrder;
}



vector<int> inOrderTrav(node* root, vector<int> & inOrder) {
    stack<node*> s1;
    while(true) {
        if(root != NULL) {
            s1.push(root);
            root=root->left;
        }
        else {
            if(s1.empty()) break;
            root=s1.top();
            inOrder.push_back(root->data);
            s1.pop();
            root=root->right;
        }
    }
    return inOrder;
}



vector<int> postOrderTrav(node* root, vector<int> & postOrder) {
    if(root==NULL) return postOrder;
    stack<node*> s2;
    stack<node*> s3;
    s2.push(root);
    while(!s2.empty()) {
        root=s2.top();
        s2.pop();
        s3.push(root);
        if(root->left != NULL) s2.push(root->left);
        if(root->right != NULL) s2.push(root->right);
    }
    while(!s3.empty()) {
        postOrder.push_back(s3.top()->data);
        s3.pop();
    }
    return postOrder;
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
	preOrderTrav(root, preOrder);
    cout << "The preOrder Traversal is : ";
	for (int i = 0; i < preOrder.size(); i++) cout << preOrder[i] << " ";

    	cout<<endl;

    vector<int> inOrder;
    inOrderTrav(root, inOrder);
    cout << "The inOrder Traversal is : ";
    for (int i = 0; i < inOrder.size(); i++) cout << inOrder[i] << " ";

        cout<<endl;

    vector < int > postOrder;
    postOrderTrav(root, postOrder);
    cout << "The postOrder Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++) cout << postOrder[i] << " ";

}
