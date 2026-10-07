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
		while (ss >> t){
			b.push_back(t);
		}
	}
	
	int Min = stoi(b[1]);
	for (int i = 3; i < n * 2; i += 2){
		int x = stoi(b[i]);
		Min = min(Min, x);
	}
	
	for (int i = 1; i < n * 2; i += 2){
		int x = stoi(b[i]);
		if (Min == x){
			cout << b[i-1];
			break;
		}
	}
	return 0;
}
