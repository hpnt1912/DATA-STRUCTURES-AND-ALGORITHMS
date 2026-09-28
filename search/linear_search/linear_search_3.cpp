#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main(){
	int n; cin >> n;
	ll a[200001];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int b[100000] = {0};
	int res = 0;
	for (int i = 0; i < n; i++){
		b[a[i]] = 1;
		while (b[res] == 1){
			res += 1;
		}
		cout << res << " ";
	}
	
	return 0;
}
