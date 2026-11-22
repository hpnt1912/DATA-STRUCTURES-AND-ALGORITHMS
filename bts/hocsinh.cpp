#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;
}

struct TNode {
    Hocsinh data;
    TNode * left, * right;
};

typedef TNode * TREE;

void CreateTree(TREE &r) {
    r = NULL;
}

TNode * CreateTNode(Hocsinh x) {
    TNode * p = new TNode;
    if (p == NULL) exit(1);
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void InsertNode(TREE &t, TNode *p) {
    if (t == NULL) {
        t = p;
        return;
    }
    if (p->data.Ten < t->data.Ten || 
       (p->data.Ten == t->data.Ten && p->data.Hodem < t->data.Hodem)) {
        InsertNode(t->left, p);
    } else if (p->data.Ten > t->data.Ten || 
              (p->data.Ten == t->data.Ten && p->data.Hodem > t->data.Hodem)) {
        InsertNode(t->right, p);
    }
}

void nhap(TREE& t){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        Hocsinh x;
        InputElement(x);
        TNode* p = CreateTNode(x);
        InsertNode(t, p);
    }
}

void LNR(TREE t){
    if (t != nullptr){
        LNR(t->left);
        OutputElement(t->data);
        LNR(t->right);
    }
}

int main(){
    TREE t;
    CreateTree(t);
    nhap(t);
    LNR(t);
}


