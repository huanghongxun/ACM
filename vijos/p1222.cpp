#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long a, b, n, i, j, tans, mans;
long f1[10000], f2[10000], u1[10000], u2[10000];
int main() {
	cin>>n;
	memset(f1,0,sizeof(f1));
	memset(u1,0,sizeof(u1));
	u1[0 + 2600] = true;
	for(i = 1; i <= n; i++)
	{
		cin>>a>>b;
		memset(u2,0,sizeof(u2));
		memset(f2,0,sizeof(f2));
		for(j = -2500; j <= 2500; j++)
		{
			if(u1[j+a-b + 2600] && u1[j-a+b + 2600])
			{
				f2[j + 2600] = min(f1[j+a-b + 2600],f1[j-a+b + 2600]+1);
				u2[j + 2600] = true;
			}
			else
			if(u1[j+a-b + 2600])
			{
				f2[j + 2600] = f1[j+a-b + 2600];
				u2[j + 2600] = true;
			}
			else
			if(u1[j-a+b + 2600])
			{
				f2[j + 2600] = f1[j-a+b + 2600]+1;
				u2[j + 2600] = true;
			}
		}
                memcpy(u1, u2, sizeof(u2));
		memcpy(f1, f2, sizeof(f2));
	}
	for(i = 0; i <= 2500; i++)
	{
		if(u1[i + 2600] && u1[-i + 2600])
		{
			cout<<min(f1[i + 2600],f1[-i + 2600]);
			break;
		}
		if(u1[i])
		{
			cout<<f1[i + 2600];
			break;
		}
		if(u1[-i])
		{
			cout<<f1[-i + 2600];
			break;
		}
	}
        return 0;
}