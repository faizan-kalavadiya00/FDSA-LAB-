#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


Node* buildTree() {
    int value;
    if (!(cin >> value)) {
        return nullptr;
    }
    if (value == -1) {
        return nullptr;
    }

    Node* root = new Node(value);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> pending;
    pending.push(root);
    while (!pending.empty()) {
        Node* current = pending.front();
        pending.pop();
        cout << current->data << ' ';

        if (current->left != nullptr) pending.push(current->left);
        if (current->right != nullptr) pending.push(current->right);
    }
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    cout << "Enter the tree in preorder (-1 for a null child):\n";
    Node* root = buildTree();

    cout << "Inorder (Left, Root, Right): ";
    if (root == nullptr) cout << "Tree is empty";
    else inorder(root);
    cout << '\n';

    cout << "Preorder (Root, Left, Right): ";
    if (root == nullptr) cout << "Tree is empty";
    else preorder(root);
    cout << '\n';

    cout << "Postorder (Left, Right, Root): ";
    if (root == nullptr) cout << "Tree is empty";
    else postorder(root);
    cout << '\n';

    cout << "Level order (top to bottom): ";
    if (root == nullptr) cout << "Tree is empty";
    else levelOrder(root);
    cout << '\n';

    deleteTree(root);
    return 0;
}
