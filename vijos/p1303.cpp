#include <cstdio>
#include <climits>
#include <iostream>
#include <set>
using namespace std;

#define N 100
int n, a[N + 1], x, q[N + 1], tot = 0;
set <int> h;
set <int> :: iterator it;

int main() {

    while (scanf("%d%*c", &x) != EOF) a[++n] = x;

    q[0] = INT_MAX;
    for (int i = 1; i <= n; ++i)
        if (!tot || q[tot] >= a[i]) q[++tot] = a[i];
        else {
            int l = 0, r = tot;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (q[mid] >= a[i]) l = mid;
                else r = mid - 1;
            }
            q[l + 1] = max(q[l + 1], a[i]);
        }

    for (int i = 1; i <= n; ++i) {
        it = h.lower_bound(a[i]);
        if (it == h.end()) h.insert(a[i]);
        else {
            h.erase(it);
            h.insert(a[i]);
        }
    }

    cout << tot << "," << h.size() - 1 << endl;
    return 0;
}