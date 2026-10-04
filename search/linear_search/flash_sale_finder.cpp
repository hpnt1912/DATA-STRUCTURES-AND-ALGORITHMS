#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	cin.ignore();
	vector<string> a(n);
	
	for (int i = 0; i < n; i++){
		getline(cin, a[i]);
	}
	
	int x; cin >> x;
	cin.ignore();
	
	bool check = false;
	for (int i = 0; i < n; i++){
		string A = a[i];
		stringstream ss(A);
		string t;
		vector<string> b;
		while (ss >> t){
			b.push_back(t);
		}
		if (stoi(b[1]) < x){
			check = true;
			cout << b[0] << endl;
		}
	}
	if (!check){
		cout << "No items found";
	}
}
