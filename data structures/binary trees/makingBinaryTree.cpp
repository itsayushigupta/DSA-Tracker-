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

    }
};

int main() {
    class node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);

}
