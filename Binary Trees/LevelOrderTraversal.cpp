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

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);

    //creating a separator after inserting root
    q.push(NULL);

    while(!q.empty()) {
        node* temp=q.front();
        q.pop();

        if(temp==NULL) {
            //it means old level has been traversed fully
            //enter next line
            cout<<endl;
            if(!q.empty()) {
                //queue still has some child nodes
                //create another separator
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main() {
    node* root=NULL;
    //creating a tree
    root=buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level order
    levelOrderTraversal(root);
}
