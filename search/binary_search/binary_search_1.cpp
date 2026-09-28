#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int x; cin >> x;
	
	int l = 0, r = n - 1;
	int res = -1;
	int cnt = 0;
	while (l <= r){
		int mid = (l + r) / 2;
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
