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

bool findNode(Node* root, int x){
	Node* p = root;
	while (p != nullptr){
		if (x == p->data) return true;
		if (x < p->data) p = p->left;
		else p = p->right;
	}
	return false;
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
	int q;
	cin >> q;
	while (q--){
		int x; cin >> x;
		if (findNode(root, x)) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
