#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=min(j,k);i<=max(j,k);++i)

int main() {
    int i, j, it;
    while (scanf("%d%d", &i, &j) == 2) {
        int ans = 0;
        FOR(it,i,j) {
            int now = it, cnt = 1;
            for (; now != 1; ++cnt)
                if (now % 2 == 0)
                    now /= 2;
                else
                    now = now * 3 + 1;

            ans = max(ans, cnt);
        }
        printf("%d %d %d\n", i, j, ans);
    }

    return 0;
}