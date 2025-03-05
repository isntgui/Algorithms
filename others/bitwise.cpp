#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k, j;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Operação and
    cout << (5&4) << "\n"; // 5 = 101, 4 = 100, 4 = 100

    // Operação or
    cout << (9|3) << "\n"; // 9 = 1001, 3 = 11, 11 = 1011

    // Operação not
    n = 6;
    cout << (~n) << "\n"; // n = -n-1, -7

    // Operação xor
    cout << (15^3) << "\n"; // 15 = 1111, 3 = 11, 12 = 1100

    // Operação shift
    j = 3;
    cout << (1 << j) << "\n"; // 1 = 1, 8 = 1000, nesse caso seria 2^j (potencia)
    
    // Operação reversa de shift
    j = 1;
    cout << (8>>j) << "\n"; // 8 = 1000, 4 = 100, sendo a mesma coisa que 8/2

    // Bitmask
    // Checa se o bit k de n está ligado
    n=5, k=0; // 5 = 101
    cout << (n & (1 << k)) << "\n";

    // Liga o bit k de n
    k = 1;
    n = n|(1<<k);
    cout << n << "\n"; // 7 = 111
    
    return 0;
}
