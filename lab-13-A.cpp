#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insertTree(Node* root, int d){
    if(root == NULL){
        return new Node(d);
    }

    if(d < root->data){
        root->left = insertTree(root->left, d);
    } else {
        root->right = insertTree(root->right, d);
    }

    return root;
};

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout << " " << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout << " " << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << " " << root->data << " ";
}

int main(){
    /* Three common DFS Traversal Method for Tree:
        i)   In-order   (left -> root -> right)
        ii)  Pre-order  (root -> left -> right)
        iii) Post-order (left -> right -> root)
    */
    cout << "\n----- 1-Insert and Traverse for DFS in Tree -----\n\n";

    Node* root = NULL;
    root = insertTree(root, 50);

    insertTree(root, 70);
    insertTree(root, 30);
    insertTree(root, 40);
    insertTree(root, 20);
    insertTree(root, 80);
    insertTree(root, 60);

    cout << "\nIn-Order   : ";
    inorder(root);
    cout << "\nPre-Order  : ";
    preorder(root);
    cout << "\nPost-Order : ";
    postorder(root);


    return 0;
}