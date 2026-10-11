#include <bits/stdc++.h>
using namespace std;

string res;

void nhap(vector<string> &a, int n){
	for (int i = 0; i < n*2; i++){
		cin >> a[i];
	}
}

bool bi_search(vector<string> &a, int n, string x){
	int l = 0, r = n - 1;
	while (l <= r){
		int m = l + (r - l) / 2;
		int pos = 2*m;
		if (a[pos] == x) {
			res = a[pos + 1];
			return true;
		}
		if (a[pos] < x){
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n; cin >> n;
	vector<string> a(2*n);
	nhap(a, n);
	string x; cin >> x;
	
	if (bi_search(a, n, x)) cout << res;
	else cout << "Not Found";
	
	return 0; 
}
