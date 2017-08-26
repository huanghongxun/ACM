#include <cstdio>
#include <cstring>
#include <climits>

inline int min(int a,int b) {
    return a<b?a:b;
}

int f[20],a[200],L,S,T,M,i,j,p,c,ans=INT_MAX,now,tot;

int main()
{
    scanf("%d%d%d%d",&L,&S,&T,&M);
    for (i=0;i<M;i++)
        scanf("%d",&a[i]);
    if (S==T)
    {
        ans=0;
        for (i=0;i<M;i++)
            if (a[i]%T==0)
                ans++;
        printf("%d",ans);
        return 0;
    }
    for (i=0;i<M-1;i++)
        for (j=i+1;j<M;j++)
        {
            if (a[i]>a[j])
            {
                c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    memset(f,0x7F,sizeof(f));
    f[0]=0; now=0; tot=0;
    for (i=1;i<L+T;i++)
    {
        for (j=S;j<=T;j++)
        {
            f[i%T]=min(f[i%T],f[(i-j+T)%T]);
        }
        if (a[p]==i)
        {
            f[i%T]++;
            p++;
        }
        if (now==f[i%T])
        {
            tot++;
        }
        else
        {
            now=f[i%T];
            tot=0;
        }
        if (tot==T)
        {
            i+=(min(a[p]-T,L)-i)/T*T;
        }
    }
    for (i=0;i<T;i++)
    {
        ans=min(ans,f[i]);
    }
    printf("%d\n",ans);
    return 0;
}