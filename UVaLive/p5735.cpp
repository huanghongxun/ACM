#include <cstdio>
#include <algorithm>
#include <functional>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
const int N = 1048576;
pair<int, int> stock[N];
int sk[N];

int main() {
    int i, n, k1, k2, kase = 0;
    while (scanf("%d%d%d", &n, &k1, &k2) == 3 && n && k1 && k2) {
        FOR(i,1,n) scanf("%d", &stock[i].first), stock[i].second = i;
        sort(stock + 1, stock + 1 + n);
        FOR(i,1,k1) sk[i] = stock[i].second;
        sort(sk + 1, sk + 1 + k1);
        printf("Case %d\n", ++kase);
        FOR(i,1,k1) printf("%d%c", sk[i], i == k1 ? '\n' : ' ');
        FOR(i,n - k2 + 1,n) sk[n - i + 1] = stock[i].second;
        sort(sk + 1, sk + 1 + k2, greater<int>());
        FOR(i,1,k2) printf("%d%c", sk[i], i == k2 ? '\n' : ' ');
    }
    return 0;
}