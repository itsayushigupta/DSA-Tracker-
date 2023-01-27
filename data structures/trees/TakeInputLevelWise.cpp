#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this->data=data;
    }
};

TreeNode<int>* takeInputLevelWise() {

    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int> (rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {

        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;

        for(int i=0; i<numChild; i++) {
            int childData;
            cout<<"enter "<<i<< "th child of "<<front->data<<endl;
            cin>>childData;

            TreeNode<int>* child= new TreeNode<int> (childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int>* root) {
        //edge case
        if(root==NULL) return;
        //print root & print children nodes by recursion
        cout<<root->data<<":";
        // now call each child
        for(int i=0; i<root->children.size(); i++) {
            cout<<root->children[i]->data<<",";
        }
        cout<<endl;
        for(int i=0; i<root->children.size(); i++){
            printTree(root->children[i]);
        }
    }

int main(){

    TreeNode<int>* root=takeInputLevelWise();
    printTree(root);

    //TODO delete the tree

}


