#include <bits/stdc++.h>
using namespace std;

#define int long long int

struct DSU {
    vector<int> peso, pai, size;

    DSU(int n) {
        pai.resize(n + 1, 0);
        peso.resize(n + 1, 0);
        size.resize(n + 1, 1);
        iota(pai.begin(), pai.end(), 0);
    }

    int find(int i) {
        return pai[i] = (pai[i] == i ? i : find(pai[i]));  // armotized
    }

    void join(int i, int j, bool union_by_rank_size) {
        i = find(i), j = find(j);
        if (i == j)
            return;
        if (union_by_rank_size) {
            if (peso[i] > peso[j])
                pai[j] = i;
            else {
                pai[i] = j;
                if (peso[i] == peso[j])
                    peso[j]++;
            }
        } else {
            if (size[i] < size[j])
                swap(i, j);
            size[i] += size[j], pai[j] = i;
        }
    }

    int set_size(int i) {
        return size[find(i)];
    }

    bool same_set(int i, int j) {
        return find(i) == find(j);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ;
}
