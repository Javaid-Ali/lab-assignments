#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    TreeNode *root;

    TreeNode *insertHelper(TreeNode *node, int d)
    {
        if (node == nullptr)
        {
            return new TreeNode(d);
        }

        if (d < node->data)
        {
            node->left = insertHelper(node->left, d);
        }
        else if (d > node->data)
        {
            node->right = insertHelper(node->right, d);
        }

        return node;
    }

    void inorderHelper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        inorderHelper(node->left);
        cout << node->data << "  ";
        inorderHelper(node->right);
    }

    void preorderHelper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->data << "  ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(TreeNode *node)
    {
        if (node == nullptr){
            return;
        }

        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << "  ";
    }

    void levelOrderHelper(TreeNode *node)
    {
        if (node == nullptr){
            return;
        }

        queue<TreeNode *> q;
        q.push(node);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            cout << current->data << "  ";

            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int d)
    {
        root = insertHelper(root, d);
    }

    void inorder()
    {
        cout << "---> Inorder <---\n";
        inorderHelper(root);
        cout << endl;
    }

    void preorder()
    {
        cout << "\n---> Preorder <---\n";
        preorderHelper(root);
        cout << endl;
    }

    void postorder()
    {
        cout << "\n---> Postorder <---\n";
        postorderHelper(root);
        cout << endl;
    }

    void levelOrder()
    {
        cout << "\n---> Level Order <---\n";
        levelOrderHelper(root);
        cout << endl;
    }
};

int main()
{
    cout << "\n----- Insert and Traverse for BST -----\n\n";
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.inorder();
    bst.preorder(); 
    bst.postorder();
    bst.levelOrder();

    return 0;
}