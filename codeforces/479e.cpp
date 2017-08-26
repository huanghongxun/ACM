using namespace std;

const int maxn = 5005;
const int mod = 1e9 + 7;

int N, A, B, K, dp[maxn][maxn];

void add (int idx, int l, int r, int d) {
    dp[idx][l] = (dp[idx][l] + d) % mod;
    dp[idx][r] = (dp[idx][r] - d + mod) % mod;
}

int main () {
    scanf("%d%d%d%d", &N, &A, &B, &K);

    dp[0][A] = 1;
    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= N; j++) {
            if (j == B) continue;
            int x = abs(j - B) - 1;
            add(i+1, max(j-x, 1), j, dp[i][j]);
            add(i+1, j+1, min(j+x+1, N + 1), dp[i][j]);
        }

        int mv = 0;
        for (int j = 1; j <= N; j++) {
            mv = (mv + dp[i+1][j]) % mod;
            dp[i+1][j] = mv;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = (ans + dp[K][i]) % mod;
    printf("%d\n", ans);
    return 0;
}