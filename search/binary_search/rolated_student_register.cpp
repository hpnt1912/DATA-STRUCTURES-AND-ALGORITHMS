#include <bits/stdc++.h>
using namespace std;

int readInt() {
    int x = 0;
    char c = getchar();

    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }

    return x;
}

bool bi_search(const vector<int> &a, int x){
	int n = a.size();
	int l = 0, r = n - 1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (a[mid] == x) return true;
		if (a[l] <= a[mid]){
			if (x >= a[l] && x < a[mid]){
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		else {
			if (x > a[mid] && x <= a[r]){
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n = readInt();
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		a[i] = readInt();
	}
	
	int x = readInt();
	
	if (bi_search(a, x)){
		cout << "YES";
	}
	else cout << "NO";
	
	return 0;
}
