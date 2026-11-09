#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node*& root, Node* node){
	if (node == nullptr) return;
	if (root == nullptr) root = node;
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




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, createNode(data));
    }
    inorder(root);
    cout << "\n";
    return 0;
}

