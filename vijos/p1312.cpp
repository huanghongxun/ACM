#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans=0,t[210],w[210],a[210][210];
int get(int l,int r) {
	if (a[l][r])
		return a[l][r];
	for (int i=l; i<r; i++)
		a[l][r]=max(a[l][r],get(l,i)+get(i+1,r)+t[l]*w[i]*w[r]);
	return a[l][r];
}
int main() {
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d",&t[i]);
		w[i-1]=t[i+n]=w[i+n-1]=t[i];
	}
	for (int i=1; i<=n; i++) ans=max(ans,get(i,i+n-1));
	printf("%d",ans);
	return 0;
}