
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

void NhapNgay(NGAY &);
void XuatNgay(NGAY );
void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN );
NODE* CreateNode(SINHVIEN );
void CreateEmptyList(LIST &);
void AddTail(LIST&, NODE* );
void XuatDS(LIST );
void NhapDS(LIST &, int n);
bool Xoa_TheoHoTen(LIST &, string);

int main() {
    LIST L;
    int n;
    string hoten;

    getline(cin, hoten);
    cin >> n ;

    NhapDS(L, n);

    Xoa_TheoHoTen(L, hoten);

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
	if (L.pHead == nullptr){
		cout << "Empty List.";
		return;
	}
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

bool Xoa_TheoHoTen(LIST &l, string ten){
	if (l.pHead == nullptr){
		return false;
	}
	NODE* p = l.pHead;
	NODE *t = p->pNext;
	if (t == nullptr){
		if (l.pHead->key.HoTen == ten){
			l.pHead = nullptr;
			delete l.pHead;
			return true;
		}
		return false;
	}
	while (t != nullptr){
		if (p == l.pHead && p->key.HoTen == ten){
			l.pHead = p->pNext;
			delete p;
		}
		else if (t == l.pTail && t->key.HoTen == ten){
			l.pTail = p;
			p->pNext = nullptr;
			delete t;
			break;
		}
		else if (t->key.HoTen == ten){
			NODE *temp = t;
			p->pNext = t->pNext;
			temp->pNext = nullptr;
			delete temp;
		}
		p = p->pNext;
		t = p->pNext;
	}
	return true;
}









