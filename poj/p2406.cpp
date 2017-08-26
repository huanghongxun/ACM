#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define MAXN 3000005

int n, num[MAXN], z[MAXN];
int sa[MAXN], rank[MAXN], height[MAXN];
int wa[MAXN], wb[MAXN], bucket[MAXN];
char s[MAXN];

void sort(int *sa, int *x, int *y, int n, int m) {
    int i;
    rep(i,0,m) bucket[i] = 0;
    rep(i,0,n) bucket[x[y[i]]]++;
    rep(i,1,m) bucket[i]+=bucket[i-1];
    for(i=n-1;i>=0;i--) sa[--bucket[x[y[i]]]]=y[i];
}
void da(char *r, int n, int m) {
    int i,j,p,*x=wa,*y=wb,*t;
    rep(i,0,n) x[i]=r[i],z[i]=i;
    sort(sa, x, z, n, m);
    for(j=1,p=1;p<n;j*=2,m=p) {
        p = 0;
        rep(i,n-j,n) y[p ++] = i;
        rep(i,0,n) if(sa[i] >= j) y[p ++] = sa[i] - j;
        sort(sa, x, y, n, m);
        t=x,x=y,y=t;p=1;x[sa[0]]=0;
        rep(i,1,n) x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
    }
}

void calHeight(char *r, int n) {
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    rep(i,0,n) {
        if (k) k--;
        j = sa[rank[i]-1];
        while(r[i+k]==r[j+k]) k++;
        height[rank[i]] = k;
    }
}
int f[MAXN];
int main() {
	while(scanf("%s", s) && s[0] != '.') {
		int n = strlen(s);
		da(s,n+1,200); calHeight(s,n);
		int ma=0,mi=0x7fffffff,i,j=rank[0];
		for(i=j;i>=1;i--) {
			f[i]=mi;
			mi=min(mi,height[i]);
		}
		mi=0x7fffffff;
		for(i=j+1;i<=n;i++) {
			mi=min(mi,height[i]);
			f[i]=mi;
		}
		for(i=1;i<=n;i++) if(n%i==0&&f[rank[i]]==n-i) {
			ma=n/i;break;
		}
		if(ma!=0) printf("%d\n", ma);
		else printf("1\n");
	}
	return 0;
}
