
#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void ReverseLL(LIST &);

void AddHead(LIST &L, NODE* p){
	if (L.pHead == nullptr){
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		p->pNext = L.pHead;
		L.pHead = p;
	}
}

void ReverseLL(LIST &L){
	LIST T;
	CreateEmptyList(T);
	NODE *p = L.pHead;
	while (p != nullptr){
		NODE *next = p->pNext;
		p->pNext = nullptr;
		AddHead(T, p);
		p = next;
	}
	L = T;
}



int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    ReverseLL(L);
    PrintList(L);
    return 0;
}

