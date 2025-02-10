#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> v) {
    int mu = 0, ml = 0;
    for (auto i : v) {
        ml += i;
        if (ml > mu)
            mu = ml;
        if (ml < 0)
            ml = 0;
    }
    return mu;
}

int main() {
	ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  while (cin >> n) {
      int t;
      vector<int> vi;
      cin >> t;
      while (n--) {
          int num;
          cin >> num;
          num -= t;
          vi.push_back(num);
      }
      cout << kadane(vi) << "\n";
  }
}
