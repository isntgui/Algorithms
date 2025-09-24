#include <bits/stdc++.h>
using namespace std;

template<typename T> struct minstack {
    stack<pair<T, T>> s;

    void push(T x) {
        if(s.empty()) s.push({x, x});
        else s.emplace(x, s.top().second < x ? s.top().second : x); //  s.top().second > x
    }

    T top() { return s.top().first; }

    T pop() {
        T ans = s.top().first;
        s.pop();
        return ans;
    }

    int size() { return s.size(); }

    T min() { return s.top().second; }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
