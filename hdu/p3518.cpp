#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<k;i++)
using std::min;
using std::max;
#define N 1005
int wa[N], wb[N], sa[N], bucket[N], height[N], rank[N], z[N];
char s[N];

void sort(int *x, int *y, int n, int m) {
	int i;
	rep(i,0,m) bucket[i]=0;
	rep(i,0,n) bucket[x[y[i]]]++;
	rep(i,1,m) bucket[i]+=bucket[i-1];
	for(i=n-1;i>=0;i--) sa[--bucket[x[y[i]]]]=y[i];
}

void da(int n, int m) {
	int i, j, p, *x=wa, *y=wb, *t;
	rep(i,0,n) x[i]=s[i],z[i]=i;
	sort(x,z,n,m);
	for(j=1,p=1;p<n;j*=2,m=p) {
		p=0;
		rep(i,n-j,n) y[p++]=i;
		rep(i,0,n) if(sa[i]>=j) y[p++]=sa[i]-j;
		sort(x,y,n,m);
		t=x,x=y,y=t;p=1;x[sa[0]]=0;
		rep(i,1,n) x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j]?p-1:p++;
	}
}

void calHeight(int n) {
	int i,j,k=0;
	for(i=1;i<=n;i++) rank[sa[i]]=i;
	rep(i,0,n) {
		if(k) k--;
		j=sa[rank[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rank[i]]=k;
	}
}

int main() {
	while(scanf("%s", s) && s[0]!='#') {
		int n=strlen(s),ans=0;
		da(n+1,250);calHeight(n);
		for(int h=1;h<=n/2;h++) { //枚举子串长
			int l=n+2,r=-1;
			for(int j=2;j<=n;j++) {
				if(height[j]>=h) {
					l=min(min(sa[j],sa[j-1]),l);
					r=max(max(sa[j],sa[j-1]),r);
				} else {
					if(l+h<=r) ans++;
					l=n+2,r=-1;
				}
			}
			if(l+h<=r) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}