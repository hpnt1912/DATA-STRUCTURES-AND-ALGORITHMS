#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int m; cin >> m;
	cin.ignore();
	vector<string> b(m);
	for (int i = 0; i < m; i++){
		getline(cin, b[i]);
	}
	
	bool found = false;
	for (int i = 0; i < m; i++){
		string A = b[i];
		stringstream ss(A);
		string t;
		while (ss >> t){
			bool check = false;
			for (int j = 0; j < n; j++){
				if (t == a[j] && check == false){
					cout << i + 1 << endl;
					check = true;
					found = true;
					break;
				}
			}
			if (check) break;
		}
	}
	if (!found){
		cout << "No spam found";
	}
}
