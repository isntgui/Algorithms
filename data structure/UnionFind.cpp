#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

class UionFind {
private:
	vector<int> p, rank;
public:
	UionFind(int n) {
		p.assign(n+1, 0);
		rank.assign(n+1, 0);
		for(int i=0; i<=n; ++i) p[i]=i;
	}
	int find(int i) {
		return (p[i]==i) ? i : (p[i]=find(p[i]));
	}
	bool comp(int i, int j) {
		return find(i)==find(j);
	}
	void unioSet(int i, int j) {
		if(!comp(i, j)) {
			int x = find(i), y=find(j);
			if(rank[x]>rank[y])
				p[y] = x;
			else {
				p[x] = y;
				if(rank[x]==rank[y])
					++rank[y];
			}
		}
	}
};