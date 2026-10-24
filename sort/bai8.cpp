#include <iostream>
using namespace std;

int partition(int a[], int l, int r){
	int pivot = a[l + (r - l) / 2];
	int i = l - 1, j = r + 1;
	while(1){
		do {
			i++;
		} while (a[i] < pivot);
		do {
			j--;
		} while (a[j] > pivot);
		
		if (i < j){
			int r = a[i];
	        a[i] = a[j];
	        a[j] = r;
		}
		else return j;
	}
}

void quickSort(int a[], int l, int r){
	if (l >= r) return;
	int p = partition(a, l, r);
	quickSort(a, l, p);
	quickSort(a, p + 1, r);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n > 0) quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}

