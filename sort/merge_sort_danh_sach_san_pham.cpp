

#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    int ma;
    string ten;
    int gia;
};

void merge(SanPham *a, int l, int m, int r){
	int size1 = m - l + 1;
	int size2 = r - m;
	SanPham *x = new SanPham[size1];
	SanPham *y = new SanPham[size2];
	
	for (int i = 0; i < size1; i++){
		x[i] = a[l + i];
	}
	int t = 0;
	for (int i = 0; i < size2; i++){
		y[i] = a[m + 1 + i];
	}
	
	int i = 0, j = 0;
	while(i < size1 && j < size2){
		if (x[i].gia == y[j].gia){
			if (x[i].ma < y[j].ma){
				a[l++] = x[i++];
			}
			else {
				a[l++] = y[j++];
			}
		}
		else if (x[i].gia < y[j].gia){
			a[l++] = x[i++];
		}
		else {
			a[l++] = y[j++];
		}
	}
	
	while (i < size1){
		a[l++] = x[i++];
	}
	while(j < size2){
		a[l++] = y[j++];
	}
	
	delete[] x;
	delete[] y;
}

void mergeSort(SanPham *a, int l, int r){
	if (l >= r) return;
	int m = (l + r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SanPham* a = new SanPham[n];
    for (int i = 0; i < n; i++) cin >> a[i].ma >> a[i].ten >> a[i].gia;

    if (n > 0) mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].ma << ' ' << a[i].ten << ' ' << a[i].gia << '\n';
    }
    return 0;
}

