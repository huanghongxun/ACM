#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 2147483647

int n, m;
double ans = 0, s;
int f[200000];
struct edge {
	int x, y;
	double weight;

	friend bool operator < (const edge &a, const edge &b) {
		return a.weight < b.weight;
	}
} e[200000];

class UnoinFindSet {
	#define N 200005
	int n;
	int parnet[N];
public:
	UnoinFindSet(int n) {
		this->n = n;
		for(int i = 1; i <= n; i++)
			parent[i] = i;
	}

	int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}

	bool merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if(fx == fy) return false;
		parent[fx] = fy;
		return true;
	}
};

int kruskal(edge[] edges, int edgeN, int nodeN) {
	sort(edges, edges + edgeN);
	UnoinFindSet set(edgeN);
	int tot = 0, sum = 0;
	for(int i = 0; i < edgeN; i++) {
		if(set.merge(edge[i].x, edge[i].y)) {
			tot++;
			sum = max(sum, edge[i].weight);
		}
		if(tot == nodeN - 1) {
			return sum;
		}
	}
	return -1;
}

int main() {
	cin>>n>>m;
	for(int i = 0; i < m; i++) {
		cin>>e[i].x>>e[i].y>>e[i].weight;
	}
	cout<<n-1<<' ';
	cout<<kruskal(e, n, m);

	return 0;
}