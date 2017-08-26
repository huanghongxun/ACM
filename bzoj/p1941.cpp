#include <cstdio>
#include <algorithm>
#define inf 1000000000
using namespace std;
int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define N 500005
#define Dim 2

static int f;
struct Node {
	int d[Dim], max[Dim], min[Dim], l, r;
	int &operator [] (int x) {
		return d[x];
	}
	friend bool operator <(Node a, Node b) {
		return a[f]<b[f];
	}
};

int dist(Node a, Node b) {
	int ans=0;
	for(int i=0;i<Dim;i++) ans+=abs(a[i]-b[i]);
	return ans;
}

class KDTree {
	Node t[N], p[N], base;

	void update(int x) {
		int l=t[x].l,r=t[x].r;
		for(int i=0;i<Dim;i++) {
			t[x].min[i]=t[x].max[i]=t[x][i];
			if(l) t[x].min[i]=min(t[x].min[i],t[l].min[i]),
				t[x].max[i]=max(t[x].max[i],t[l].max[i]);
			if(r) t[x].min[i]=min(t[x].min[i],t[r].min[i]),
				t[x].max[i]=max(t[x].max[i],t[r].max[i]);
		}
	}

	int build(int l, int r, int fn=0) {
		f=fn;
		int m=l+r>>1;
		nth_element(p+l,p+m,p+r+1);
		t[m]=p[m];
		for(int i=0;i<Dim;i++)
			t[m].max[i]=t[m].min[i]=t[m][i];
		if(l<m) t[m].l=build(l,m-1,(fn+1)%Dim);
		if(m<r) t[m].r=build(m+1,r,(fn+1)%Dim);
		update(m);
		return m;
	}

	int getMax(const Node &x) {
		int ans=0;
		for(int i=0;i<Dim;i++)
			ans+=max(abs(base[i]-x.max[i]),abs(base[i]-x.min[i]));
		return ans;
	}

	int getMin(const Node &x) {
		int ans=0;
		for(int i=0;i<Dim;i++)
			ans+=max(base[i]-x.max[i],0)+max(x.min[i]-base[i],0);
		return ans;
	}

	int queryMax(int x) {
		if(!x) return -inf;
		int ans=dist(t[x],base);
		int l=t[x].l,r=t[x].r,dl=-inf,dr=-inf;
		if(l) dl=getMax(t[l]);
		if(r) dr=getMax(t[r]);
		if(dl>dr) {
			if(dl>ans) ans=max(ans,queryMax(l));
			if(dr>ans) ans=max(ans,queryMax(r));
		} else {
			if(dr>ans) ans=max(ans,queryMax(r));
			if(dl>ans) ans=max(ans,queryMax(l));
		}
		return ans;
	}

	int queryMin(int x) {
		if(!x) return inf;
		int ans=dist(t[x],base);
		if(ans==0) ans=inf;
		int l=t[x].l,r=t[x].r,dl=inf,dr=inf;
		if(l) dl=getMin(t[l]);
		if(r) dr=getMin(t[r]);
		if(dl<dr) {
			if(dl<ans) ans=min(ans,queryMin(l));
			if(dr<ans) ans=min(ans,queryMin(r));
		} else {
			if(dr<ans) ans=min(ans,queryMin(r));
			if(dl<ans) ans=min(ans,queryMin(l));
		}
		return ans;
	}

public:

	KDTree() {
		cnt=0;
	}

	int cnt, rt;

	void addNode(int d[]) {
		++cnt;
		for(int i=0;i<Dim;i++) p[cnt][i]=d[i];
	}

	void buildTree() {
		rt = build(1,cnt,0);
	}

	int queryMinDist(int d[]) {
		for(int i=0;i<Dim;i++) base[i]=d[i];
		return queryMin(rt);
	}

	int queryMaxDist(int d[]) {
		for(int i=0;i<Dim;i++) base[i]=d[i];
		return queryMax(rt);
	}
};
KDTree kd;

int point[500005][2];

int main() {
	int n=read();
	for(int i=0;i<n;i++) {
		point[i][0]=read();point[i][1]=read();
		kd.addNode(point[i]);
	}
	kd.buildTree();
	int ans=inf;
	for(int i=0;i<n;i++) {
		int mn=kd.queryMinDist(point[i]),mx=kd.queryMaxDist(point[i]);
		ans=min(ans,mx-mn);
	}
	printf("%d\n", ans);
	return 0;
}
