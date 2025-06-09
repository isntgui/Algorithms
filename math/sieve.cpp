#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e6+10;

int primo[mxn];

void eh_primo() {
    fill(primo, primo+mxn, -1);
    primo[0] = primo[1] = 0;
    for(int i=2; i<mxn; i++) {
        if(primo[i]==-1) {
            primo[i] = i;
            for(int j=2*i; j<mxn; j+=i) {
                primo[j] = 0;
            }
        }
    }
}

void fat_crivo(){
    for(int i=2; i<mxn; i++) {
        if(primo[i]==0) {
            for(int j=i; j<mxn; j+=i) {
                if(primo[j]==0) {
                    primo[j] = i;
                }
            }
        }
    }
}

vector<int> fatorar(int x) {
    vector<int> div;
    while(x>1) {
        div.push_back(primo[x]);
        x/=primo[x];
    }
    return div;
}

int main() {
    // fat_crivo();
    // eh_primo();
    // int n;
    // cin >> n;
    // vector<int> ans = fatorar(n);
    // for(int i=0; i<(int)ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << primo[n];
}
