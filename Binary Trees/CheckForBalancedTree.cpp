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

//a tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of a tree
//absolute(height(left)-height(right))) <= 1

//APPROACH-1
//time complexity=O(n^2)
int height(node* node) {
    //base case
    if(node==NULL) {
        return 0;
    }
    //recursive
    int leftHeight=height(node->left);
    int rightHeight=height(node->right);

    int ans=max(leftHeight, rightHeight);
    return (ans+1);
}

bool isBalanced(node* root) {
    //base case
    if(root==NULL) {
        return true;
    }
    //recursive (2 conditions)
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    //third condition
    bool diff=abs(height(root->left)-height(root->right))<=1;

    if(left && right && diff) {
        return true;
    }
    else {
        return false;
    }
}

//APPROACH-2
//time complexity=O(n)
//pair stores true/false and height, first block stores if balanced or not and second block stores the height

pair<bool, int> balancedFast(node* root) {
    //base case
    if(root==NULL) {
        pair<bool, int> p=make_pair(true,0);
        return p;
    }

    //recursive
    pair<int, int> left=balancedFast(root->left);
    pair<int, int> right=balancedFast(root->right);

    //first block of pair gives bool answer
    bool leftAns=left.first;
    bool rightAns=right.first;
    //second block of pair gives height
    bool diff=abs(left.second-right.second)<=1;

    pair<bool, int> ans;
    ans.second=max(left.second, right.second)+1;

    if(leftAns && rightAns && diff) {
        ans.first=true;
    }
    else {
        ans.first=false;
    }
    return ans;
}

int Fast(node* root) {
    //first block stores if balanced or not
    return balancedFast(root).first;
}

int main() {
    node* root=NULL;
    root=buildTree(root);
    cout<<"is tree balanced or not: "<<isBalanced(root);
    cout<<endl;
    cout<<"is tree balanced or not: "<<Fast(root);
}
