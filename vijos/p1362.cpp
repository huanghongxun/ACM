#include <cstdio>
#include <iostream>
using namespace std;
int a[301][301],f[301];
int main(){
	int n,s,min=1000000;
	cin >>n >>s;
	for (int k=1;k<=n;++k)
		for (int m=1;m<=n;++m)
			if (k!=m) a[k][m]=min;
			else a[k][m]=0;
	for (int k=1;k<n;++k) {
		int x,y,z;
		cin >>x >>y >>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for (int k=1;k<=n;++k)
		for (int m=1;m<=n;++m)
			for (int p=1;p<=n;++p)
				if (a[m][k]+a[k][p]<a[m][p])
					a[m][p]=a[m][k]+a[k][p];
	for (int i=1;i<=n;++i)
		for (int j=i;j<=n;++j)
			if (a[i][j]>s) continue;
			else {
				for (int k=1;k<=n;++k)
					if ((k!=i)&&(k!=j))
						f[k]=1000000;
					else
						f[k]=0;
				for (int k=1;k<=n;++k)
					if (a[i][k]+a[k][j]!=a[i][j])
						continue;
					else {
						f[k]=0;
						for (int l=1;l<=n;++l)
							if (a[l][k]<f[l])
								f[l]=a[l][k];
					}
				int max=0;
				bool b=1;
				for (int k=1;k<=n;++k)
					if (f[k]>min) { b=0; break; }
					else if (f[k]>max) max=f[k];
				if ((b)&&(max<min))
				min=max;
			}
	cout <<min <<endl;
	return 0;
}