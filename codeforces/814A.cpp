#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <functional>
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define rep(i,j,k) for(i=j;i<k;++i)
typedef long long ll;
const int inf = 2147483647;
const int N = 105;
using namespace std;

int a[N], b[N];

int main() {
    //freopen("aaa.in","r",stdin);
    //freopen("aaa.out","w",stdout);

    int n, k, i, j = 0;
    scanf("%d%d", &n, &k);

    FOR(i,1,n) scanf("%d", a + i);
    FOR(i,1,k) scanf("%d", b + i);
    sort(b + 1, b + 1 + k, greater<int>());
    FOR(i,1,n) if (a[i] == 0) a[i] = b[++j];
    FOR(i,2,n) if (a[i] <= a[i - 1]) break;
    if (i <= n) puts("Yes");
    else puts("No");

    return 0;
}