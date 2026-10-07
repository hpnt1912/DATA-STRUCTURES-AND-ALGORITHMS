#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	cin.ignore();
	vector<string> a(n);
	for (int i = 0; i < n; i++){
		getline(cin, a[i]);
	}
	
	int x, y;
	string s;
	cin >> x >> y;
	cin.ignore();
	cin >> s;
	
	bool check = false;
	for (int i = 0; i < n; i++){
		string A = a[i];
		stringstream ss(A);
		string t;
		vector<string> b;
		while(ss >> t){
			b.push_back(t);
		}
		int l = stoi(b[1]);
		if ((l >= x && l <= y) && (b[2] == s)){
			cout << b[0] << endl;
			check = true;
		}
	}
	
	if (!check){
		cout << "No suspects found";
	}
	return 0;
}






