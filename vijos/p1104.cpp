#include <iostream>
using namespace std;
#define V 1005
#define M 105

int t, m;
int c[M], w[M];
int f[V];

int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++) {
		cin>>c[i]>>w[i];
	}

	for(int i=1;i<=m;i++) {
		for(int j=t;j>=0;j--) {
			if(j-c[i]>=0)
				f[j] = max(f[j], f[j-c[i]]+w[i]);
		}
	}

	cout<<f[t];

	return 0;
}