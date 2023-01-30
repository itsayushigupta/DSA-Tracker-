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

//diameter is the longest path between any two nodes

//APPROACH 1- TC->O(n^2)
//option 1-we get diameter from the left subtree only
//option 2-we get diameter from the right subtree only
//option 3-we get diameter from both left and right subtrees
int height(node* node) {
    if(node==NULL) return 0;
    int lh=height(node->left);
    int rh=height(node->right);
    int h=max(lh,rh)+1;
    return h;
}
int diameter(node* root) {
    //base case
    if(root==NULL) return 0;
    int option1=diameter(root->left);
    int option2=diameter(root->right);
    int option3=height(root->left)+height(root->right);
    int answer=max(option1,max(option2,option3));
    return answer;
}

//APPROACH 2- TC->O(n)
//taking longest path on every node considering each node as the curve point
//create a pair (first block stores diameter and second block stores height)
pair<int,int> diameter2(node* root) {
    //base case
    if(root==NULL) {
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameter2(root->left);
    pair<int,int> right=diameter2(root->right);
    //since first block stores the diameter
    int op1=left.first;
    int op2=right.first;
    //since second block stores height so adding heights
    int op3=left.second+right.second+1;

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second, right.second)+1;
    return ans;
}

int diameterFast(node* root) {
    return diameter2(root).first-1;
    //since first part stores diameter so returning that only
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
	//int dia;
	cout<<"diameter of tree= "<<diameter(root);
	cout<<endl;
	cout<<"diameter of tree by optimised approach= "<<diameterFast(root);
}
