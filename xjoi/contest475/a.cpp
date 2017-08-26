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
ll read() {
    ll s=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}

int main() {
    ll n = read(), p, i;
    FOR(i,1,(100000000/n+1)) {
        int flag = 1;
        p = n * i;
        while (p > 0) {
            if (p%10>1) { flag = 0; break; }
            else p /= 10;
        }
        if (flag) {
            printf("%d", i);
            return 0;
        }
    }
    puts("NO");
    return 0;
}