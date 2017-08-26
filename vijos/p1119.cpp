#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAXN 101
#define MAXV 500
#define AddEdge(s,t,d) Add(s,t,d),Add(t,s,d)
int X[MAXN][4],Y[MAXN][4],C[MAXN];
int n,c,S,T,a,b;
int v[MAXN][4],V=0;
struct edge {
	edge *next;
	int t;
	double d;
} *head[MAXN];
void Add(int s,int t,double d) {
	edge *p=new(edge);
	p->t=t,p->next=head[s],p->d=d;
	head[s]=p;
}
bool check(int x1,int y1,int x2,int y2) {
	return x1*x2+y1*y2==0;
}
int Sqr(int x) {
	return x*x;
}
void INIT() {
	memset(head,0,sizeof(head));
	scanf("%d%d%d%d",&n,&c,&a,&b);
	for (int i=0;i<n;i++) {
		scanf("%d%d%d%d%d%d%d",&X[i][0],&Y[i][0],&X[i][1],&Y[i][1],&X[i][2],&Y[i][2],&C[i]);
		if (check(X[i][1]-X[i][0],Y[i][1]-Y[i][0],X[i][2]-X[i][0],Y[i][2]-Y[i][0])) {
			X[i][3]=X[i][0]+X[i][1]-X[i][0]+X[i][2]-X[i][0];
			Y[i][3]=Y[i][0]+Y[i][1]-Y[i][0]+Y[i][2]-Y[i][0];
		}
		if (check(X[i][0]-X[i][1],Y[i][0]-Y[i][1],X[i][2]-X[i][1],Y[i][2]-Y[i][1])) {
			X[i][3]=X[i][1]+X[i][0]-X[i][1]+X[i][2]-X[i][1];
			Y[i][3]=Y[i][1]+Y[i][0]-Y[i][1]+Y[i][2]-Y[i][1];
		}
		if (check(X[i][1]-X[i][2],Y[i][1]-Y[i][2],X[i][0]-X[i][2],Y[i][0]-Y[i][2])) {
			X[i][3]=X[i][2]+X[i][1]-X[i][2]+X[i][0]-X[i][2];
			Y[i][3]=Y[i][2]+Y[i][1]-Y[i][2]+Y[i][0]-Y[i][2];
		}
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<4;j++)
			v[i][j]=++V;
	S=++V;T=++V;
	for (int i=0;i<n;i++) {
		for (int j=0;j<4;j++) {
			for (int k=j+1;k<4;k++) {
				AddEdge(v[i][j],v[i][k],sqrt(Sqr(X[i][j]-X[i][k])+Sqr(Y[i][j]-Y[i][k]))*C[i]);
			}
		}
	}
	for (int i=0;i++<n;) {
		for (int j=i;j++<n;) {
			for (int k=0;k<4;k++) {
				for (int h=0;h<4;h++) {
					AddEdge(v[i][k],v[j][h],sqrt(Sqr(X[i][k]-X[j][h])+Sqr(Y[i][k]-Y[j][h]))*c);
				}
			}
		}
	}
	for (int i=0;i<4;i++) {
		AddEdge(S,v[a][i],0);
		AddEdge(v[b][i],T,0);
	}
}
double dist[MAXN];
void dfs(int v) {
	for (edge *p=head[v];p;p=p->next) {
		if (dist[p->t]>dist[v]+p->d) {
			dist[p->t]=dist[v]+p->d;
			dfs(p->t);
		}
	}
}
int main() {
	INIT();
	for (int i=0;i++<V;) dist[i]=0x7fffffff;
	dist[S]=0;
	dfs(S);
	printf("%.2f\n",dist[T]);
	return 0;
}