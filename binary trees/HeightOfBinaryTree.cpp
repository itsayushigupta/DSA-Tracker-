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

int heightRecursive(node* root) {
    if(root==NULL) return 0;
    int leftSide=heightRecursive(root->left);
    int rightSide=heightRecursive(root->right);
    int ans=max(leftSide, rightSide);
    return 1+ans;
}

int heightIterative(node* root) {
    //empty tree has 0 height
    if(root==NULL) return 0;
    //create an empty queue
    queue<node*> q;
    //inserting the root of the tree in the queue
    q.push(root);
    node* Front=NULL;
    int height=0;
    while(!q.empty()) {
        //find the total nodes at that current level
        int total=q.size();
        //loop will run for times=no of nodes at the current level
        while(total--) {
            Front=q.front();
            q.pop();
            if(Front->left != NULL)
                q.push(Front->left);
            if(Front->right != NULL)
                q.push(Front->right);
        }
        //increment height of the tree after every level
        height++;
    }
    return height;
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
	int height;
	cout<<"height of tree recursively= "<< heightRecursive(root);
	cout<<endl;
	cout<<"height of tree iteratively= "<< heightIterative(root);
}
