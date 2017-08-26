#include <iostream>
#include <string>
using namespace std;

long long int jc(long long int a)
{
	long long int b = a;
	a--;
	while(a>0)
	{
		b *= a;
		a--;
	}
	return b;
}


int main()
{
	int n;
	int t = 1;
	int k = 1;
	int p = 0;
	long long int m;
	cin >> n >> m;
	int flag[n+1];
	m--;
	while((n-t)>=1)
	{
		long long temp = jc(n-t);
		p = m/temp;
		m %= temp;
		for(k = 1; k <=n; k++)
		{
			if(p==0) //找到当前数
			{
				if(flag[k] != 1)
				{
					cout << k << " ";
					flag[k] = 1;
					break;
				}
				else
				{
					continue;
				}
			}

			if(flag[k] == 1) //如果已经用过会被设为1
			{
				continue;
			}
			else
			{
				p--;
			}
		}
		t++;
	}

	for(int i = 1;i<=n;i++)
	{
		if(flag[i]!=1) cout << i;
	}
	return 0;
}
