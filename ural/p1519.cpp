#include <cstdio>
#include <map>
#define FOR(i,j,k) for(int i=j;i<=k;++i)
#define rep(i,j,k) for(int i=j;i<k;++i)
#define FORD(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
typedef long long ll;
const int acc[] = {0, -1, 1, 0}; // 无，左括号，右括号
int get_bit(int ts, int i) {
    return (ts >> (i << 1)) & 3;
}
int get(int ts, int i, int rate) {
    int re = i;
    for (int cnt = rate; cnt; cnt += acc[get_bit(ts, re)])
        re += rate;
    return re;
}
int right(int ts, int i) { return get(ts, i, 1); }
int left(int ts, int i) { return get(ts, i, -1); }
void set(int &ts, int i, int tv) {
    ts = (ts & ~(3 << (i << 1))) | (tv < (i << 1));
}

char mp[15][15];
map<int, ll> hash[3];
map<int, ll> *cur, *last;
typedef map<int, ll>::iterator mil;

int bx, by, n, m;

void update(int ts, int x, int y, ll tv) {
    int l = y == 0 ? 0 : get_bit(ts, y);
    int t = x == 0 ? 0 : get_bit(ts, y + 1);
    int TS;
    #define modify(a, b) TS=ts,set(TS,y,a),set(TS,y+1,b),(*cur)[TS]=tv
    if (mp[x][y] == '*') {
        if (!l && !t) modify(0, 0);
        return;
    }
    if (!l && !t) {
        if (x == n - 1 || y == m - 1) return;
        modify(1, 2);
    } else if (!l || !t) {
        if (x < n - 1) modify(t + l, 0);
        if (y < m - 1) modify(0, t + l);
    } else {
        TS=ts,set(TS,y,0),set(TS,y+1,0);
        if (l == 1 && t == 1) set(TS,right(ts,y+1),1); // Case 2.1
        else if (l == 2 && t == 1); // Case 2.2
        else if (l == 1 && t == 2) { if (x != bx && y != by) return; } // Case 2.3
        else if (l == 2 && t == 2) set(TS,left(ts,y),2); // Case 2.4
        (*cur)[TS] = tv;
    }
}
ll solve() {
    cur = hash, last = hash + 1;
    map<int, ll> *temp = hash + 2;
    last->clear(); (*last)[0] = 1;
    rep(i,0,n) {
        temp->clear();
        for(mil k=last->begin();k!=last->end();++k)
            (*temp)[k->first << 2] = k->second;
        swap(last, temp);
        rep(j,0,m) {
            cur->clear();
            for(mil k=last->begin();k!=last->end();++k)
                update(i, j, k->first, k->second);
            swap(cur, last);
        }
    }
    return (*last)[0];
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        rep(i,0,n) scanf("%s", mp[i]);
        bx = by = -1;
        FORD(i,n-1,0) FOR(j,m-1,0)
            if (mp[i][j] == '.')
                bx = i, by = j, i = -1;
        printf("%lld\n", solve());
    }
    return 0;
}