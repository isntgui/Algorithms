#include<bits/stdc++.h>
using namespace std;

int mdc(int a, int b) {
    return (b==0 ? a : mdc(b, a%b));
}

int mmc(int a, int b) {
    return (a/mdc(a, b))*1LL*b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    cout << mdc(n, m) << "\n";
    cout << mmc(n, m) << "\n";
}
