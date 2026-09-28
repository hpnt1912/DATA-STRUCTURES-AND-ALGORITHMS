#include <iostream>
#include <algorithm>
using namespace std;

bool myBinarySearch(int a[], int n, int x);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int x; 
    while (q--){
        cin >> x;
        if (myBinarySearch(arr, n, x))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

bool myBinarySearch(int a[], int n, int x){
	int l = 0, r = n - 1;
	while (l <= r){
		int mid = (l + r) / 2;
		if (a[mid] == x){
			return true;
		}
		else if (a[mid] < x){
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return false;
}

