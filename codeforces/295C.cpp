#include <queue>
#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
#include <algorithm>
#include <cstring>
#include <cmath>
typedef long long ll;
const int N = 55, MOD = 1000000007;
using namespace std;
struct Data { int n1, n2, type;
    int id() { return n1 * N * N + n2 * N + type; }
};
ll dis[N * N * 2], way[N * N * 2], C[N][N];
queue<Data> q;
int main() {  
    int i, j, x, n1 = 0, n2 = 0, n, k;
    Data h, p;
    FOR(i,0,50) C[i][0] = 1;
    FOR(i,1,50) FOR(j,1,50)
    FOR(i,0,50) C[i][0]=1;
    FOR(i,1,50) FOR(j,1,50)
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    FOR(i,1,n) {
        scanf("%d",&x);
        if (x == 50) n1++; else n2++;
    }
    h = (Data){n1, n2, 0};
    dis[h.id()] = 1;
    way[h.id()] = 1;
    q.push(h);
    while (!q.empty()) {
        u = q.front(); q.pop();
        FOR(j,0,u.n2) {
            if (j * 100 > k) break;
            FOR(j,0,u.n1) {
                 if (!j && !i) continue;
                 if (i * 50 + j * 100 > k) break;
                 v = (Data) {n1 - u.n1 + i, n2 - u.n2 + j, 1 - u.type};
                 if (!dis[v.id()]) {
                      dis[v.id()] = dis[u.id()] + 1;
                      q.push(v);
                 }
                 if (dis[v.id()] == dis[u.id()] + 1) {
                      ll t;
                      t = (C[u.n1][i] * C[u.n2][j]) % MOD;
                      (t *= way[u.id()]) %= MOD;
                      (way[v.id()] += t) %= MOD;
                 }
            }
        }
    }
    printf("%I64d\n%I64d\n", dis[((Data){n1,n2,1}).id()]-1,way[((Data){n1,n2,1}).id()]);
    return 0;
}
