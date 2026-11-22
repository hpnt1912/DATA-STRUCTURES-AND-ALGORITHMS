#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int x){
    Node *N = new Node();
    N->data = x;
    N->left = N->right = nullptr;
    return N;
}

void insertNode(Node*& root, Node* node){
    if (node == nullptr) return;
    if (root == nullptr) {
        root = node;
        return;
    }
    if (node->data < root->data){
        if (root->left == nullptr){
            root->left = node;
        }
        else {
            insertNode(root->left, node);
        }
    }
    else if (node->data > root->data){
        if (root->right == nullptr){
            root->right = node;
        }
        else {
            insertNode(root->right, node);
        }
    }
}

void inorder(Node* root){
    if (root != nullptr){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node* findMin(Node* root){
    if (root == nullptr) return 0;
    Node* p = root;
    while (p->left != nullptr){
        p = p->left;
    }
    return p;
}

void xoaNode(Node*& root, Node* node){
    if (root == nullptr) return;
    if (root->data == node->data){
        bool check = false;
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        // Trường hợp 2: Node chỉ có 1 con (con phải)
        else if (root->left == nullptr){
            Node* t = root;
            root = root->right;
            delete t;
        }
        // Trường hợp 2: Node chỉ có 1 con (con trái)
        else if (root->right == nullptr){
            Node* t = root;
            root = root->left;
            delete t;
        }
        else {
            Node* p = findMin(root->right);
            root->data = p->data;
            xoaNode(root->right, p);
        }
    }
    else if (node->data < root->data) {
        xoaNode(root->left, node);
    }
    else {
        xoaNode(root->right, node);
    }
}

int main(){
    int n; cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        Node* p = CreateNode(x);
        insertNode(root, p);
    }
    int d; cin >> d;
    while (d--){
        int x; cin >> x;
        Node* t = CreateNode(x);
        xoaNode(root, t);
        delete t;

    }
    inorder(root);
    return 0;
}