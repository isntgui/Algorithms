#include <bits/stdc++.h>
using namespace std;

struct Polynomius {
    vector<int> pl;

    explicit Polynomius(const vector<int>& a = {}) : pl(a) {
        trim();
    }

    void trim() {
        while (!pl.empty() && pl.back() == 0)
            pl.pop_back();
    }

    int deg() const { return (int)pl.size() - 1; }

    Polynomius operator+(const Polynomius& other) const {
        int n = max((int)pl.size(), (int)other.pl.size());
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (i < (int)pl.size()) res[i] += pl[i];
            if (i < (int)other.pl.size()) res[i] += other.pl[i];
        }
        Polynomius p(res);
        p.trim();
        return p;
    }

    Polynomius operator-(const Polynomius& other) const {
        int n = max((int)pl.size(), (int)other.pl.size());
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (i < (int)pl.size()) res[i] += pl[i];
            if (i < (int)other.pl.size()) res[i] -= other.pl[i];
        }
        Polynomius p(res);
        p.trim();
        return p;
    }

    Polynomius operator*(const Polynomius& other) const {
        if (pl.empty() || other.pl.empty())
            return Polynomius({});
        vector<int> res(pl.size() + other.pl.size() - 1, 0);
        for (int i = 0; i < (int)pl.size(); i++) {
            for (int j = 0; j < (int)other.pl.size(); j++) {
                res[i + j] += pl[i] * other.pl[j];
            }
        }
        Polynomius p(res);
        p.trim();
        return p;
    }

    Polynomius operator/(const Polynomius& other) const {
        if (other.pl.empty() || other.pl.back() == 0)
            throw invalid_argument("Divisão por polinômio nulo!");

        vector<int> A = pl;
        vector<int> B = other.pl;
        vector<int> Q(max(0, (int)A.size() - (int)B.size() + 1), 0);
        vector<int> R = A;

        int m = (int)B.size() - 1;
        int n = (int)A.size() - 1;

        while ((int)R.size() - 1 >= m) {
            int degDiff = (int)R.size() - 1 - m;
            int coef = R.back() / B.back();
            if (coef == 0) break;
            Q[degDiff] = coef;

            for (int i = 0; i <= m; i++)
                R[i + degDiff] -= coef * B[i];

            while (!R.empty() && R.back() == 0)
                R.pop_back();
        }

        Polynomius q(Q);
        q.trim();
        return q;
    }

    Polynomius operator%(const Polynomius& other) const {
        if (other.pl.empty() || other.pl.back() == 0)
            throw invalid_argument("Divisão por polinômio nulo!");

        vector<int> A = pl;
        vector<int> B = other.pl;
        vector<int> R = A;

        int m = (int)B.size() - 1;
        int n = (int)A.size() - 1;

        while ((int)R.size() - 1 >= m) {
            int degDiff = (int)R.size() - 1 - m;
            int coef = R.back() / B.back();
            if (coef == 0) break;

            for (int i = 0; i <= m; i++)
                R[i + degDiff] -= coef * B[i];

            while (!R.empty() && R.back() == 0)
                R.pop_back();
        }

        Polynomius r(R);
        r.trim();
        return r;
    }
};

ostream& operator<<(ostream& out, const Polynomius& p) {
    if (p.pl.empty()) return out << 0;

    for (int i = p.pl.size() - 1; i >= 0; i--) {
        int c = p.pl[i];
        if (c == 0) continue;

        if (i != (int)p.pl.size() - 1) {
            if (c > 0) out << " + ";
            else out << " - ", c = -c;
        } else if (c < 0) {
            out << "-";
            c = -c;
        }

        if (i == 0 || c != 1) out << c;
        if (i >= 1) out << "x";
        if (i > 1) out << "^" << i;
    }
    return out;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> eq1 = {1, 2, 3, 4};
    vector<int> eq2 = {3, 2};

    Polynomius p1(eq1);
    Polynomius p2(eq2);

    cout << "P1(x) = " << p1 << "\n";
    cout << "P2(x) = " << p2 << "\n\n";

    cout << "Soma:          " << (p1 + p2) << "\n";
    cout << "Subtração:     " << (p1 - p2) << "\n";
    cout << "Multiplicação: " << (p1 * p2) << "\n";
    cout << "Quociente:     " << (p1 / p2) << "\n";
    cout << "Resto:         " << (p1 % p2) << "\n";
}
