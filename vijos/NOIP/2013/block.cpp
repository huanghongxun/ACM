#include <cstdio>
#define N 100005
int h[N], ans=0, n;
int main() {
	h[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&h[i]);
		if(h[i]>h[i-1]) ans+=h[i]-h[i-1];
	}
	printf("%d\n",ans);
	return 0;
}