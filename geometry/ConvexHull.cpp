#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e3+1e2;

struct Pt {
	int x, y;
	Pt(int _x = 0, int _y = 0): x(_x), y(_y) {}
	Pt operator+(const Pt &o) {return Pt(x+o.x, y+o.y);}
	Pt operator-(const Pt &o) {return Pt(x-o.x, y-o.y);}
	bool operator < (Pt o) const {
		if(x==o.x) return y < o.y;
		return x < o.x;
	}
	void operator+=(const Pt &o) {x+=o.x, y+=o.y; }
	void operator-=(const Pt &o) {x-=o.x, y-=o.y; }
	ll dot(const Pt &o) { return 1ll*x*o.x + 1ll*y*o.y; } //produto escalar
	ll cross(const Pt &o) { return 1ll*x*o.y - 1ll*y*o.x; } //produto vetorial
};

int marc[mxN], n;
vector<Pt> conv, upper, lower, pts;

void makeconv() {
	long long it1 = 0, it2 = 0;
	for(int i = 0; i < n; i++){
		if(marc[i]) continue;
		while(it1 >= 2 && (pts[i] - upper[it1 - 2]).cross(upper[it1 - 1] - upper[it1 -2]) < 0){
			upper.pop_back();
			it1--;
		}
		upper.push_back(pts[i]);
		it1++;
		while(it2 >= 2 && (pts[i] - lower[it2 - 2]).cross(lower[it2 - 1] - lower[it2 -2]) > 0){
			lower.pop_back();
			it2--;
		}
		lower.push_back(pts[i]);
		it2++;
	}
	for(int i=0; i<it1-1; ++i) conv.push_back(upper[i]);
	for(int i=it2 - 1; i>0; --i) conv.push_back(lower[i]);
}

double d(const Pt &x, const Pt &y) {
	return sqrt(pow(y.x-x.x, 2)+pow(y.y-x.y, 2));
}

void init() {
	conv.clear();
	lower.clear();
	upper.clear();
	pts.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(cin >> n && n) {
		init();
		pts.resize(n);
		for(int i=0; i<n; ++i)
			cin >> pts[i].x >> pts[i].y;
		sort(pts.begin(), pts.end());
		makeconv();
		double ans = 0;
		for(size_t i=0; i<conv.size(); ++i) {
			Pt p1 = conv[i], p2 = conv[(i+1)%(int)conv.size()];
			ans+=d(p1, p2);
		}
		cout << "Tera que comprar uma fita de tamanho ";
		cout << fixed << setprecision(2) << ans << ".\n";
	}
}
