#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;
#define N 524288
int dp[8][8];
char code[N];

int main() {
    int i, j, k, l;
    rep(i,0,8) dp[i][i] = 0;
    rep(i,0,8) rep(j,i+1,8) dp[j][i] = 8 - (dp[i][j] = j - i);
    
    while(scanf("%s", code) != EOF) {
        l = strlen(code);
        rep(i,0,l) code[i] -= '0';
        code[l] = code[0];
        rep(i,0,l) code[i] = dp[code[i]][code[i + 1]];
        i = 0, j = 1, k = 0;
        while (true) {
            if (i + k >= l || j + k >= l) break;
            if (code[i + k] == code[j + k]) ++k;
            else {
                if (code[j + k] > code[i + k]) j += k + 1;
                else i += k + 1;
                k = 0;
                if (i == j) ++j;
            }
        }
        int r = min(i, j);
        rep(i,0,l) printf("%d", code[(i + r) % l]);
        puts("");
    }
    return 0 ;
}
