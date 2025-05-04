#include<iostream>
#include<queue>
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

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        if(current->left == NULL){
            current->left = new Node(d);
            break;
        } else {
            q.push(current->left);
        }

        if(current->right == NULL){
            current->right = new Node(d);
            break;
        } else {
            q.push(current->right);
        }
    }

    return root;
}

void traverse(Node* root){
    if(root == NULL){
        return;
    }

    queue <Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if(current->left != NULL){
            q.push(current->left);
        }

        if(current->right != NULL){
            q.push(current->right);
        }
    }
}

int main(){
    /*  
    */
    cout << "\n----- 3-Insert and Traverse for BFS in Tree -----\n";

    Node* root = NULL;
    root = insertTree(root, 50);

    insertTree(root, 70);
    insertTree(root, 30);
    insertTree(root, 40);
    insertTree(root, 20);
    insertTree(root, 80);
    insertTree(root, 60);

    cout << "\nBFS Traversal : ";
    traverse(root);

    return 0;
}