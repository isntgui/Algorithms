#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int primo[maxn]; 

void crivo(int n){
    for(int i=1; i<=n; i++){
        primo[i] = -1;
    }
    for(int i = 2; i <= n; i++){
        if(primo[i] == -1){
            primo[i] = 1;
            for(int j = i + i; j <= n; j += i){
                primo[j] = 0;
            }
        }
    }
}
