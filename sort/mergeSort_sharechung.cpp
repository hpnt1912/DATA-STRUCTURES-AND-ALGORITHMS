#include <bits/stdc++.h>
#define ll long long
using namespace std;

void xuatMang(ll a[], ll n){
	for (ll i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void xuatVector(vector<ll> a, ll n){
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void merge(ll a[], ll l, ll m, ll r){
	vector<ll> x(a + l, a + m + 1);
	vector<ll> y(a + m + 1, a + r + 1);
	
	ll i = 0, j = 0;
	while (i < x.size() && j < y.size()){
		if (x[i] < y[j]){
			a[l++] = x[i++];
		}
		else {
			a[l++] = y[j++];
		}
	}
	
	while (i < x.size()){
		a[l++] = x[i++];
	}
	while (j < y.size()){
		a[l++] = y[j++];
	}
}

void mergeSort(ll a[], ll n){
	ll k = 1;
	
	cout << "Mang truoc khi sap xep:\n";
	xuatMang(a, n);
	cout << endl;
	
	cout << "Sap xep:\n";
	while (k < n){
		cout << "k = " << k << endl;
		cout << "Mang A (truoc khi chia): ";
		xuatMang(a, n);
		
		vector<ll> b, c;
		for (ll l = 0; l < n; l += k * 2){
			ll m = min(l + k - 1, n - 1);
			ll r = min(l + k * 2 - 1, n - 1);
			
			for (ll i = l; i <= m; i++) b.push_back(a[i]);
			for (ll i = m + 1; i <= r; i++) c.push_back(a[i]);
		}
		
		cout << "Mang B: ";
		xuatVector(b, b.size());
		cout << "Mang C: ";
		xuatVector(c, c.size());
		
		for (ll l = 0; l < n; l += k * 2){
			ll m = min(l + k - 1, n - 1);
			ll r = min(l + k * 2 - 1, n - 1);
			
			if (m < r) merge(a, l, m, r);
		}
		
		cout << "Mang A (sau khi gop): ";
		xuatMang(a, n);
		cout << endl;
		
		k *= 2;
	}
}

int main(){
	ll n; cin >> n;
	ll a[n];
	
	for (ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	mergeSort(a, n);
	
	cout << "Mang sau khi sap xep:\n";
	xuatMang(a, n);
	
	return 0;
}







