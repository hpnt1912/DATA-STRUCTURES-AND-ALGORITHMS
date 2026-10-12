#include <bits/stdc++.h>
#define ll long long
using namespace std;

void SelectionSort(ll a[], ll n){
	cout << "Sap xep:\n";
	
	for (ll i = 0; i < n - 1; i++){
		ll Min = LLONG_MAX;
		cout << "i = " << i << endl;
		cout << "Mang truoc khi swap: ";
		for (ll k = 0; k < n; k++){
			cout << a[k] << " ";
		}
		cout << endl;
		
		ll minIndex = i;
		for (ll j = i + 1 ; j < n; j++){
			if (a[j] < a[minIndex]) minIndex = j;
		}
		cout << "Phan tu nho nhat trong doan [" << i + 1 << ", " << n - 1 << "]: " << a[minIndex] << endl;
		cout << "Swap " << a[i] << " va " << a[minIndex] << endl;
		swap(a[i], a[minIndex]);
			
		cout << "Mang sau khi swap: ";
		for (int l = 0; l < n; l++){
			cout << a[l] << " ";
		}
		cout << endl << endl;
	}
	
	cout << "Mang sau khi sap xep:\n";
	for (ll i = 0 ; i < n; i++){
		cout << a[i] << " ";
	}
}

int main(){
	ll n; cin >> n;
	ll a[n];
	
	for (ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cout << "Mang truoc khi sap xep:\n";
	for (ll i = 0 ; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl << endl;
	
	SelectionSort(a, n);
	
	return 0;
}
