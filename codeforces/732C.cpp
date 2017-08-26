#include <cstdio>
#include <algorithm>
using std::max;
typedef long long ll;
int main() {
    ll b, d, s;
    scanf("%I64d%I64d%I64d", &b, &d, &s);
    ll ma = max(max(b, d), s);
    printf("%I64d", max(ma - b - 1, 0ll) + max(ma - d - 1, 0ll) + max(ma - s - 1, 0ll));
    return 0;
}