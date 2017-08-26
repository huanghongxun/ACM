#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
const int N = 300005;
struct Edge {
	int x, y, v;
	bool operator <(const Edge &b) const {return v>b.v;}
} e[N];
char r[N];
int sa[N], wa[N], wb[N], z[N], c[N], rank[N], height[N], n;
int fa[N], sz[N];
long long ans[N][2], mi[N], ma[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x, y);
	fa[x] = y; sz[y] += sz[x];
	ma[y] = max(ma[x], ma[y]);
	mi[y] = min(mi[x], mi[y]);
}
int main() {
	int n = read(), m = 250;
	scanf("%s", r+1);
    int i,j=1,k,p=1,*x=wa,*y=wb,*t;
    FOR(i,1,n)c[x[i]=r[i]]++;
    FOR(i,1,m)c[i]+=c[i-1];
    for(i=n;i;i--) sa[c[x[i]]--]=i;
    for(;p<n;j*=2,m=p) {
        for(p=0,i=n-j+1;i<=n;i++)y[++p]=i;
        FOR(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
        FOR(i,0,m)c[i]=0;
        FOR(i,1,n)c[x[y[i]]]++;
        FOR(i,1,m)c[i]+=c[i-1];
        for(i=n;i;i--)sa[c[x[y[i]]]--]=y[i];
		t=x;x=y;y=t;p=1;x[sa[1]]=1;
        FOR(i,2,n)x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j])?p:++p;
    }
    FOR(i,1,n) rank[sa[i]] = i;
    for(i=1,k=0;i<=n;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
	FOR(i,1,n) ma[rank[i]]=mi[rank[i]]=read(),fa[i]=i,sz[i]=1,e[i-1]=(Edge){i-1,i,height[i]};
	for (sort(e + 1, e + n), j = 1, i = e[1].v; i >= 0; i--) {
		ans[i][0] = 0; ans[i][1] = -1ll<<62;
		for (; j < n && e[j].v == i; j++) {
			int x = find(e[j].x), y = find(e[j].y);
			ans[i][1] = max(ans[i][1], max(ma[x] * ma[y], mi[x] * mi[y]));
			ans[i][0] += 1ll * sz[x] * sz[y];
			merge(x, y);
		}
		ans[i][0] += ans[i + 1][0];
		if (ans[i + 1][0]) ans[i][1] = max(ans[i][1], ans[i + 1][1]);
	}
	for(i=0;i<n;i++) printf("%lld %lld\n", ans[i][0], ans[i][0]==0?0:ans[i][1]);

	return 0;
}
