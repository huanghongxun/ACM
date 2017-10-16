#include <cstdio>
const int N = 180500;
int prime[16384], vis[N], cnt = 0;

void get_primes() {
    int i, j;
    for (i = 2; i < N; ++i) {
        if (!vis[i])
            prime[cnt++] = i;
        for (j = 0; j < cnt; ++j) {
            if (i * prime[j] >= N)
                break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    int n, i;
    get_primes();

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &i);
        printf("%d\n", prime[i - 1]);
    }

    return 0;
}