#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    char ans[2][4] = { "NO", "YES" };
    int d, e, f, dp, ep, h, dep = 0;
    scanf("%d%d%d%d%d%d", &d, &e, &f, &dp, &ep, &h);

    for (--dp, --ep; dp != ep; dp /= 2, ep /= 2)
        ++dep;

    if (dep <= max(d, e))
        puts(ans[abs(d - e) <= h]);
    else
        puts(ans[dep * 2 - d - e <= h]);

    return 0;
}