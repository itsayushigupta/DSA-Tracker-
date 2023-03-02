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

/*
              1                  ----level 0
        3           5            ----level 1
     7    11    17    null       ----level 2
*/

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

//level order traversal is also known as breadth first search
//mostly solved by using queues

void PostOrderTraversal(node* root) {
    // left right node

    //base case
    if(root==NULL) return;
    //recursive
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main() {
    node* root=NULL;
    //creating a tree
    root=buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //post order
    PostOrderTraversal(root);
}
