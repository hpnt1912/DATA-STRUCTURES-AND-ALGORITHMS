#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main (){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long max1 = -1, max2 = -1;
		long long min1 = LLONG_MAX, min2 = LLONG_MAX;
		for (int i = 0; i < n; i++){
			if (a[i] > max1){
				max2 = max1;
				max1 = a[i];
			}
			else if (a[i] > max2){
				max2 = a[i];
			}
			if (a[i] < min1){
				min2 = min1;
				min1 = a[i];
			}
			else if (a[i] < min2){
				min2 = a[i];
			}
		}
		cout << max1 - min1 + max2 - min2 << endl;
	}
	
	return 0;
}
