#include <cstdio>
#define rep(i,j,k) for(i=j;i<k;i++)
int c[5]={-1,1,0,-2,2};
char a[101][101];
int p[101*101], n, m, s = 0, i, j;
inline int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}
inline int get(int x, int y) {
	return x*m+y;
}
inline int inmap(int x, int y) {
	return get(x,y)>=get(0,0)&&get(x,y)<=get(n-1,m-1);
}
void f(int x,int y) {
	int i, j;
	rep(i,0,5) rep(j,0,5)
		if(inmap(x+c[i],y+c[j]))
		if (a[x+c[i]][y+c[j]]=='#') {
			p[find(get(x+c[i],y+c[j]))]=p[find(get(x,y))];
		}
}
inline char getChar() {
	char ch;
	while(1) {
		ch = getchar();
		if(ch == '-' || ch == '#') break;
	}
	return ch;
}
int main() {
	scanf("%d%d", &n, &m);
	rep(i,0,n) rep(j,0,m)
		a[i][j]=getChar(),p[get(i,j)]=get(i,j);
	rep(i,0,n) rep(j,0,m) if(a[i][j]=='#') f(i,j);
	rep(i,0,n) rep(j,0,m) {
		int k=get(i,j);
		if(p[k]==k&&a[i][j]=='#') {
			s++;
			//printf("%d %d\n", i, j);
		}
	}
	printf("%d", s);
	return 0;
}