#include <bits/stdc++.h>
using namespace std;

struct Mo {
    struct Query {
        int l, r, id;
    };

    int n, block;
    vector<Query> queries;
    vector<int> ans;

    vector<int> a;
    int sum = 0;

    Mo(const vector<int>& a) : n((int)a.size()), a(a) {
        block = max(1, (int)sqrt(n));
    }

    void add_query(int l, int r) {
        queries.push_back({l, r, (int)queries.size()});
    }

    void process() {
        int q = queries.size();

        ans.resize(q);

        sort(queries.begin(), queries.end(), [&](const Query& a, const Query& b) {
            int block_a = a.l / block;
            int block_b = b.l / block;

            if (block_a != block_b)
                return block_a < block_b;

            return a.r < b.r;
        });

        int L = 0, R = -1;

        for (auto [l, r, id] : queries) {
            while (L > l)
                add(--L);

            while (R < r)
                add(++R);

            while (L < l)
                remove(L++);

            while (R > r)
                remove(R--);

            ans[id] = get_answer();
        }
    }

    void add(int i) {
        sum += a[i];
    }

    void remove(int i) {
        sum -= a[i];
    }

    int get_answer() {
        return sum;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ;
}
