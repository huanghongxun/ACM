#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
const int MaxN = 101;
vector<int> tree_conn[MaxN];
int f[MaxN][MaxN];
int w[MaxN];
int n;
int k;
int max(int a, int b)
{
    return a > b ? a : b;
}
void dp(int p, int c)
{
    int i;
    int j;
    for (j=k; j>=1; --j)
    {
        for (i=1; i<=j; ++i)
        {
            f[p][j] = max(f[p][i] + f[c][j-i], f[p][j]);
        }
    }
}
void dfs(int node, int parent)
{
    f[node][1] = w[node];
    vector<int>::iterator it;
    for (it=tree_conn[node].begin(); it!=tree_conn[node].end(); ++it)
    {
        if (*it == parent)
        {
            continue;
        }
        dfs(*it, node);
        dp(node, *it);
    }
}
int main()
{
    int i;
    int j;
    int x;
    int y;
    int mmax;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        for (i=0; i<n; ++i)
        {
            scanf("%d", w + i);
        }
        for (i=0; i<n; ++i)
        {
            tree_conn[i].clear();
        }
        for (i=0; i<n-1; ++i)
        {
            scanf("%d %d", &x, &y);
            tree_conn[x].push_back(y);
            tree_conn[y].push_back(x);
        }
        memset(f, 0, sizeof(f));
        dfs(0, 0);
        mmax = -1;
        for (i=0; i<n; ++i)
        {
            if (mmax < f[i][k])
            {
                mmax = f[i][k];
            }
        }
        printf("%d\n", mmax);
    }
    return 0;
}