#include <cstdio>
#include <algorithm>
#include <cmath>
#define RANGE 1000000
const int N = 100001;
using namespace std;

int read() {
    int s = 0, f = 1; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
    return s * f;
}

struct BIT {
    int c[2000005];
    int add(int x, int v) {
        x += RANGE + 1;
        for (; x <= 2 * RANGE + 1; x += x & -x) c[x] += v;
    }

    int sum(int x) {
        x += RANGE + 1;
        int s = 0;
        for (; x; x -= x & -x) s += c[x];
        return s;
    }

    void cover(int l, int r, int s) {
        if (l > r) return;
        l = max(l, -RANGE); r = min(r, RANGE);
        add(l, s); add(r + 1, -s);
    }
} bit;

struct Inequation {
    int x, y, c;
    Inequation() { x = y = c = 0; }
    Inequation(int u, int v, int w) {
        c = 0;
        if (u > 0) x = floor((double)(w - v) / u) + 1, y = RANGE;
        else if (u < 0) x = -RANGE, y = ceil((double)(w - v) / u) - 1;
        else if (v > w) x = -RANGE, y = RANGE;
        else x = 2, y = 1;
    }
} e[N];
int main() {
    int t = read(), i = 0, u, v, w; char op[8];
    while (t--) {
        scanf("%s", op);
        if (op[0] == 'A') {
            u = read(); v = read(); w = read();
            e[++i] = Inequation(u, v, w);
            bit.cover(e[i].x, e[i].y, 1);
        } else if (op[0] == 'D') {
            w = read();
            if (!e[w].c)
                e[w].c = 1, bit.cover(e[w].x, e[w].y, -1);
        } else
            printf("%d\n", bit.sum(read()));
    }
    return 0;
}