#include <cstdio>

int f[2][N], c[2][N], h[N];

int lowbit(int *c, int t) {
	return t & -t;
}

void change(int *c, int i, int x){
	for(;i<=n;i+=lowbit(i)) c[i]=max(c[i],x);
}

int query(int *c, int l, int r) {
	int ans=0;
	for(;i>0;i-=lotbit(i)) ans=max(ans,c[i]);
	return ans;
}

int main() {

	int n, i, maxh;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&h[i]);
		maxh=max(maxh,h[i]);
	}

	for(i=1;i<=n;i++) {
		f[0][i]=max(query(c[1],h[i]-1)+1,f[0][i]);
		f[1][i]=max(query(c[0],maxh-h[i]-1)+1,f[0][i]);
		change(c[0],f[0][i]); change(c[1],f[1][i]);
		ans=max(ans,max(f[0][i],f[1][i]));
	}
	printf("%d\n", ans);

	return 0;
}