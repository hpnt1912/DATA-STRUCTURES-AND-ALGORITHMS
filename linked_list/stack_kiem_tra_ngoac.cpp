
#include <iostream>
#include <string>
using namespace std;

// Implement a stack of characters yourself (array or linked list, do NOT use std::stack)
// and use it to write the function below:
//   bool isBalanced(const string& s)
//     Return true if the bracket string s is valid (every opener is closed by the
//     matching closer in the correct nesting order), otherwise false.


struct Node {
	char key;
	Node* next;
};

struct Stack {
	Node* top;
};

Node* CreateNode(char x){
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

bool isBalanced(string s){
	Stack a;
	CreateEmptyStack(a);
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
			Node *p = CreateNode(s[i]);
			Push(a, p);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
			if (a.top == nullptr) return false;
			if (s[i] == ')' && a.top->key != '(') return false;
			if (s[i] == ']' && a.top->key != '[') return false;
			if (s[i] == '}' && a.top->key != '{') return false;
			Pop(a);
		}
	}
	return a.top == nullptr;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << (isBalanced(s) ? "YES" : "NO") << '\n';

    return 0;
}

