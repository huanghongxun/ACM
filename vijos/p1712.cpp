#include <iostream>
using namespace std;

long long x, y;

int main()
{
	cin>>x>>y;
	if(x>=0)
		if(y>-x&&y<=x)
			cout<<(2*x-1)*(2*x-1)+y+x-1;
		else if(y>=0)
			cout<<2*y*2*y-y-x;
		else
			cout<<(2*-y+1)*(2*-y+1)+y+x-1;
	else if (y>=x&&y<=-x)
		cout<<2*x*2*x-y-x;
	else if(y>=0)
		cout<<2*y*2*y-y-x;
	else cout<<(2*-y+1)+y+x-1;
	return 0;
}