#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	string x; cin >> x;
	bool check = false;
	for (int i = 0; i < n; i++){
		if (x == a[i]){
			check = true;
			break;
		}
	}
	if (check) cout << "YES";
	else cout << "NO";
	
	
	return 0;
}
