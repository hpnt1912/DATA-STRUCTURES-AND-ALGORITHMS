#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int x; cin >> x;
	
	int cnt = 0;
	int b[100000], j = 0;
	for(int i = 0; i < n; i++){
		if (a[i] == x){
			cnt++;
			b[j++] = i;
		}
	}
	if (cnt == 0){
		cout << 0;
	}
	else {
		cout << cnt << endl;
		for (int i = 0; i < j; i++){
			cout << b[i] << " " << b[i] + 1 << endl;
		}
	}
	
	return 0;
}
