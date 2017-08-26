#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, k;
double dfs(double x, double y, int split) {
    if(split==1) return max(x/y,y/x);
    double mi=1e9;
    for(int i=1;i<=split/2;i++) {
        mi=min(mi,max(dfs(x/split*i,y,i),dfs(x/split*(split-i),y,split-i)));
        mi=min(mi,max(dfs(x,y/split*i,i),dfs(x,y/split*(split-i),split-i)));
    }
    return mi;
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    printf("%.6lf\n",dfs(n,m,k));
    return 0;
}