#include <stdio.h>
#include <string.h>
using namespace std;
#define N 10005
#define M 105

typedef long long ll;

ll n, m, now, i, j;
ll up[N][M], card[N][M], louti[M], loutitot[N], lt[N][M];

ll mod(ll s, ll m) {
    ll r = s;
    while(r>=m) r-=m;
    return r;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    memset(loutitot,0,sizeof(loutitot));
    for(i=1;i<=n;i++)
        for(j=0;j<m;j++)
            scanf("%d%d", &up[i][j], &card[i][j]);
    scanf("%d", &now);
    ll sum = 0;
    for(i=1;i<=n;i++) {
        sum = mod(sum+card[i][now],20123);
        ll d = card[i][now];
        ll k = 0;
        for(j=now;j<m;j++)
            if(up[i][j])
                louti[++k] = j;
        for(j=0;j<now;j++)
            if(up[i][j])
                louti[++k] = j;
        d=mod(d,k);
        if(d==0) d=k;
        now=louti[d];
    }
    printf("%lld", sum);
    return 0;
}