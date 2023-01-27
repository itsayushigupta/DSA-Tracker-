#include<iostream>
#include<vector>
using namespace std;
//keep address of root like address of head in ll

template<typename T>
class TreeNode {
public:
    T data;   // to store data for each node
    vector<TreeNode<T>*> children;      // to store children for each node

    TreeNode(T data) {     // constructor to initialize data
        this->data=data;
    }
};


    TreeNode<int>* takeInput() {
        int rootData;
        cout<<"enter data"<<endl;
        cin>>rootData;
        TreeNode<int>* root=new TreeNode<int> (rootData);   // dynamic allocation of root node

        int n;
        cout<<"enter number of children of "<<rootData<<endl;
        cin>>n;
        for(int i=0;i<n; i++){
            TreeNode<int>* child=takeInput();                // static allocation
            root->children.push_back(child);
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
    /*
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    //Linking the root node and child nodes ie node1 and node2
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int>* root=takeInput();
    printTree(root);

    //TODO delete the tree

}
