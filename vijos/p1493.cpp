#include <iostream> 
#include <cstring>
using namespace std; 
int f[51][51][100]; 
int a[51][51]; 
int m,n,i,j,k; 
int max4(int x1,int x2,int x3,int x4){ 
	return max(x4,max(x3,max(x2,x1))); 
} 
int main() 
{ 
	memset(f,0,sizeof(f)); 
	memset(a,0,sizeof(a)); 
	cin>>m>>n; 
	for(i=1;i<=m;i++){ 
		for(j=1;j<=n;j++){ 
			cin>>a[i][j]; 
		} 
	} 
	for(k=1;k<=(m+n-1);k++){ 
		for(i=1;i<=m;i++){ 
			for(j=1;j<=m;j++){ 
				f[i][j][k]=max4(f[i][j][k-1],f[i-1][j][k-1],f[i][j-1][k-1],f[i-1][j-1][k-1]); 
				f[i][j][k]+=a[i][k+1-i]+a[j][k+1-j]; 
				if(i==j){
					f[i][j][k]-=a[i][k+1-i];
				} 
			} 
		} 
	} 
	cout<<f[m][m][m+n-1]; 
	return 0; 
}