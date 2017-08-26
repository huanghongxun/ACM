#include <cstdio>
#define min(a,b) (a<b?a:b)
#define N 4000005
int c[N], tag[N], M, n, m;
inline int lowbit(int i) {
	return i & -i;
}
void pushdown(int i) {
	for(int j=M;j;j>>=1) {
		int s=i/j;
		if(tag[s]==0||2*s>3*M) continue;
		tag[s<<1]+=tag[s], c[s<<1]+=tag[s];
		tag[(s<<1)^1]+=tag[s], c[(s<<1)^1]+=tag[s];
		tag[s]=0;
	}
}
void pushup(int i) {
	for(int j=i>>1;j;j>>=1)
		c[j]=min(c[j<<1],c[(j<<1)+1])+tag[j];
}
int add(int l, int r, int k) {
	l+=M-1,r+=M+1;
	pushdown(l),pushdown(r);
	for(int s=l,t=r;s^t^1;s>>=1,t>>=1) {
		if(~s&1) tag[s^1]+=k,c[s^1]+=k;
		if( t&1) tag[t^1]+=k,c[t^1]+=k;
	}
	pushup(l),pushup(r);
}
int query(int l, int r) {
	int ans=0x7fffffff;
	l+=M-1,r+=M+1;
	pushdown(l),pushdown(r);
	for(int s=l,t=r;s^t^1;s>>=1,t>>=1) {
		if(~s&1) ans=min(ans,c[s^1]);
		if( t&1) ans=min(ans,c[t^1]);
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for(M=1;M<=n+1;M<<=1);
	for(int i=1;i<=n;i++) scanf("%d", &c[M+i]);
	for(int i=M-1;i;i--) c[i]=min(c[(i<<1)+1],c[i<<1]);
	for(int i=1,j,d,s,t;i<=m;i++) {
		scanf("%d%d%d", &d, &s, &t);
		j = query(s,t);
		//printf("TEST: %d\n", j);
		if(j<d) {
			printf("-1\n%d\n", i);
			goto end;
		}
		add(s,t,-d);
	}
	printf("0\n");
end:
	return 0;
}