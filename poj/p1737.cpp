#include <cstdio>

const int base = 10000, power = 4, LEN = 1000, N = 51;
struct Num {
    int a[LEN], l;
    Num(int x = 0) {
        a[1] = x; repair();
    }
    void apply(const Num &b, int ratio) {
        for (int i = 1; i <= b.l; ++i)
            a[i] += ratio * b.a[i];
        repair();
    }
    Num &operator+= (const Num &b) { apply(b, 1); return *this; }
    Num &operator-= (const Num &b) { apply(b, -1); return *this; }
    Num &operator*= (const Num &b) {
        Num t;
        for (int i = 1; i <= b.l; ++i) {
            for (int j = 1; j <= l; ++j)
                t.a[i + j - 1] += b.a[i] * a[j];
            t.repair();
        }
        return *this = t;
    }
    Num &operator*= (int b) {
        for (int i = 1; i <= l; ++i) a[i] *= b;
        repair();
        return *this;
    }
    void repair() {
        int i;
        for (i = 1; a[i] != 0; ++i) {
            a[i + 1] += a[i] / base;
            a[i] %= base;
        }
        l = i - 1;
    }
    void output() {
        printf("%d", a[l]);
        for (int i = l - 1; i; --i)
            printf("%04d", a[i]);
    }
} c[N][N], a[N], pr[1230], t;
int n;

int main() {
    int i, j, n;
    pr[0] = 1;
    for (i = 1; i < 1230; ++i) {
        pr[i] = pr[i - 1];
        pr[i] *= 2;
    }
    c[0][0] = 1;
    for (i = 1; i <= 50; ++i) {
        c[i][0] = c[i][i] = 1;
        for (j = 1; j < i; ++j) {
            c[i][j] += c[i - 1][j];
            c[i][j] += c[i - 1][j - 1];
        }
    }
    a[1] = a[2] = 1; a[3] = 4;
    for (i = 4; i <= 50; ++i) {
        a[i] = pr[i * (i - 1) / 2];
        for (j = 1; j < i; ++j) {
            t = a[j];
            t *= c[i - 1][j - 1];
            t *= pr[(i - j) * (i - j - 1) / 2];
            a[i] -= t;
        }
    }
    while (scanf("%d", &n) && n) {
        a[n].output(); putchar('\n');
    }
    return 0;
}