#include <cstdio>
using namespace std;
const int MAX = 100;
 
double ans[MAX];
double dp[MAX][MAX];
 
int main(){
    int i, j, id;
    for(i = 1; i < MAX; i ++){
        ans[i] = 2;
        dp[i][1] = dp[1][i] = dp[i][i] = 1;
    }
    ans[1] = 1;
    for(i = 1; i < MAX; i ++)
        for(j = 2; j < i; j ++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] * j;
            ans[i] += dp[i][j];
        }
    while(scanf("%d", &id) && id)
        printf("%d %.0f\n", id, ans[id]);
    return 0;
}