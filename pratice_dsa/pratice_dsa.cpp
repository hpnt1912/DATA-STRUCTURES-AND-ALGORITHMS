#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	ll n, q; cin >> n >> q;
	ll a[n];
	for (ll i = 0; i < n; i ++){
		cin >> a[i];
	}
	while (q--){
		ll x; cin >> x;
		bool check = false;
		for (ll i = 0; i < n; i++){
			if (a[i] == x){
				check = true;
				break;
			}
		}
		if (check){
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
