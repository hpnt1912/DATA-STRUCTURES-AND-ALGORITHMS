
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);
NODE* CreateNode(SINHVIEN x);
void CreateEmptyList(LIST &L);
void AddTail(LIST& l, NODE* p);
void XuatDS(LIST L);
void NhapDS(LIST &L, int n);
void ChenGiam(LIST &, SINHVIEN);

int main() {
    LIST L;
    int n;
    SINHVIEN sv;

    NhapSinhVien(sv);

    cin >> n ;
    NhapDS(L, n);

    ChenGiam(L, sv);

    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}

NODE* CreateNode(SINHVIEN x){
	NODE* p = new NODE;
	p->key = x;
	p->pNext = nullptr;
	return p;
}

void AddTail(LIST& l, NODE* p){
	if (l.pHead == nullptr){
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void CreateEmptyList(LIST &L){
	L.pHead = nullptr;
	L.pTail = nullptr;
}

void XuatDS(LIST L){
	NODE* p = L.pHead;
	while (p != nullptr){
		XuatSinhVien(p->key);
		cout << endl;
		p = p->pNext;
	}
}

void NhapDS(LIST &L, int n){
	CreateEmptyList(L);
	for (int i = 0; i < n; i++){
		cout << endl;
		SINHVIEN x;
		NhapSinhVien(x);
		NODE *p = CreateNode(x);
		AddTail(L, p);
	}
}

void ChenGiam(LIST &L, SINHVIEN x){
	NODE *p = CreateNode(x);
	if (L.pHead == nullptr){
		AddTail(L, p);
		return;
	}
	NODE *q = L.pHead;
	NODE *t = q->pNext;
	if (t == nullptr){
		if (q->key.MASV >= p->key.MASV) AddTail(L, p);
		else {
			p->pNext = q;
			L.pHead = p;
		}
		return;
	}
	while (t != nullptr){
		if (q == L.pHead && p->key.MASV > q->key.MASV){
			p->pNext = q;
			L.pHead = p;
			break;
		}
		else if (t == L.pTail && t->key.MASV >= p->key.MASV){
			AddTail(L, p);
			break;
		}
		else if (p->key.MASV > t->key.MASV){
			q->pNext = p;
			p->pNext = t;
			break;
		}
		q = t;
		t = t->pNext;
	}
}










