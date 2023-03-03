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

// leaf nodes are the nodes which do not have any child node
// their left and right nodes have -1 that is NULL

void inorderTraversal(node* root, int &cnt) {
    //base case
    if(root==NULL) return;

    //recursive
    //left node right

    inorderTraversal(root->left, cnt);
    //leaf node condition
    if(root->left==NULL && root->right==NULL) {
        cnt++;
    }

    inorderTraversal(root->right, cnt);
}

int NumberOfLeafNodes(node* root) {
    int cnt=0;
    //doing by in order traversal
    //calling in order function
    inorderTraversal(root, cnt);
    return cnt;
}


int main() {
    node* root=NULL;
    root=buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"number of leaf nodes: "<<NumberOfLeafNodes(root);
}
