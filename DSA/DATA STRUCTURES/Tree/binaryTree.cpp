#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Depth-First Traversal

void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// Breadth-First Traversal

void levelOrder(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}

// Insertion
Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        else
        {
            current->left = new Node(data);
            return root;
        }

        if (current->right != nullptr)
        {
            q.push(current->right);
        }
        else
        {
            current->right = new Node(data);
            return root;
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(50); // Root node

    // Level 1
    root->left = new Node(30);
    root->right = new Node(70);

    // Level 2
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // Level 3
    root->left->left->left = new Node(10);
    root->right->right->right = new Node(90);
    root->right->left->right = new Node(65);

    //
    //        50
    //       /  \
    //     30    70
    //    / \    / \
    //  20  40  60  80
    //  /        \   \
    // 10        65  90

    inOrder(root); // 10 20 30 40 50 60 65 70 80 90
    cout << endl;
    preOrder(root); // 50 30 20 10 40 70 60 65 80 90
    cout << endl;
    postOrder(root); // 10 20 40 30 65 60 90 80 70 50
    cout << endl;

    levelOrder(root); // 50 30 70 20 40 60 80 10 65 90
    cout << endl;
    insert(root, 35);
    levelOrder(root);
    return 0;
}