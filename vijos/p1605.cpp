#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int p [1010],col[1010],Min[1010],pai[3][1010],l[3],wei[10010],las[10010],too[10010];
int n,t=0,should=1;
void line(int x,int y) {
	las[++t] = wei[x]; wei[x] = t; too[t] = y;
	las[++t] = wei[y]; wei[y] = t; too[t] = x;
}
void draw(int x,int c) {
	if (!col[x] ) col[x]=c; else
	if ( col[x]!=c) {printf("0");exit(0);} else return;
	for (int i=wei[x]; i; i=las[i]) draw(too[i],3-c); 
}
int main() {
	scanf("%d",&n); for (int i=1 ; i<=n; i++) scanf("%d",&p[i]);
	Min[n] = p[n]; for (int i=n-1; i>=1; i--) Min[i]=min(Min[i+1],p[i]);
	pai[1][0]=1002; col[n+1]=1; pai[2][0]=1002; p[n+1]=1001;
	for (int i=1 ; i<=n-2; i++)
	for (int j=i+1; j<=n-1; j++) 
	if(p[i]<p[j]&&Min[j+1]<p[i]) line(i,j);
	for (int i=1 ; i<=n ; i++) 
	if ( !col[ i ] ) draw(i,1);
	for (int i=1 ; i<=n+1; i++) {
	int f=1;
	while (f)
	if ( pai[1][l[1]] == should ) {should++; l[1]--; printf("b ");} else
	if ( pai[2][l[2]] == should ) {should++; l[2]--; printf("d ");} else f=0;
	pai[ col[i] ][ ++l[ col[i] ] ]=p[i];
	if (i<n+1) printf("%c ", char(2*col[i]+95) );
	}
	return 0;
}