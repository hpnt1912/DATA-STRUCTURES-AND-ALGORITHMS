#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int x){
	Node* N = new Node();
	N->data = x;
	N->left = nullptr;
	N->right = nullptr;
	return N;
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


int findMin(Node* root){
	if (root == nullptr) return 0;
	Node* p = root;
	while (p->left != nullptr){
		p = p->left;
	}
	return p->data;
}

int findMax(Node* root){
	if (root == nullptr) return 0;
	Node* p = root;
	while (p->right != nullptr){
		p = p->right;
	}
	return p->data;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n; cin >> n;
	Node* root = nullptr;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		Node *p = CreateNode(x);
		insertNode(root, p);
	}
	cout << findMin(root) << " " << findMax(root);
	
	return 0;
}








