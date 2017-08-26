/*#include <stdio.h>
using namespace std;
int main()
{
	int m,s,t,dis,ti;
	ti=0;
	dis=0;
	scanf("%d%d%d", &m, &s, &t);
	while (1)
	{
		if (dis >= s)
		{
			puts("Yes");
			printf("%d\n", ti);
			break;
		}
		else
		{
			if (ti < t)
			{
				if (m >= 10)
				{
					m -= 10;
					dis += 60;
				}
				else
				{
					if (s - dis >= 60 && t - ti >= ((10-m)-(10-m)%4) / 4 + 1 + 1)
						m+=4;
					else
						dis+=17;
				}
				ti++;
			}
			else
			{
				puts("No");
				printf("%d\n", dis);
				break;
			}
		}
	}
	return 0;
}*/

#include <iostream>
using namespace std;

long m, s, t, dis, i, l, r, mid, m1;

int main()
{
    cin>>m>>s>>t;
    m1 = m;
    dis = 0;
    for(i = 1; i <= t; i++)
    {
        if(m >= 10 || m >= 6 && t - i >= 1 ||
           m >= 2 && t - i >= 2 || t - i >= 6)
        {
            if(m >= 10)
            {
                m -= 10;
                dis += 60;
            }
            else
                m += 4;
        }
        else
            dis += 17;
        if(dis >= s)
        {
        	mid = i;
        	break;
        }
    }
    
    m = m1;
    if(dis < s)
    {
        cout<<"No"<<endl;
        cout<<dis<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
        cout<<mid<<endl;
    }
    
    return 0;
}

#include <stdio.h>
long m,s,t;
void work()
{
	long i,a=0,b=0;
	for(i=1;i<=t;i++)
	{
		if(m>=10)
		{
			b=b+60;m=m-10;
		}
		else
		m=m+4;
		if(b>a+17)a=b;
		else a=a+17;
		if(a>=s)
		{
			printf("Yes\n%ld",i);
			break;
		}
	}
	if(i>t)
		printf("No\n%d",a);
}
int main()
{
	scanf("%ld%ld%ld",&m,&s,&t);
	work();
	return 0;
}