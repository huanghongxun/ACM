#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200001;
int main() {
    int n, m, i, q;
    static int a[N];
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    while (m--) {
        scanf("%d", &q);
        printf("%d ", upper_bound(a, a + n, q) - a);
    }
    return 0;
}