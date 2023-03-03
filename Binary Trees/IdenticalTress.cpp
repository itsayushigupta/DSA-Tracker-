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

bool isIdentical(node* root1, node* root2) {
    //base case
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL && root2!=NULL) return false;
    if(root1!=NULL && root2==NULL) return false;

    bool left=isIdentical(root1->left, root2->left);
    bool right=isIdentical(root1->right, root2->right);
    bool value=(root1->data)==(root2->data);

    if(left&&right&&value) return true;
    else return false;
}

int main() {
    node* root1=NULL;
    root1=buildTree(root1);
    cout<<endl<<endl;
    node* root2=NULL;
    root2=buildTree(root2);
    cout<<endl<<endl;
    cout<<"are trees identical or not: "<<isIdentical(root1, root2);
}
