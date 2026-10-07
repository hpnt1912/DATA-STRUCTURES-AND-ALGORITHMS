#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	cin.ignore();
	vector<string> a(n);
	for (int i = 0; i < n; i++){
		getline(cin, a[i]);
	}
	
	vector<string> b;
	for (int i = 0; i < n; i++){
		string A = a[i];
		stringstream ss(A);
		string t;
		while(ss >> t){
			b.push_back(t);
		}
	}
	
	int Max = -1;
	for (int i = 1; i < n*3; i += 3){
		int x = stoi(b[i]);
		int y = stoi(b[i + 1]);
		if (y == 0){
			Max = max(Max, x);
		}
	}
	
	bool check = false;
	for (int i = 1; i < n*3; i += 3){
		int x = stoi(b[i]);
		int y = stoi(b[i + 1]);
		if (Max == x && y == 0){
			cout << b[i - 1];
			check = true;
			break;
		}
	}
	
	if (!check && Max == -1){
		cout << "All patients seen";
	}
	return 0;
}
