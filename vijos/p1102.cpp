#include <iostream>
using namespace std;

int height;
int apple[10];

int main()
{
	for(int i=0;i<10;i++) cin>>apple[i];
	cin>>height;
	int ans = 0;
	for(int i=0;i<10;i++) if(apple[i]<=height+30) ans++;
	cout<<ans;
	return 0;
}