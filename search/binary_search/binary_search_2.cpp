#include <iostream>
#include <cmath>
#define ll long long
#include <string>
#include <vector>
using namespace std;

int main(){
	int n; cin >> n;
	vector<string> a;
	for (int i = 0; i < n; i++){
		string x; cin >> x;
		a.push_back(x);
	}
	string x; cin >> x;
	
	int l = 0, r = n - 1;
	int res = -1;
	int cnt = 0;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (a[mid] == x){
			res = mid;
			break;
		}
		else if (a[mid] < x){
			l = mid + 1;
			cnt++;
		}
		else {
			r = mid - 1;
			cnt++;
		}
	}
	if (res == -1){
		cout << -1;
	}
	else {
		cout << res << endl << cnt + 1;
	}
	
	return 0;
}
