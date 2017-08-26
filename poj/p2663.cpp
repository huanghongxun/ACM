#include <cstdio>
#include <cstring>
using namespace std;
int M,N=3;
long long dp[1<<3][30];
bool kexing[1<<3];
int full;
inline bool check(int in) {
    int bit=0;
    while(in>0) {
        if( (in&1)==1)
            bit++;
        else {
            if((bit&1)==1)
                return false;
            bit=0;
        }
        in>>=1;
    }
    return (bit&1)!=1;
}
inline bool check2(int x1,int x2) {
   if( (x1|x2)!= full-1 )  //如果这里不用位运算，时间很长，要用约3000MS
                return false;
    return kexing[x1&x2];
}
int main() {
    full = 1<<3;
    for(int s = 0; s < full; ++s) if(check(s)) kexing[s] = 1;
    while(scanf("%d",&M) != EOF) {
        if(M == -1)break;
        if(M == 0) {
            printf("1\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        full = 1<<N;
        for(int s = 0; s < full; ++s)
            if(kexing[s])
                dp[s][0] = 1;
        for(int i = 1; i < M; ++i)
            for(int s = 0; s < full; ++s)
                for(int s1 = 0; s1 < full; ++s1) {
                    if(!check2(s1,s))continue;
                    dp[s][i] += dp[s1][i-1];
                }
        int S = (1<<N) - 1;

        printf("%lld\n",dp[S][M-1]);
    }
    return 0;
}