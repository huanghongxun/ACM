#include <iostream>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
typedef long long ull;
const int N = 8192;
ull p[N], q[N], year[N];
int main() {
    ull x, y, l, r, i, j, P, Q, Y = 0, ans = 0;
    p[0] = q[0] = 1;
    cin>>x>>y>>l>>r;
    for (P = 0; p[P] <= r / x; ++P) p[P + 1] = p[P] * x; // prevents out of range error
    for (Q = 0; q[Q] <= r / y; ++Q) q[Q + 1] = q[Q] * y;
    FOR(i,0,P) FOR(j,0,Q) if (p[i] + q[j] <= r && p[i] + q[j] >= l) year[++Y] = p[i] + q[j];
    year[++Y] = l - 1; year[++Y] = r + 1;
    sort(year + 1, year + 1 + Y);
    FOR(i,2,Y) ans = max(ans, year[i] - year[i - 1] - 1);
    cout<<ans;
    return 0;
}