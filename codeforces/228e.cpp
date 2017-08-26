#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 101, M = N*N/2;

vector<pair<int, bool> > g[N];
queue<pair<int, bool> > q;
bool vis[N], cl[N];
vector<int> res;

int main () {
    int n, a, b, c, m;
    scanf("%d%d", &n, &m);
    bool possible = true;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(make_pair(b, !c));
        g[b].push_back(make_pair(a, !c));
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            vector<vector<int> > c = vector<vector<int> >(2);
            q.push(make_pair(i, 0));
            while (!q.empty()) {
                auto top = q.front(); q.pop();
                if (vis[top.first]) {
                    if (cl[top.first] != top.second)
                        possible = false;
                    continue;
                }
                vis[top.first] = true;
                cl[top.first] = top.second;
                c[top.second].push_back(top.first);
                for (auto j : g[top.first])
                    q.push(make_pair(j.first, (top.second + j.second) % 2));
            }
            if (c[0].size() > c[1].size()) {
                for (int j : c[1]) res.push_back(j);
            } else {
                for (int j : c[0]) res.push_back(j);
            }
        }
    if (!possible) {
        puts("Impossible");
    } else {
        printf("%d\n", (int)res.size());
        for (int j : res) printf("%d ", j);
    }
    return 0;
}

