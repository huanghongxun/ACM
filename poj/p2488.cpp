#include <cstdio>
#include <cstring>
using namespace std;
#define move(a,x,y,i) a[x+dx[i]][y+dy[i]]

#define N 26

bool map[N][N];
int p, q;
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int wx[N*N], wy[N*N];

bool ok(int x, int y)
{
    if (x < 0 || y < 0 || x >= q || y >= p)
        return false;
    if (map[x][y])
        return false;
    return true;
}

bool dfs(int x, int y, int t)
{
    map[x][y] = 1;
    wx[t] = x;
    wy[t] = y;
    if (t == p * q - 1)
        return true;
    for (int i = 0; i < 8; i++)
        if (ok(x + dx[i], y + dy[i]))
            if(dfs(x + dx[i], y + dy[i], t + 1)) return true;
    map[x][y] = 0;
    return false;
}

void print() {
    for (int i = 0; i < p * q; i++)
        printf("%c%d", wx[i] + 'A', wy[i] + 1);
    printf("\n\n");
}

int main()
{
    int t, i, j;
    scanf("%d", &t);
    int s = 0;
    while (t--) {
        s++;
        printf("Scenario #%d:\n", s);
        memset(map, 0, sizeof(map));
        scanf("%d%d", &p, &q);
        /*for (i = 0; i < q; i++) {
            for (j = 0; j < p; j++) {
                if(dfs(i, j, 0)) { j = -1; break; }
            }
            if (j == -1) { i = -1; break; }
        }*/
        if (dfs(0, 0, 0)) print();
        else printf("impossible\n\n");
    }
    return 0;
}