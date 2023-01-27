#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data=d;
        left,right=NULL;
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
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);            //insert root in the queue
    q.push(NULL);
    while(!q.empty()) {     //till the time queue is not empty
        node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp==NULL) {     //this means poorana level poora traverse ho chuka hai
            cout<<endl;
            if(!q.empty()) {     //this means queue still has some child nodes
               q.push(NULL);
            }
        }

        else {
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

}

int main() {
    node* root=NULL;
    //creating a tree
    root=buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);     //level order traversal

}
