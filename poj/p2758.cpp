#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define mi 19931117
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define pwr(x) (1 << (x))
using namespace std;
char ori[60010];
int sa[60010], rank[60010], len, slen;
int *rankt, rt[2][60010], orik;
int height[60010], h[60010];
int st[60010][20];
bool genesis (const int &a, const int &b) { return ori[a] < ori[b]; }
bool revo (const int &a, const int &b)
{
    if (rankt[a] != rankt[b]) return rankt[a] < rankt[b];
    else return rankt[a + orik] < rankt[b + orik];
}
void sa_init ()
{
    int i, dl = 0, tl;
    for (i = 0; i < len; i++)
        sa[i] = i;
    sort(sa, sa + len, genesis);
    rt[0][sa[0]] = 0;
    for (i = 1; i < len; i++)
    {
        if (ori[sa[i]] == ori[sa[i - 1]]) rt[0][sa[i]] = rt[0][sa[i - 1]];
        else rt[0][sa[i]] = rt[0][sa[i - 1]] + 1;
    }
    for (orik = 1; orik < len; orik <<= 1)
    {
        rankt = rt[dl]; tl = dl; dl = 1 - dl;
        sort(sa, sa + len, revo);
        rt[dl][sa[0]] = 0;
        for (i = 1; i < len; i++)
        {
            if (rt[tl][sa[i]] == rt[tl][sa[i - 1]] && rt[tl][sa[i] + orik] == rt[tl][sa[i - 1] + orik])
                rt[dl][sa[i]] = rt[dl][sa[i - 1]];
            else rt[dl][sa[i]] = rt[dl][sa[i - 1]] + 1;
        }
    }
    for (i = 0; i < len; i++)
        rank[sa[i]] = i;
    return;
}
void lcp_init ()
{
    int i, j, r1, r2;
    for (i = 0; i < len; i++)
    {
        if (rank[i] == 0) h[i] = 0;
        else if (i == 0 || h[i - 1] <= 1)
        {
            r1 = i, r2 = sa[rank[i] - 1];
            for (j = 0; j + r1 < len && j + r2 < len; j++)
                if (ori[r1 + j] != ori[r2 + j]) break;
            h[i] = j;
        }
        else
        {
            r1 = i, r2 = sa[rank[i] - 1];
            for (j = h[i - 1] - 1; j + r1 < len && j + r2 < len; j++)
                if (ori[r1 + j] != ori[r2 + j]) break;
            h[i] = j;
        }
    }
    for (i = 0; i < len; i++)
        height[i] = h[sa[i]];
    for (i = 0; i < len; i++)
        st[i][0] = height[i];
    for (i = 1; pwr(i) <= len; i++)
    {
        for (j = 0; j + pwr(i) <= len && j + pwr(i - 1) < len; j++)
            st[j][i] = min(st[j][i - 1], st[j + pwr(i - 1)][i - 1]);
    }
    return;
}
int lcp (int a, int b)
{   
    int ra = rank[a], rb = rank[b], i;
    if (ra == rb) return slen - sa[ra];
    if (ra > rb) { i = ra; ra = rb; rb = i; }
    for (i = 0; pwr(i) <= rb - ra; i++); i--;
    return min(st[ra + 1][i], st[rb - pwr(i) + 1][i]);
}
int dist[60010], opos[60010], posi[60010];
void ins (char cp, int pl)
{
    int i;
    if (pl > len) pl = len - 1;
    for (i = len - 1; i >= pl; i--)
    {
        ori[i + 1] = ori[i];
        opos[i + 1] = opos[i];
        if (opos[i] != -1) posi[opos[i]] = i + 1;
    }
    ori[++len] = 0;
    ori[pl] = cp;
    opos[pl] = -1;
    for (i = pl - 1; i >= 0; i--)
    {
        if (opos[i] == -1) break;
        dist[opos[i]] = pl - i;
    }
}
int query (int a, int b, int ret)
{
    int lc = lcp(a, b), mis = min(dist[a], dist[b]), i;
    int ra = posi[a], rb = posi[b];
    if (lc < mis) return ret + lc;
    for (i = mis; ra + i <= len && rb + i <= len; i++)
    {
        if (ori[ra + i] != ori[rb + i] || !ori[ra + 1] || !ori[rb + i])
            return ret + i;
        else if (opos[ra + i] != -1 && opos[rb + i] != -1)
            return query(opos[ra + i], opos[rb + i], ret + i);
    }
}
int main ()
{
    int m, i, a, b; char ar[5], s[5];
    scanf("%s %d", ori, &m);
    len = strlen(ori);
    ori[len++] = '$';
    sa_init();
    lcp_init();
    for (i = 0; i < len; i++)
        dist[i] = mi, opos[i] = posi[i] = i;
    slen = len - 1;
    for (i = 0; i < m; i++)
    {
        scanf("%s", ar);
        if (ar[0] == 'Q')
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", query(a - 1, b - 1, 0));
        }
        else
        {
            scanf("%s %d", s, &a);
            ins(s[0], a - 1);
        }
    }
    return 0;
}