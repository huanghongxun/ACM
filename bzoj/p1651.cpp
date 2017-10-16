#include <cstdio>
#include <queue>
using namespace std;
int read() {
    int s = 0, f = 1; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
    return s * f;
}
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int main() {
    int n = read(), i, a, b, x = 0, ans = 0;
    for (i = 1; i <= n; ++i) {
        pq.push(make_pair(read(), 1));
        pq.push(make_pair(read() + 1, -1));
    }
    while (!pq.empty()) {
        pair<int, int> u = pq.top();
        pq.pop();
        x += u.second;
        if (x > ans) ans = x;
    }
    printf("%d", ans);
    return 0;
}