#include<bits/stdc++.h>
using namespace std;

const int mxn = 1e4+10;

int parent[mxn], height[mxn];

int find(int i) {
    return (i==parent[i]?i:parent[i] = find(parent[i]));
}

void join(int i, int j) {
    int x = find(i), y = find(j);
    if(!(x==y)) {
        if(height[x]>height[y])
            parent[y] = x;
        else {
            parent[x] = y;
            if(height[x]==height[y])
                ++height[y];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(height, 0, sizeof(height));
    iota(parent, parent+mxn, 0); // inicializa o vetor em sequencia, dependendo do intervalo

    int _max, n, m;
    while(cin >> n >> m) {
        _max = max(_max, max(n, m));
        join(n, m);
    }

    for(int i=0; i<=_max; ++i)
        cout << "Antecessor[" << i << "] = " << parent[i] << ".\n";
    cout << "\n";
    for(int i=0; i<=_max; ++i)
        cout << "Altura[" << i << "] = " << height[i] << ".\n";
}
