#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include "debugging.h"
#endif

struct Polynomials {

    vector<int> pl;
    int size;
    int remainder;

    Polynomials(vector<int> a = {}) : size(a.size()), pl(a), remainder(0) {}

    Polynomials operator+(const Polynomials& other) {
        Polynomials resp;
        bool tipo;
        if(other.size > size) {
            tipo = true;
            resp.pl = other.pl;
            resp.size = other.size;
        } else {
            tipo = false;
            resp.pl = pl;
            resp.size = size;
        }
        if(tipo) {
            for(int i = 0; i < size; i++)
                resp.pl[i] += pl[i];
        } else {
            for(int i = 0; i < other.size; i++)
                resp.pl[i] += other.pl[i];
        }
        return resp;
    }

    Polynomials operator/(const Polynomials& other) {
        Polynomials resp;
        return resp;
    }
};

ostream& operator<<(ostream& out, const Polynomials& poly) {
    if(poly.pl[poly.size - 1] == 1 || poly.pl[poly.size - 1] == -1 && poly.pl[poly.size - 1]) {
        if(poly.pl[poly.size - 1] > 0)
            out << "x^" << poly.size - 1;
        else
            out << "-x^" << poly.size - 1;
    } else {
        if(poly.pl[poly.size - 1] > 0) {
            out << poly.pl[poly.size - 1];
            out << "x";
            if(poly.size - 1 > 1)
                out << "^" << poly.size - 1;
        }
        else {
            if(poly.pl[poly.size - 1] != 0)
                out << poly.pl[poly.size - 1] << "x^" << poly.size - 1;
        }
    }
    for(int i = poly.size - 2; i >= 1; i--) {
        if(poly.pl[i] == 0) continue;
        if(poly.pl[i] > 0) {
            out << " + ";
            if(poly.pl[i] != 1)
                out << poly.pl[i];
            out << "x";
            if(i > 1)
                out << "^" << i;
        } else {
            out << " - ";
            if(poly.pl[i] != -1)
                out << -poly.pl[i];
            out << "x";
            if(i - 1 > 1)
                out << "^" << i - 1;
        }
    }
    if(poly.pl[0] == 0)
        return out;
    if(poly.pl[0]) 
        out << " + " << poly.pl[0];
    else
        out << " - " << poly.pl[0];
    return out;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> eq1 = {1, 2, 3, 4}; // 4x^3 + 3x^2 + 2x + 1
    vector<int> eq2 = {3, 2}; // x^3 + 2x^2 + 3x + 4
    Polynomials pl1(eq1);
    Polynomials pl2(eq2);
    cout << pl1 << "\n";
    cout << pl2 << "\n";
    Polynomials ans = pl1 + pl2;
    cout << ans << "\n";
}
