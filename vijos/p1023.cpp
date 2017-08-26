#include <cstdio>
int p[5005],k=0,n,i,x;
int find(int x) { return p[x]==x?x:p[x]=find(p[x]); }
int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<=n;i++) for(;;) {
		scanf("%d",&x); if(!x) break;
		p[find(x)]=p[find(i)];
	}
	for(i=1;i<=n;i++) if(p[i]==i) k++;
	printf("%d",k);
	return 0;
}