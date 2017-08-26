#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 10005
#define inf 0x7ffffff
int n;

vector<int> map[MAXN];
int first[MAXN];//结点在搜索顺序数组中最先出现的位置（下标）
int occur[MAXN<<1];//结点在出现的顺序数组重复的也要记录
int depth[MAXN<<1];//结点在搜索树中的深度，与occur相对应
int pos[MAXN<<1][20];//pos[i][j] 表示从第i个位置开始的2^j个元素中的最小值的下标
int indegree[MAXN];
int m=0;//不断记录出现的下标

void dfs(int u, int dep) {
    occur[++m] = u;//进入该点时进行记录
    depth[m] = dep;
    if(!first[u]) first[u] = m;
    for (int i = 0; i < map[u].size(); i++) {
        dfs(map[u][i], dep + 1);
        occur[++m] = u;//访问子树返回也要标记
        depth[m] = dep;
    }
}

int main() {
    int t, i, j, a, b;
    scanf("%d",&t);
    while(t--) {
        m=0;
        memset(first, 0, sizeof first);
        memset(indegree, 0, sizeof indegree);
        scanf("%d",&n);
        for(i=1;i<=n;i++) map[i].clear();
        for(i=1;i<n;i++) {
            scanf("%d%d",&a,&b);
            map[a].push_back(b);
            indegree[b] = true;
        }
        for(i=1;i<=n;i++) {
            if(!indegree[i]) {
                dfs(i,0);
                break;
            }
        }

        for(i = 1; i <= m;i++)
            pos[i][0] = i;
        for(j=1;j<20;j++)
            for(i=1;i<=m;i++) {
                if(i+(1<<j)-1 <= m) {
                    pos[i][j] = depth[pos[i][j-1]] < depth[pos[i+(1<<(j-1))][j-1]] ? pos[i][j-1] : pos[i+(1<<(j-1))][j-1];
                }
            }

        scanf("%d%d", &a, &b);
        int l=first[a],r=first[b];//得到区间左右端点
        if(l>r) swap(l, r);
        int k=(int)(log(double(r-l+1))/log(2.0));
        int min_id=depth[pos[l][k]]<depth[pos[r-(1<<k)+1][k]]?pos[l][k]:pos[r-(1<<k)+1][k];//最小值下标
        printf("%d\n", occur[min_id]);//取得当前下标表示的结点
    }
    return 0;
}
