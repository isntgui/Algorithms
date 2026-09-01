#include <bits/stdc++.h>
using namespace std;

#define sz(a) (int)a.size()

int n, m;
vector<vector<int>> mat;

void mirror() {
    for (auto& row : mat)
        reverse(row.begin(), row.end());
}

/*
    ans[j][n-i-1] para sentido horário
    ans[m-j-1][i] para sentido anti-horário
*/
void rotate90() {
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans[j][n - i - 1] = mat[i][j];
    mat = ans;
    swap(n, m);
}

/*
    90° = 1 * 90°
    180° = 2 * 90°
    270° = 3 * 90°
    360° = 4 * 90°
*/
void rotate(int k) {
    k %= 4;
    while (k--)
        rotate90();
}