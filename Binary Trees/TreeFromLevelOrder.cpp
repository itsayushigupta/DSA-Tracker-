#include<iostream>
#include<queue>
using namespace std;

class node{
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

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"enter data for root: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp=q.front();
        q.pop();

        cout<<"enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

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

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //creating tree from level order traversal
    buildFromLevelOrder(root);
    //printing the tree from level order traversal
    levelOrderTraversal(root);
}
