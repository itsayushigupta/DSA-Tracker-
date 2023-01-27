#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data=d;
        left=right=NULL;
    }
};

void LevelOrderTraversal(node* root,vector<vector<int> > & LevelOrder) {
    if(root==NULL) return ;
    queue<node*> q;
    //put the root of the tree in the queue as the first element
    q.push(root);
    while(!q.empty()) {
        int Size=q.size();
        vector<int> level;
        for(int i=0; i<Size; i++) {
            node *curr= q.front();
            q.pop();
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
            level.push_back(curr->data);
        }
        LevelOrder.push_back(level);
    }

}

int main() {
	class node * root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> left -> right = new node(5);
	root -> left -> right -> left = new node(8);
	root -> right -> left = new node(6);
	root -> right -> right = new node(7);
	root -> right -> right -> left = new node(9);
	root -> right -> right -> right = new node(10);

	vector<vector<int> > LevelOrder;

	LevelOrderTraversal(root, LevelOrder);
	int total=LevelOrder.size();
    cout << "The Level Order Traversal is : " << endl;

	for (int i=0; i<LevelOrder.size(); i++)  {
		for(int j =0;j<LevelOrder[i].size();j++)
			cout << LevelOrder[i][j] << " ";

		cout << endl;
	}
}
