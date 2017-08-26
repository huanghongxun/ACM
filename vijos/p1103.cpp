#include <iostream>
#include <cstring>
using namespace std;
#define L 10005

bool road[L];

int l, m, a, b;

int main()
{
	cin>>l>>m;
	memset(road,1,sizeof(road));
	while(m--) {
		cin>>a>>b;
		for(int i=a;i<=b;i++) road[i]=0;
	}
	int ans = 0;
	for(int i=0;i<=l;i++) if(road[i]) ans++;
	cout<<ans;
	return 0;
}