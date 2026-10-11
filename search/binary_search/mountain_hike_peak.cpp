#include <bits/stdc++.h>
using namespace std;

void nhap(vector<int> &a, int n){
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
}

int bi_search(vector<int> &a, int n){
	int l = 0, r = n - 1;
	int res = -1;
	if (n == 3) return a[1];
	while (l < r){
		int m = (r + l) / 2;
		res = max(res, a[m]);
		if ((m < n && m != 0) && res >= a[m+1] && res >= a[m-1]) return res;
		if (m != 0 && res < a[m-1]){
			r = m - 1;
		}
		else if (m < n && res < a[m+1]){
			l = m + 1;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
	int n; cin >> n;
	vector<int> a(n);
	nhap(a, n);
	
	cout << bi_search(a, n);
	
}
