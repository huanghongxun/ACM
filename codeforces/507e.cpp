#include <bits/stdc++.h>
using namespace std;
const int N = 100001;

int d[N], pre[N], num[N];
vector <pair <int, int>> e[N];
map<pair<int, int>, int> mp;
struct Data { int a, b, c; };
queue <int> q;

int main() {
    int n, m, x, y, z;
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++) {
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back({y, z});
        e[y].push_back({x, z});
        mp[{x, y}] = mp[{y, x}] = z;
    }
    
    d[1] = 1; q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto i : e[x])
            if (!d[i.first])
                pre[i.first] = x, num[i.first] = num[x] + i.second, d[i.first] = d[x] + 1, q.push(i.first);
            else if (d[i.first] > d[x] && num[i.first] < num[x] + i.second)
                pre[i.first] = x, num[i.first] = num[x] + i.second;  
    }
    vector<Data> ans;
    for (int i = n; i > 1; i = pre[i])  {
        if (mp[{i, pre[i]}] == 0)
            ans.push_back({i, pre[i], 1});
        mp[{i, pre[i]}] = mp[{pre[i], i}] = 2;    
    }
    
    for (auto it : mp)
        if (it.second == 1)
            ans.push_back({it.first.first, it.first.second, 0}), mp[{it.first.second, it.first.first}] = 2; 
    printf("%d\n", (int)ans.size());
    for (auto i : ans)
        printf("%d %d %d\n", i.a, i.b, i.c);
    return 0;
}