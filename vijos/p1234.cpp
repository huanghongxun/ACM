#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 2147483647
#define N 200005

int n, m, k;
double ans = 0, s;
struct edge {
	int x, y;
	double weight;

	friend bool operator < (const edge &a, const edge &b) {
		return a.weight < b.weight;
	}
} e[N];

class UnoinFindSet {
	int n;
	int f[N];
public:
	UnoinFindSet(int n) {
		this->n = n;
		for(int i = 1; i <= n; i++)
			f[i] = i;
	}

	int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}

	bool merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if(fx == fy) return false;
		f[fx] = fy;
		return true;
	}
};

double kruskal(edge edges[], int edgeN, int nodeN, int need) {
	sort(edges, edges + edgeN);
	UnoinFindSet set(nodeN);
	int tot = 0;
	double sum = 0;
	for(int i = 0; i < edgeN; i++) {
		if(set.merge(edges[i].x, edges[i].y)) {
			tot++;
			sum += edges[i].weight;
		}
		if(tot == need) {
			return sum;
		}
	}
	return -1;
}

int main() {
	cin>>n>>m>>k;
	for(int i = 0; i < m; i++) {
		cin>>e[i].x>>e[i].y>>e[i].weight;
	}
	int ans = kruskal(e, m, n, n - k);
	if(ans == -1)
		cout<<"No Answer";
	else
		cout<<ans;

	return 0;
}