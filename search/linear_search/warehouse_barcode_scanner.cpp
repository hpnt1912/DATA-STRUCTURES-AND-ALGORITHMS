#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x; cin >> x;
	int res = -1;
	for (int i = 0; i < n; i++){
		if (x == a[i]){
			res = i + 1;
			break;
		}
	}
	cout << res;
	
	return 0;
}
