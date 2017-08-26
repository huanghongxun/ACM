#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
const ll inf = 0x7f7f7f7f7f7f7f7fll;
const int N = 200005;
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;

vector<string> str, str_rev;
ll c[N], dp[N][2];

int main() {
    int n, i;
    string s;
    cin >> n;
    rep(i,0,n) cin >> c[i];
    rep(i,0,n) {
        cin >> s;
        str.push_back(s);
        reverse(s.begin(), s.end());
        str_rev.push_back(s);
    }
    memset(dp, 0x7f, sizeof dp);
    dp[0][0] = 0;
    dp[0][1] = c[0];
    rep(i,1,n) {
        if (str    [i - 1] <= str    [i]) dp[i][0] = min(dp[i - 1][0]       , dp[i][0]);
        if (str_rev[i - 1] <= str    [i]) dp[i][0] = min(dp[i - 1][1]       , dp[i][0]);
        if (str    [i - 1] <= str_rev[i]) dp[i][1] = min(dp[i - 1][0] + c[i], dp[i][1]);
        if (str_rev[i - 1] <= str_rev[i]) dp[i][1] = min(dp[i - 1][1] + c[i], dp[i][1]);
    }
    if (dp[n - 1][0] == inf && dp[n - 1][1] == inf)
        cout << -1;
    else
        cout << min(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}