#include <iostream>
using namespace std;
int main()
{
	int day = 0, ma = 0, x, y;
	for(int i = 1; i <= 7; i++)
	{
		cin>>x>>y;
		if(x+y>ma)
		{
			ma = x+y;
			day = i;
		}
	}
	cout<<day;
	return 0;
}