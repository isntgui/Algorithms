#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);

    cout << "Elemento no índice 1: " << *s.find_by_order(1) << "\n";
    cout << "Número de elementos menores que 15: " << s.order_of_key(15) << "\n";
}
