#include <cstdio>
int a, b, n;
int num[100001];
void dfs(int x, int d) {
	if (x > n) {
		printf("%d", a);
		for(int i=1;i<=n;i++) printf("%d", num[i]);
		throw 1;
	} else
		for(int i=0;i<10;i++)
			if((d*10+i)%b==0) num[x]=i,dfs(x+1,0);
}
int main() {
	scanf("%d%d%d", &a, &b, &n);
	try {
		dfs(1,a);
		printf("-1");
	} catch(int x) {
	}
	return 0;
}