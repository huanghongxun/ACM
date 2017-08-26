#include <cstdio>
#include <cstring>
#define rep(i,j,k) for(i=j;i<k;i++)
#define MAXN 200005
int sa[MAXN], rank[MAXN], wa[MAXN], wb[MAXN], height[MAXN], z[MAXN], bucket[MAXN];
char s[MAXN];

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
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		rep(i,0,n) if(sa[i]>=j) y[p++]=sa[i]-j;
		sort(x,y,n,m);
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j]?p-1:p++;
	}
}

void calHeight(int n) {
	int i, j, k = 0;
	for(i=1;i<=n;i++) rank[sa[i]]=i;
	rep(i,0,n) {
		if(k) k--;
		j=sa[rank[i]-1];
		while(s[i+k]==s[j+k])k++;
		height[rank[i]]=k;
	}
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	s[n]=0;
	da(n+1, 250);
	calHeight(n);
	for(int i=1;i<=n;i++) printf("%d ", sa[i]+1);
	printf("\n");
	for(int i=2;i<=n;i++) printf("%d ", height[i]);
	
	return 0;
}
