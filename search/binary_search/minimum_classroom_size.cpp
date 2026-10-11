#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int x; cin >> x;
	
	int res = -1;
	
	int l = 0, r = n - 1;
	
	while (l < r){
		int m = l + (r - l) / 2;
		if (a[m] == x){
			res = x;
			break;
		}
		if (a[m] >= x){
			r = m;
	    }
		else {
			l = m + 1;
		}
	}
	if (a[l] >= x) res = a[l];
	
	if (res == -1) cout << "No suitable classroom";
	else cout << res;
	
	return 0;
}








