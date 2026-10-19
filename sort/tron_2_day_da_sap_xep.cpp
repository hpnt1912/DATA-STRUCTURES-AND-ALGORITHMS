#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> m;
	int b[m];
	for (int i = 0; i < m; i++){
		cin >> b[i];
	}
	
	int i = 0, j = 0;
	int t = n + m;
	int res[t];
	int k = 0;
	while (i < n && j < m){
		if (a[i] <= b[j]){
			res[k++] = a[i++];
		}
		else {
			res[k++] = b[j++];
		}
	}
	
	while (i < n){
		res[k++] = a[i++];
	}
	while (j < m){
		res[k++] = b[j++];
	}
	
	for (int i = 0; i < t; i++){
		cout << res[i] << " ";
	}
	
	return 0;
}
