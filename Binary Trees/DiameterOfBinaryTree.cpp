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

//diameter is also known as width of tree
//number of nodes on the longest path between two end nodes

/*
APPROACH-1
time complexity=O(n^2) as height is also called
diameter can be found in three cases:
  1. only in left subtree
  2. only in right subtree
  3. both left and right subtree
*/
int height(node* node) {
    //base case
    if(node==NULL) return NULL;
    //recursive
    int leftHeight=height(node->left);
    int rightHeight=height(node->right);
    int ans=max(leftHeight, rightHeight);
    return (ans+1);
}

int diameter(node* root) {
    //base case
    if(root==NULL) return 0;

    //recursive
    //at every node we are doing three functions
    int option1=diameter(root->left);
    int option2=diameter(root->right);
    int option3=height(root->left)+height(root->right)+1;

    int ans=max(option1, max(option2, option3));
    return ans;
}

/*
APPROACH-2
time complexity=O(n)
to bring answer in O(n), remove height function
pair will return both diameter and height
first block of pair--->diameter
second block of pair--->height
*/

pair<int, int> diameterFast(node* root) {
    //base case
    if(root==NULL) {
        pair<int, int> p=make_pair(0,0);
        return p;
    }

    //recursive
    pair<int, int> left=diameterFast(root->left);
    pair<int, int> right=diameterFast(root->right);

    //first block of pair gives diameter
    int op1=left.first;
    int op2=right.first;
    //second block of pair gives height
    int op3=left.second + right.second + 1;

    pair<int, int> ans;
    ans.first=max(op1, max(op2, op3));
    ans.second=max(left.second, right.second) + 1;
    return ans;
}

int diaFast(node* root) {
    return diameterFast(root).first;
    //return first part as it stores diameter
}



int main() {
    node* root=NULL;
    root=buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"diameter: "<<diameter(root)<<endl;
    cout<<"diameter: "<<diaFast(root);
}
