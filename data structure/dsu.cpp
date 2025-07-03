#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class UF {
    private:
        vector<int> peso, pai, size;
    public:
        UF(int n) {
            pai.resize(n+1);
            peso.resize(n+1);
            size.resize(n+1, 1);
            iota(pai.begin(), pai.end(), 0);
        }

        int find(int i) {
            return pai[i] = (pai[i]==i?i:find(pai[i]));
        }

        // Union by rank & size
        void joint(int i, int j) {
            i = find(i), j = find(j);
            if(i==j) return ;
            if(peso[i]>peso[j]) {
                pai[j] = i;
                size[i]+=size[j];
            } else if(peso[i]<peso[j]) {
                pai[i] = j;
                size[j]+=size[i];
            }  else {
                pai[i] = j;
                size[i]+=size[j];
                peso[j]++;
            }
        }

        int set_size(int i) {
            return size[find(i)];
        }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ;
}
