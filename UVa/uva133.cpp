#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 25;
int n, k, m;
int a[maxn];
int main() {
	int n, k, m, i;
    while (scanf("%d%d%d", &n, &k, &m) && n) {
        for (i = 1; i <= n; i++) a[i] = i;
        int left = n;
        int p1 = 1, p2 = n;
        while (left) {
            int cnt;
            for (cnt = 0; cnt < k; ++p1) {
                if (p1 == n + 1) p1 = 1;
                if (a[p1]) ++cnt;
            }
            --p1;
            for (cnt = 0; cnt < m; --p2) {
                if(p2 == 0) p2 = n;
                if(a[p2]) ++cnt;
            }
            ++p2;
            printf("%3d", p1);
            --left;
            if (p2 != p1) {
                printf("%3d", p2);
                --left;
            }
            a[p1] = a[p2] = 0;
            if (left) putchar(',');
        }
        putchar('\n');
    }
    return 0;
}