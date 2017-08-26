#include <cstdio>
#include <map>
#include <vector>
using std::map;
using std::pair;
using std::make_pair;
using std::vector;

int read() {
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}

const int N = 200040;

int fa[N], sz[N], tot;
map<int, int> idx;
vector<pair<int, int> > limit;

int getIndex(int i) {
	if (idx.find(i) == idx.end()) idx[i] = tot++;
	return idx[i];
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] > sz[y]) fa[y] = x, sz[x] += sz[y];
	else fa[x] = y, sz[y] += sz[x];
}

void init() {
	for (int i = 0; i <= 200000; i++) {
		fa[i] = i; sz[i] = 1;
	}
}

int main() {
	int kase = read(), n, i, j, e;
	while (kase--) {
		init();
		tot = 0;
		n = read();
		idx.clear();
		limit.clear();
		while (n--) {
			i = getIndex(read()), j = getIndex(read()), e = read();
			if (e == 1) merge(i, j);
			else limit.push_back(make_pair(i, j));
		}
		int flag = 1;
		for (int i = 0; i < limit.size(); i ++) {
			if (find(limit[i].first) == find(limit[i].second)) {
				flag = 0; break;
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}

	return 0;
}