#include <bits/stdc++.h>
using namespace std;

template<typename T> struct minqueue {
    deque<pair<T, int>> q;

    void push(T x) {
        int ct = 1;
        while(q.size() and x < q.front().first) // x > q.front().first for max
            ct += q.front().second, q.pop_front();
        q.emplace_front(x, ct);
    }
    
    void pop() {
        if (q.back().second > 1) q.back().second--;
        else q.pop_back();
    }

    T min() { return q.back().first;}
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // usa-se assim:
    // minqueue<int> mq;
}
