
#include <iostream>
using namespace std;

// Implement a stack of int yourself (array or linked list, do NOT use std::stack)
// and use it to write the function below:
//   void printBinary(int n)
//     Print the binary representation of n (no leading zeros), followed by a newline.
//     Hint: push n % 2, then n /= 2; finally pop the bits to print them (LIFO).

struct Node {
	int key;
	Node* next;
};

struct Stack {
	Node* top;
};

Node* CreateNode(int x){
	Node *p = new Node;
	p->key = x;
	p->next = nullptr;
	return p;
}

void CreateEmptyStack(Stack &s){
	s.top = nullptr;
}

void Push(Stack &s, Node *p){
	if (s.top == nullptr){
		s.top = p;
	}
	else {
		p->next = s.top; 
		s.top = p;
	}
}

void Pop(Stack &s){
	if (s.top == nullptr) return;
	Node *temp = s.top;
	s.top = s.top->next;
	delete temp;
}

void duyetStack(Stack s){
	if (s.top == nullptr) return;
	Node *p = s.top;
	while (p != nullptr){
		cout << p->key;
		p = p->next;
	}
}

void printBinary(int n){
	Stack s;
	CreateEmptyStack(s);
	while (n > 0){
		int temp = n % 2;
		Node *p = CreateNode(temp);
		Push(s, p);
		n /= 2;
	}
	duyetStack(s);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    printBinary(n);

    return 0;
}

