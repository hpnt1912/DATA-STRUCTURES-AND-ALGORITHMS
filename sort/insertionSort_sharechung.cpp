#include <bits/stdc++.h>
#define ll long long
using namespace std;

void xuat(ll a[], ll n){
	for (ll i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

void insertionSort(ll a[], ll n){
	cout << "Mang truoc khi sap xep:\n";
	xuat(a, n);
	cout << endl << endl;
	
	cout << "Sap xep:\n";
	for (ll i = 1; i < n; i++){
		cout << "i = " << i << endl;
		cout << "Mang truoc khi xu ly: ";
		xuat(a, n);
		cout << endl;
		ll x = a[i];
		cout << "Phan tu dang xet A[" << i << "] = " << x << endl;
		ll pos = i - 1;
		while(pos >= 0 && x < a[pos]){
			a[pos + 1] = a[pos];
			pos--;
		}
		cout << "Chen " << x << " vao vi tri k = " << pos + 1 << endl;
		a[pos + 1] = x;
		cout << "Mang sau khi xu ly: ";
		xuat(a, n);
		cout << endl << endl;
	}
	cout << "Mang sau khi sap xep:\n";
	xuat(a, n);
}


int main(){
	ll n; cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++){
		cin >> a[i];
	}
	insertionSort(a, n);
	return 0;
}
