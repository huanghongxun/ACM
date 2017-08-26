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
#define RE(i,j) for(i=0;i<j;i++)
#define FO(i,j) for(i=1;i<=j;i++)
using namespace std;
typedef long long ll;
ll read() {
    ll s = 0, f = 1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
 
const int N = 64;
ll n, m;
ll a[N], p[N];
 
int phi(int n) {
    int res = n, x = n, i;  
    for(i = 2; i * i <= n; i++)
        if(n % i == 0) {  
            res = res / i * (i - 1);
            while(n % i == 0) n /= i;  
        }
    if(n > 1) res = res / n * (n - 1);  
    return res;  
}  
 
ll get(ll x) {
    int i;
    FOR(i,1,m)
        if(p[i] != p[i-1] && x % p[i] == 0)
            return phi(n / x);
    return 0;
}
 
int main() {
    ll i, j, ans = 0;
    n = read(); m = read();
    FOR(i,1,m) p[i] = gcd(n, a[i] = read());
    sort(p + 1, p + m + 1);
    for (i = 1; i * i <= n; i++)
        if(n % i == 0) {
            ans += get(i);
            if (i * i != n) ans += get(n / i);
        }
    printf("%lld", n - ans);
    return 0;
}
