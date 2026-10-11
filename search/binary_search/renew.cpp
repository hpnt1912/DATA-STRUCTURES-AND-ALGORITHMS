#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll a, k, b, m, n;
	cin >> a >> k >> b >> m >> n;
	
	ll res = 0;
	ll t = 0;
	ll cnt1 = 1, cnt2 = 1;
	while (t < n){
		res++;
		if (res == cnt1*m && res != cnt2*k){
			t += a;
			cnt1++;
		}
		else if (res == cnt2*k && res != cnt1*m){
			t += b;
			cnt2++;
		}
		else if (res != cnt1*m && res != cnt2*k){
			t += a + b;
		}
		else {
			t += 0;
			cnt1++;
			cnt2++;
		}
	}
	cout << res;
}
