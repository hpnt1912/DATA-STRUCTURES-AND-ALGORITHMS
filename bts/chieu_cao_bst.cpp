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

int height(Node* root){
    if (root == nullptr) return -1;
    return 1 + max(height(root->left), height(root->right));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        Node* p = CreateNode(x);
        insertNode(root, p);
    }
    cout << height(root);
}