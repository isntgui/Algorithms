#include <bits/stdc++.h>
using namespace std;

#define int int64_t

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
    Node(Node *l, Node *r) {
        left = l;
        right = r;
        val = (l ? l->val : 0) + (r ? r->val : 0); // min, max, sum, gcd, ...
    }
};


Node* bld(const vector<int> &node, int l, int r) {
    if (l == r) return new Node(node[l]);
    int mid = (l + r) / 2;
    return new Node(bld(node, l, mid), bld(node, mid + 1, r));
}

Node* upd(Node *prev, int l, int r, int i, int x) {
    if (l == r) return new Node(x);
    int mid = (l + r) / 2;
    if (i <= mid)
        return new Node(upd(prev->left, l, mid, i, x), prev->right);
    else
        return new Node(prev->left, upd(prev->right, mid + 1, r, i, x));
}

int qry(Node *node, int l, int r, int i, int j) {
    if (!node || j < l || i > r) return 0;
    if (i <= l && r <= j) return node->val;
    int mid = (l + r) / 2;
    return qry(node->left, l, mid, i, j) + qry(node->right, mid + 1, r, i, j);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // exemplo de uso 
    vector<int> arr = {0, 1, 2, 3, 4}; // 1-indexed
    int n = 4;
    vector<Node*> versions;
    versions.push_back(bld(arr, 1, n)); // versão 0
    versions.push_back(upd(versions[0], 1, n, 2, 10)); // versão 1: arr[2] = 10
    versions.push_back(upd(versions[1], 1, n, 3, 5));  // versão 2: arr[3] = 5
    versions.push_back(upd(versions[1], 1, n, 3, 5));  // versão 3: mesma que versão 2
    cout << "Versão 0, soma [1..3]: " << qry(versions[0], 1, n, 1, 3) << "\n"; // 6
    cout << "Versão 1, soma [1..3]: " << qry(versions[1], 1, n, 1, 3) << "\n"; // 14
    cout << "Versão 2, soma [1..3]: " << qry(versions[2], 1, n, 1, 3) << "\n"; // 16
}
