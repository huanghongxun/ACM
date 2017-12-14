// UVALive 6176, HDU 4488
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 405;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
struct fraction {
    ll fz, fm;
    fraction() : fz(1), fm(1) {}
    fraction(ll fz, ll fm): fz(fz), fm(fm) {}
    fraction &operator+= (const fraction &b) {
        ll g1 = gcd(abs(fm), abs(b.fm));
        ll b1 = fm / g1 * b.fm;
        fz = b1 / fm * fz + b1 / b.fm * b.fz;
        fm = b1;
        g1 = gcd(abs(fz), abs(fm));
        fm /= g1;
        fz /= g1;
        return *this;
    }
    fraction operator- (const fraction & b) {
        ll g1 = gcd(abs(fm), abs(b.fm));
        ll b1 = fm / g1 * b.fm;
        fraction t;
        t.fz = b1 / fm * fz - b1 / b.fm * b.fz;
        t.fm = b1;
        g1 = gcd(abs(fz), abs(fm));
        t.fm /= g1;
        t.fz /= g1;
        return t;
    }
    fraction operator* (const fraction &b) {
        fraction t(1, 1);
        t.fz = fz * b.fz;
        t.fm = fm * b.fm;
        ll g = gcd(abs(t.fz), abs(t.fm));
        t.fz /= g;
        t.fm /= g;
        return t;
    }
    void print() {
        if (fm == 1) printf("%lld", fz);
        else printf("%lld/%lld", fz, fm);
    }
} f[N][N], unit(1, 1);

int main() {
    int T, kase, m, k, i, j;

    f[0][1] = unit;
    for (i = 1; i < N; ++i){
        fraction tmp(1, i + 1);
        f[i][i+1] = tmp;
        for (j = i; j >= 1; --j) {
            if (j > 1) {
                fraction t(i, j);
                f[i][j] = t * f[i-1][j-1];
                tmp += f[i][j];
            }
            else f[i][j] = unit - tmp;
        }
        
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &kase, &m, &k);
        printf("%d ", kase);
        f[m][k].print();
        putchar('\n');
    }
    return 0;
}