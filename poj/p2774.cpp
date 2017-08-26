#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define MAXN 200050

int n, num[MAXN], z[MAXN];
int sa[MAXN], rank[MAXN], height[MAXN];
int wa[MAXN], wb[MAXN], wv[MAXN], wd[MAXN];
char s[MAXN];

void sort(int *sa, int *x, int *bucket, int *y, int n, int m) {
    int i;
    rep(i,0,m) bucket[i] = 0;
    rep(i,0,n) bucket[x[i]]++;
    rep(i,1,m) bucket[i]+=bucket[i-1];
    for(i=n-1;i>=0;i--) sa[--bucket[x[i]]]=y[i];
}

void da(char *r, int n, int m) {
    int i,j,p,*x=wa,*y=wb,*t;
    rep(i,0,n) x[i]=r[i],z[i]=i;
    sort(sa, x, wd, z, n, m);
    for(j=1,p=1;p<n;j*=2,m=p) {
        p = 0;
        rep(i,n-j,n) y[p ++] = i;
        rep(i,0,n) if(sa[i] >= j) y[p ++] = sa[i] - j;
        rep(i,0,n) wv[i] = x[y[i]];
        sort(sa, wv, wd, y, n, m);
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

int main() {
	scanf("%s", s);
	int n1 = strlen(s), ans=0;
	s[n1]='$';
	scanf("%s",s+n1+1);
	int n = strlen(s);
	da(s,n+1,200);
	calHeight(s,n);
	for(int i=2;i<=n;i++) {
		if(sa[i-1]<n1&&sa[i]>n1||sa[i-1]>n1&&sa[i]<n1)
			ans=max(ans,height[i]);
	}
	printf("%d", ans);
	return 0;
}
