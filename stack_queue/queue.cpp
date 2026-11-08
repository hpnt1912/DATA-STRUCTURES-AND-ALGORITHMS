
#include <iostream>
#include <string>
using namespace std;

// Implement an integer queue yourself (circular array or linked list, FIFO,
// do NOT use std::queue) providing the following operations:
//   void enqueue(int x)   - add x to the back
//   bool emptyQueue()     - return true if the queue is empty
//   int  frontValue()     - return the front value (the queue is non-empty)
//   int  dequeue()        - remove and return the front value (the queue is non-empty)
//   int  sizeQueue()      - return the number of elements currently in the queue

struct Node {
	int key;
	Node* next;
};

struct Queue {
	Node* top;
	Node* back;
};

Queue &q;

Node* CreateNode(int x){
	Node *p = new Node;
	p->key = x;
	p->next = nullptr;
	return p;
}

bool emptyQueue(){
	if (q->back == nullptr) return true;
	return false;
}

void enquete(int x){
	Node *p = CreateNode(x);
	if (emptyQueue){
		q->back = p;
		q->top = q->back;
	}
	else {
		q.top = 
	}
}

void enqueue(Stack &s, Node *p){
	if (s.top == nullptr){
		s.top = p;
	}
	else {
		p->next = s.top; 
		s.top = p;
	}
}

int  frontValue(){
	if (emptyQueue) return 0;
	else {
		return q->back;
	}
}

int  dequeue(){
	if (emptyQueue) return 0;
	else {
		
	}
}


void Pop(Stack &s){
	if (s.top == nullptr) return;
	Node *temp = s.top;
	s.top = s.top->next;
	delete temp;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ENQUEUE") {
            int x;
            cin >> x;
            enqueue(x);
        } else if (cmd == "DEQUEUE") {
            if (emptyQueue()) cout << "EMPTY\n";
            else cout << dequeue() << '\n';
        } else if (cmd == "FRONT") {
            if (emptyQueue()) cout << "EMPTY\n";
            else cout << frontValue() << '\n';
        } else {
            cout << sizeQueue() << '\n';
        }
    }

    return 0;
}

