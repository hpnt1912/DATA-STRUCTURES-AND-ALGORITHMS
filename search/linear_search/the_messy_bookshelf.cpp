#include <iostream>
#include <cmath>
#define ll long long
#include <string>
#include <vector>
using namespace std;

int main(){
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	string x; cin >> x;
	
	int res = -1;
	for (int i = 0; i < n; i++){
		if (a[i] == x){
			res = i + 1;
			break;
		}
	}
	cout << res;
}
