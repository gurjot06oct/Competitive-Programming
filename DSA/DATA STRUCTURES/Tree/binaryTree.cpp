#include <iostream>
#include <queue>
#include<stack>
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

void inOrderIterative(Node* root) {
    std::stack<Node*> auxStack;
    Node* current = root;

    while (current != nullptr || !auxStack.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            auxStack.push(current);
            current = current->left;
        }

        // Current must be nullptr at this point
        current = auxStack.top();
        auxStack.pop();

        // Visit the node
        std::cout << current->data << " ";

        // Go to the right subtree
        current = current->right;
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
void preOrderIterative(Node* root) {
    if (root == nullptr) return;

    std::stack<Node*> auxStack;
    Node* node;
    auxStack.push(root);

    while (!auxStack.empty()) {
        node = auxStack.top();
        auxStack.pop();

        // Visit the node
        std::cout << node->data << " ";

        // Push right child first so that left child is processed first
        if (node->right != nullptr) {
            auxStack.push(node->right);
        }

        if (node->left != nullptr) {
            auxStack.push(node->left);
        }
    }
}
void preorderTraversalOptimal(Node* root) {
    if (root == nullptr) return;

    std::stack<Node*> auxStack; // Stack to store right children
    Node* current = root;

    // Run till stack is not empty or current is not NULL
    while (!auxStack.empty() || current != nullptr) {
        // Print left children while they exist and keep pushing right into the stack
        while (current != nullptr) {
            std::cout << current->data << " ";
            
            if (current->right != nullptr) {
                auxStack.push(current->right);
            }
            
            current = current->left;
        }
        
        // We reach when current is NULL, so we take out a right child from the stack
        if (!auxStack.empty()) {
            current = auxStack.top();
            auxStack.pop();
        }
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

void postOrderTraversal_twoStack(Node* root) {
    if (root == nullptr) return;

    std::stack<Node*> stack1, stack2;

    // Push root to the first stack
    stack1.push(root);

    // Run while the first stack is not empty
    while (!stack1.empty()) {
        // Pop a node from the first stack and push it onto the second stack
        Node* node = stack1.top();
        stack1.pop();
        stack2.push(node);

        // Push left and right children of the popped node onto the first stack
        if (node->left) {
            stack1.push(node->left);
        }
        if (node->right) {
            stack1.push(node->right);
        }
    }

    // The second stack contains the nodes in postorder, so we print them
    while (!stack2.empty()) {
        Node* node = stack2.top();
        stack2.pop();
        std::cout << node->data << " ";
    }
}
void postOrderTraversal_oneStack(Node* root) {
    if (root == nullptr) return;

    std::stack<Node*> st;
    Node* current = root;
    Node* lastVisited = nullptr;

    while (!st.empty() || current != nullptr) {
        // Go to the leftmost node
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        // Peek the node at the top of the stack
        Node* topNode = st.top();

        // If the right child exists and traversing from the left child, move to the right child
        if (topNode->right != nullptr && lastVisited != topNode->right) {
            current = topNode->right;
        } else {
            // Visit the node
            std::cout << topNode->data << " ";
            lastVisited = topNode;
            st.pop();
        }
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

    inOrderIterative(root); // 10 20 30 40 50 60 65 70 80 90
    cout << endl;
    preorderTraversalOptimal(root); // 50 30 20 10 40 70 60 65 80 90
    cout << endl;
    postOrderTraversal_oneStack(root); // 10 20 40 30 65 60 90 80 70 50
    cout << endl;
    levelOrder(root); // 50 30 70 20 40 60 80 10 65 90
    cout << endl;
    insert(root, 35);
    levelOrder(root);
    return 0;
}