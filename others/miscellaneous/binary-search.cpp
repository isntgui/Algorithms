#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end()); // a precisa está ordenado.
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2; // ou l + (r - l) / 2 para evitar overflow
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << "\n";
}
