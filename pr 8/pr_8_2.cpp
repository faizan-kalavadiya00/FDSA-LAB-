#include <iostream>
using namespace std;

struct Node {
    long long code;
    Node* left;
    Node* right;

    explicit Node(long long value) : code(value), left(nullptr), right(nullptr) {}
};

Node* insertCode(Node* root, long long code, bool& inserted) {
    if (root == nullptr) {
        inserted = true;
        return new Node(code);
    }

    if (code < root->code) {
        root->left = insertCode(root->left, code, inserted);
    } else if (code > root->code) {
        root->right = insertCode(root->right, code, inserted);
    } else {
        // Book codes are intended to be unique, so ignore a duplicate code.
        inserted = false;
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->code << ' ';
    inorder(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter the number of book codes: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid number of book codes.\n";
        return 1;
    }

    Node* root = nullptr;
    cout << "Enter " << n << " book codes:\n";
    for (int i = 0; i < n; ++i) {
        long long code;
        if (!(cin >> code)) {
            cout << "Invalid input.\n";
            deleteTree(root);
            return 1;
        }

        bool inserted = false;
        root = insertCode(root, code, inserted);
        if (!inserted) {
            cout << "Duplicate code " << code << " ignored.\n";
        }
    }

    cout << "Book codes in ascending order (inorder traversal): ";
    if (root == nullptr) cout << "No book codes";
    else inorder(root);
    cout << '\n';

    deleteTree(root);
    return 0;
}
