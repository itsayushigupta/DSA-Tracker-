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
     example:

              1                  ----level 0
        3           5            ----level 1
     7    11    17    null       ----level 2

     zig zag traversal = 1 5 3 7 11 17
     stored 1
     stored 5 3
     stored 7 11 17
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

/*
queue first will have the root of level 0
maintain a boolean variable flag which represents left to right as 1 and right to left as 0
after popping out root we have push back its child into the queue
children of root will be inserted in right to left form
further we will go left to right and this will go on till all the levels are traversed
*/

vector<int> zigzagTraversal(node* root) {
    vector<int> ans;
    if(root==NULL) {
        return ans;
    }

    queue<node*> q;
    q.push(root);

    bool leftToRight=true;
    //the flag will decide whether elements will be inserted in normal flow or the opposite flow that is right to left
    //elements will be inserted in 2 ways in the temp vector either left to right or right to left

    while(!q.empty()) {
       int total=q.size();

       //temporary vector for each level nodes
       vector<int> temp(total);

       //every level has to be processed
       for(int i=0; i<total; i++) {
            node* frontNode=q.front();
            q.pop();

            //determining in which order to fill elements
            int index=(leftToRight) ? i : (total-i-1);
            temp[index]=frontNode->data;

            if(frontNode->left != NULL) {
                q.push(frontNode->left);
            }

            if(frontNode->right != NULL) {
                q.push(frontNode->right);
            }
       }

       //after processing each level
       //direction change, negate the boolean variable
       leftToRight=!leftToRight;


       for(auto i: temp) {
            ans.push_back(i);
       }
    }
    return ans;
}

int main() {
    node* root=NULL;
    root=buildTree(root);
    zigzagTraversal(root);
}
