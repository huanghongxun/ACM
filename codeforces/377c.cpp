#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int N = 100, M = 20, STATE = 1 << 20, inf = 2147483647;
int s[N], team[M], wa[STATE], wb[STATE];
char action[M][2];

int countBit(int n) {
    int ans = 0;
    for (; n; ans++) n &= n - 1;
    return ans;
}

int main() {
    int n, i, m, *best = wa, *nbest = wb;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", s + i);
    sort (s, s + n, greater<int>());
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%s%d", action[i], team + i);
    for (i = m - 1; i >= 0; i--) {
        fill(nbest, nbest + STATE, team[i] == 1 ? -inf : inf);
        for (int sta = 0; sta < STATE; sta++) {
            if (countBit(sta) != i) continue;
            for (int j = 0; j < m; j++)
                if ((sta & (1 << j)) == 0) {
                    int nsta = sta | (1 << j);
                    if (action[i][0] == 'b')
                        if (team[i] == 1)
                            nbest[sta] = max(nbest[sta], best[nsta]);
                        else
                            nbest[sta] = min(nbest[sta], best[nsta]);
                    else
                        if (team[i] == 1)
                            nbest[sta] = max(nbest[sta], best[nsta] + s[j]);
                        else
                            nbest[sta] = min(nbest[sta], best[nsta] - s[j]);
                }
        }
        swap(best, nbest);
    }
    printf("%d", best[0]);
    return 0;
}