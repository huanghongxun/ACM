#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define rep(i,j,k) for(i=j;i<k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
using namespace std;
typedef long long ll;

int read() {
    int s=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}

int n,m;
int c[101][17],d[101],f[101][1<<16];
int main() {
    int i,j,k;
    n=read();m=read();
    FOR(i,1,n) {
        d[i]=read();
        FOR(j,1,m) c[i][j]=read();
    }
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    FOR(i,1,n) {
        rep(j,0,1<<m) f[i][j]=f[i-1][j]+d[i];
        FOR(k,1,m) rep(j,0,1<<m) if(~j&(1<<k-1))
            f[i][j|(1<<k-1)]=min(f[i][j|(1<<k-1)],f[i][j]+c[i][k]);
        rep(j,0,1<<m)
            f[i][j]=min(f[i][j],f[i-1][j]);
    }
    printf("%d", f[n][(1<<m)-1]);
    return 0;
}