#include <bits/stdc++.h>
using namespace std;

void nhap(int a[], int n){
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
}

int bi_search(int a[], int n, int d){
	int l = a[n-1];
	int r = 0;
	for (int i = 0; i < n; i++){
		r += a[i];
	}
	
	while(l < r){
		int cnt = 1;
		int m = (l + r) / 2;
		int temp = 0;
		for (int i = 0; i < n; i++){
		    if ((temp + a[i]) > m){
		    	cnt++;
		    	temp = 0;
		    	i -= 1;
			}
			else {
				temp += a[i];
			}
		}
		if (cnt <= d){
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}

int main(){
	int n; cin >> n;
	int d; cin >> d;
	int a[n];
	nhap(a, n);
	
	int w = bi_search(a, n, d);
	cout << w;
	return 0;
}











