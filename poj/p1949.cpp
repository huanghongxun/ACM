#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int Max = 10050;
int MaxTime[Max];
 
int main(){
    int n, i, t, k, cnt, ans = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++){
        scanf("%d%d", &t, &cnt);
        MaxTime[i] = t;
        while(cnt --){
            scanf("%d", &k);
            MaxTime[i] = max(MaxTime[i], t + MaxTime[k]);
        }
        ans = max(ans, MaxTime[i]);
    }
    printf("%d\n", ans);
    return 0;
}