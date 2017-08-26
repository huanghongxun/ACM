#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[402];
int main()
{
    int cas;
    while(~scanf("%d", &cas))
        while(cas--)
        {
            memset(a,0,sizeof(a));
            int n,i,j,x,y;
            scanf("%d", &n);
            for(i=0;i<n;i++)
            {
                scanf("%d%d", &x, &y);
                if(x>y)swap(x,y);
                if(!(x&1))x--;
                if(y&1)y++;
                for(j=x;j<=y;j++)
                    a[j]++;
            }
            int ma=0;
            for(i=1;i<=400;i++)ma=max(ma,a[i]);
            printf("%d\n",ma*10);
        }
    return 0;
}