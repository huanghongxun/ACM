#include <cstdio>
#define N 105
int d[N][N];
int n,ans=0x7ffffff;
void work(int now, int a, int b, int c, int s) {
	if(now == n-1) {
		if(s<ans) ans=s;
	} else {
		work(now+1,a+1,b,c,s+d[a][now+1]);
		work(now+1,a,b+1,c,s+d[b][now+1]);
		work(now+1,a,b,c+1,s+d[c][now+1]);
	}
}

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		d[i][i]=0;
		for(int j=i+1;j<n;j++) {
			scanf("%d",&d[i][j]);
			d[j][i]=d[i][j];
		}
	}
	work(0,0,0,0,0);
	printf("%d", ans);

	return 0;
}