#include <iostream>
using namespace std;
#define V 20001
#define N 31
int v, vv, n, i;
int f[V], w[N];

int main()
{
	cin>>v>>n;
	for(i = 1; i <= n; i++)
		cin>>w[i];
	for(i = 1; i <= n; i++)
		for(vv = v; vv >= w[i]; vv--)
			f[vv] = max(f[vv], f[vv-w[i]]+w[i]);
	cout<<v-f[v]<<endl;
	return 0;
}