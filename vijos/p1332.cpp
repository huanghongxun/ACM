#include <iostream>
using namespace std;
int main() {
	int i,j,t,k,n,a[101],f[101][101][2],b[101];
	cin>>n;
	for (i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]>=0)
			b[i]=0;
		else {
			b[i]=1;
			a[i]=-a[i];
		}
		f[i][i][0]=f[i][i][1]=a[i];
	}
	for (t=1;t<n;t++)
		for (i=1;i<=n-t;i++) {
			j=i+t;
			f[i][j][0]=-99999999;
			f[i][j][1]=99999999;
			for (k=i+1;k<=j;k++) {
				if (b[k]==0) {
					f[i][j][0]=max(f[i][j][0],f[i][k-1][0]+f[k][j][0]);
					f[i][j][1]=min(f[i][j][1],f[i][k-1][1]+f[k][j][1]); 
				} else {
					f[i][j][0]=max(f[i][j][0],f[i][k-1][0]-f[k][j][1]);
					f[i][j][1]=min(f[i][j][1],f[i][k-1][1]-f[k][j][0]);
				}
			}
		}
	cout<<f[1][n][0];
}