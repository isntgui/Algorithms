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

    // Operação reversa (desliga o k bit de n)
    n = 5, k = 2;
    n = n&~(1<<k);
    cout << n << "\n";

    // ================================================================== BITSET ==================================================================

    // init bitset
    bitset<8> a("10"); // 00000010
    bitset<8> b(5); // 00000101
    a = 0b10101010; // 10101010

    // functions bitset  
    cout << a.all() << "\n"; // if all a_i = 1, so true
    cout << a << "\n";
    cout << a.count() << "\n"; // count(a_i == 1)
    cout << a.any() << "\n"; // if any a_i = 1, so true
    cout << a.none() << "\n"; // if all a_i = 0, so true
    cout << a.size() << "\n"; // size of bitset
    cout << b[1] << "\n";
    a = ~a; // a_i = a_i ^ 1;
    b.flip(1); // b_i ^= 1
    b.set(1); // b_i = 1
    b.reset(1); // b_i = 0

    // bitset operators
    a = 11, b = 4;
    cout << (a^b) << "\n";
    cout << (a|b) << "\n";
    cout << (a&b) << "\n";
    cout << (a<<1) << "\n";
    cout << (b>>1) << "\n";

    // Comp
    cout << (a!=b) << "\n";
    b = a;
    cout << (a==b) << "\n";

    // bitset -> int
    cout << b.to_ulong() << "\n";
    cout << b.to_ullong() << "\n";
    cout << b.to_string() << "\n";
    return 0;
}
