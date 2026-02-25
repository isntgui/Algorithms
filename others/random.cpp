#include <bits/stdc++.h>
using namespace std;

#ifdef o_0
#include "debugging.h"
#endif

#define int long long int
#define sum accumulate
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

struct Random {
    int seed;
    int tempo_atual = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
    int a = 1664525, c = 1013904223, m = pow(2, 32), x = (!seed ? ((int)tempo_atual * 1000) : seed);

    Random(int _seed = 0) : seed(_seed) {}

    int random(int min = 0, int max = 1) {
        x = (a * x + c) % m;
        return (int)(min + ((double)x / m) * (max - min + 1));
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Random R;
    cout << R.random() << "\n";
}
