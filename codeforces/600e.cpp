#include <cstdio>
#include <map>
#include <algorithm>
using std::map; using std::swap;
const int N = 100001, M = 2 * N;
typedef long long ll;

int head[N], next[M], to[M], cnt = 0;
ll ans[N];
int color[N], n;

void add(int u, int v) {
    next[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}

struct State {
    map<int, int> m;
    int cnt; ll sum;
};

State dfs(int u, int fa) {
    State res;
    res.m[color[u]]++;
    res.cnt = 1;
    res.sum = color[u];

    for (int i = head[u]; i; i = next[i]) {
        if (to[i] == fa) continue;
        State sta = dfs(to[i], u);
        if (sta.m.size() > res.m.size()) {
            swap(sta.m, res.m);
            res.cnt = sta.cnt;
            res.sum = sta.sum;
        }
        for (auto it : sta.m) {
            int appear = res.m[it.first] += it.second;
            if (appear > res.cnt) {
                res.cnt = appear;
                res.sum = it.first;
            } else if (appear == res.cnt) {
                res.sum += it.first;
            }
        }
    }

    ans[u] = res.sum;

    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", color + i);
    for (int i = 1, x, y; i < n; i++) {
        scanf("%d %d", &x, &y);
        add(x, y); add(y, x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%I64d ", ans[i]);
    return 0;
}