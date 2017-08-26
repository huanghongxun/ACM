#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int N = 1000005;
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define foreach(i,j) for(typeof(j.begin()) i=j.begin();i!=j.end();++i)
int fa[N], c[N], ans = 0;
set<int> h[N];
int main() {
    int i, n, m, f, a, b;
    scanf("%d%d", &n, &m);
    FOR(i,1,n) scanf("%d", &c[i]);
    FOR(i,1,n) {
        fa[c[i]] = c[i];
        h[c[i]].insert(i);
        if (c[i] != c[i - 1]) ++ans;
    }
    while (m--) {
        scanf("%d", &f);
        if (f == 2) printf("%d\n", ans);
        else {
            scanf("%d%d", &a, &b);
            if (a == b) continue;
            if (h[fa[a]].size() > h[fa[b]].size())
                swap(fa[a], fa[b]);
            a = fa[a]; b = fa[b];
            foreach(i, h[a]) {
                if (c[*i - 1] == b) --ans;
                if (c[*i + 1] == b) --ans;
                h[b].insert(*i);
            }
            foreach(i, h[a]) c[*i] = b;
            h[a].clear();
        }
    }
    return 0;
}