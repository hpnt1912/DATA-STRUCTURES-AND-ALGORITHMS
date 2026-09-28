#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	long long x; cin >> x;
	
	int res1 = -1;
	int res2 = 0;
	int res4 = 0;
	int res3;
	for (int i = 0; i < n; i++){
		if (a[i] == x){
			res1 = i;
			res2++;
			break;
		}
		res2++;
	}
	
	for (int i = n; i >= 0; i--){
		if (a[i] == x){
			res3 = res4 - 1;
			break;
		}
		res4++;
	}
	
	if (res1 == -1){
		cout << -1;
	}
	else {
		cout << res1 << endl << res2 << endl << res3 << endl << res4;
	}
	return 0;
}
