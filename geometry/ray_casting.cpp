#include <bits/stdc++.h>
using namespace std;

struct Point {int x, y;};

bool inside(Point p, vector<Point>& poly) {
    bool in = false;
    int n = poly.size();
    for (int i = 0, j = n - 1;
         i < n; j = i++) {
        Point a = poly[i];
        Point b = poly[j];
        bool cross_y =
            (a.y > p.y) != (b.y > p.y);

        if (cross_y) {
            long double x =
                (long double)(b.x - a.x) * (p.y - a.y) / (b.y - a.y) + a.x;

            if (p.x < x)
                in = !in;
        }
    }
    return in;
}
