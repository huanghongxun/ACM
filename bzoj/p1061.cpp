#include <cstdio>
#include <cmath>
const double eps = 1e-7;
const double inf = 1e30;
#define FOR(i,j,k) for(i=j;i<=k;i++)
int read() {
	int s=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;'0'<=ch&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*f;
}
template<int M, int N>
void pivot(double (&a)[M][N], double (&b)[M], double (&c)[N], int m, int n, int l, int e, int &v) {
	int i, j, k;
	b[l] /= a[l][e];
	FOR(i,1,n) if (i!=e) a[l][i]/=a[l][e];
	a[l][e]=1/a[l][e];
	FOR(i,1,m)if(i!=l&&fabs(a[i][e])>eps) {
		b[i]-=a[i][e]*b[l];
		FOR(j,1,n)if(j!=e)
			a[i][j]-=a[i][e]*a[l][j];
		a[i][e]=-a[i][e]*a[l][e];
	}
	v+=c[e]*b[l];
	FOR(i,1,n)if(i!=e)c[i]-=c[e]*a[l][i];
	c[e]=-c[e]*a[l][e];
}
template<int M, int N>
double simplex(double (&a)[M][N], double (&b)[M], double (&c)[N], int m, int n, int v) {
	int i,e;
	while (1) {
		FOR(i,1,n) if (c[i]>eps) break;
		if (i==n+1) return v;
		double t=inf,l;e=i;
		FOR(i,1,m)
			if(a[i][e]>eps&&t>b[i]/a[i][e])
				t=b[i]/a[i][e],l=i;
		if(t==inf) return inf;
		pivot(a, b, c, m, n, l, e, v);
	}
	return inf;
}
int main() {
	int i,j,x,y,z;
	const int M = 10001, N = 1001;
	static double c[N], a[M][N], b[M];
	int n=read(),m=read();
	FOR(i,1,n) c[i]=read();
	FOR(i,1,m) {
		x=read(),y=read(),z=read();
		FOR(j,x,y) a[i][j]=1;
		b[i]=z;
	}
	printf("%d",(int)(simplex(a,b,c,m,n,0)+0.5));
	return 0;
}