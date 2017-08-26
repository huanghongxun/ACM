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
	const int M = 1201, N = 601;
	static double c[N], a[M][N], b[M];
	int n=read(),k=read(),m=0;
	FOR(i,1,3*n) c[i]=read();
	for(i=1;i+n-1<=3*n;i++) {
		b[++m]=k;
		FOR(j,i,i+n-1) a[m][j]=1;
	}
	FOR(i,1,3*n) b[++m]=a[m][i]=1;
	printf("%d",(int)(simplex(a,b,c,m,n*3,0)+0.5));
	return 0;
}