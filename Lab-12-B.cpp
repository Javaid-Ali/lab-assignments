#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    int height;

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL
{
private:
    TreeNode *root;

    int getHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalance(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    TreeNode *insertHelper(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < node->data)
        {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertHelper(node->right, val);
        }
        else
        {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && val < node->left->data)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && val > node->right->data)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && val > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && val < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
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
            return;
        cout << node->data << "  ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(TreeNode *node)
    {
        if (node == nullptr)
            return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << "  ";
    }

    void levelOrderHelper(TreeNode *node)
    {
        if (node == nullptr)
            return;

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
    AVL()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        root = insertHelper(root, val);
    }

    void inorder()
    {
        cout << "---> Inorder <---\n";
        ;
        inorderHelper(root);
        cout << endl;
    }

    void preorder()
    {
        cout << "\n---> Preorder <---\n";
        ;
        preorderHelper(root);
        cout << endl;
    }

    void postorder()
    {
        cout << "\n---> Postorder <---\n";
        ;
        postorderHelper(root);
        cout << endl;
    }

    void levelOrder()
    {
        cout << "\n---> Level Order <---\n";
        ;
        levelOrderHelper(root);
        cout << endl;
    }
};

int main()
{
    cout << "\n----- Insert and Traverse for AVL Tree -----\n";
    AVL avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    avl.inorder();
    avl.preorder();
    avl.postorder();
    avl.levelOrder();

    return 0;
}