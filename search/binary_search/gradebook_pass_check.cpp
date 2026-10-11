#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    int l = 0, r = n - 1;
    bool found = false;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (a[m] == x) {
            found = true;
            break;
        }

        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }

    cout << (found ? "YES" : "NO");
    return 0;
}
