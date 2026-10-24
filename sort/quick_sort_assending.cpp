#include <bits/stdc++.h>
using namespace std;

int n;

void Output(int a[]) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void QuickSort(int a[], int left, int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];   // ch?t là ph?n t? ? gi?a

    cout << "Truoc: ";
    Output(a);
    cout << "Left=" << left << " - Right=" << right << " - Pivot=" << pivot << "\n";

    do {
        while (a[i] < pivot) i++;        // tìm ph?n t? >= pivot bên trái
        while (a[j] > pivot) j--;        // tìm ph?n t? <= pivot bên ph?i
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);

    cout << "Sau: ";
    Output(a);
    cout << "\n";

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

int main() {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    Output(a);
    cout << "\n";

    cout << "Sap xep:\n";
    if (n > 1) QuickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep:\n";
    Output(a);

    return 0;
}
