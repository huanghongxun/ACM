#include <iostream>
using namespace std;
#define M 30
#define N 30005

typedef long long ll;

int n, m;
ll v[M], p[M];
ll f[N];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>v[i]>>p[i];
	for(int i=1;i<=m;i++)
		for(int j=n;j>=0;j--)
			if(j>=v[i])
				f[j]=max(f[j],f[j-v[i]]+p[i]*v[i]);
	cout<<f[n];

	return 0;
}