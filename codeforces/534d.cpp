#include <cstdio>
#include <vector>
#define FOR(i,j,k) for(i=j;i<=k;i++)
using namespace std;
const int N = 200001;
int n, a[N], ans[N], len;
vector<int> vec[N];
int main() { 
    int i,j,k;  
    scanf("%d",&n);  
    len = 0;
    FOR(i,1,n) {
        scanf("%d", &a[i]);
        vec[a[i]].push_back(i);
    }
    int now = 0, flag = 1;
    FOR(i,1,n) {
        while (now >= 0 && vec[now].empty()) now -= 3;
        if (now < 0) { flag = 0; break; }
        ans[++len] = vec[now].back();
        vec[now++].pop_back();
    }
    if(flag) {
        puts("Possible");
        FOR(i,1,len) printf("%d ",ans[i]);
    } else puts("Impossible");
  
    return 0;  
}  