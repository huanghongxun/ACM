#include <stdio.h>
#include <algorithm>
using namespace std;
define MAXN 100
int map[MAXN][MAXN];
int h[MAXN];
int n,m;
int gap[MAXN];
bool f;
int sap(int v,int flow){
	int rec=0,minh=n;
	if (v==n+1){
		f=true;
		return flow;
	}
	for (int i=0;i++<n+1;){
		if (map[v][i]){
			if (h[i]==h[v]-1){
				int ret=sap(i,min(flow-rec,map[v][i]));
				map[v][i]-=ret;
				map[i][v]+=ret;
				rec+=ret;
				if (flow==rec) return flow;
				if (h[1]>=n+1) return rec;
			}
			minh=min(h[i],minh);
		}
	}
	if (!f){
		h[v]=minh+1;
	}
	if (!(--gap[h[v]])){
		h[1]=n+1;
	}

	gap[h[v]]++;
	return rec;
}
int main(){
	int ans=0;
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n+1;i++){
		for (int j=0;j<=n+1;j++){
			map[i][j]=0;
		}
	}
	for (int i=0;i<=n+1;i++){
		h[i]=0;
	}
	while (m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]+=z;
		map[y][x]+=z;
	}
	scanf("%d",&m);
	while (m--){
		int x;
		scanf("%d",&x);
		map[x][n+1]=100000;
	}
	gap[0]=n+1;
	while (h[1]<n+1){
		f=false;
		ans+=sap(1,0x7ffffff);
	}
	printf("%d\n",ans);
	return 0;
}