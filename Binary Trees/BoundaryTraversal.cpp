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

/*
Left boundary nodes: defined as the path from the root to the left-most node
i.e- leaf node you could reach when you always travel preferring left subtree over right subtree.

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root.
The right-most node is leaf node you reach when you always travel preferring right subtree over left subtree.
Exclude root from this as it was already included in traversal of left boundary nodes.
*/

void traverseLeft(node* root, vector<int> &ans) {
    //base case
    if((root==NULL) || (root->left==NULL && root->right==NULL)) return;
    //store the node value in the answer
    ans.push_back(root->data);
    //check if left and right nodes exist
    if(root->left) traverseLeft(root->left, ans);
    else traverseLeft(root->right, ans);
}

void traverseLeafNodes(node* root, vector<int> &ans) {
    //base case
    if(root==NULL) return;
    //if it is a leaf node, store it
    if(root->left==NULL && root->right==NULL) {
        ans.push_back(root->data);
        return;
    }
    traverseLeafNodes(root->left, ans);
    traverseLeafNodes(root->right, ans);
}

void traverseRight(node* root, vector<int> &ans) {
    //base case
    if((root==NULL) || (root->left==NULL && root->right==NULL)) return;
    //check if left and right nodes exist
    if(root->right) traverseRight(root->right, ans);
    else traverseLeft(root->left, ans);
    //store the node value in the answer
    ans.push_back(root->data);
}

vector<int> BoundaryTraversal(node* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    ans.push_back(root->data);

    //left part of the tree
    traverseLeft(root->left, ans);

    //traverse Leaf Nodes
    //left subtree
    traverseLeafNodes(root->left, ans);
    //right subtree
    traverseLeafNodes(root->right, ans);

    //traverse right part
    traverseRight(root->right, ans);

    return ans;
}

int main() {
    node* root=NULL;
    root=buildTree(root);
    vector<int> ans = BoundaryTraversal(root);
    for(auto i: ans) {
        cout<<i<<" ";
    }
}
