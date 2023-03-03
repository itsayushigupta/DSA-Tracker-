#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root) {
    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1) return NULL;

    cout<<"enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
}

//height is the longest distance between root node and leaf node
//find the height of left and right subtree
//return the maximum of the two heights and add one(root node)


int height(node* node) {
    //base case
    if(node==NULL) {
        return NULL;
    }
    //recursive
    int leftHeight=height(node->left);
    int rightHeight=height(node->right);

    int ans=max(leftHeight, rightHeight);
    return (ans+1);
}

int main() {
    node* root=NULL;
    root=buildTree(root);
    cout<<"height: "<<height(root);
}
