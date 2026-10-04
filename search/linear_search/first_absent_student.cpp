#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	cin.ignore();
	vector<string> a(n);
	int cnt = 0;
	string res = "";
	for (int i = 0; i < n; i++){
		getline(cin, a[i]);
		if (a[i].back() == 'A' && cnt == 0){
			cnt = 1;
			for (int j = 0; j <= a[i].size() - 2; j++){
				res += a[i][j];
			}
		}
	}
	
	if (res == ""){
		cout << "All Present";
	}
	else {
		cout << res;
	}
	
	return 0;
}
