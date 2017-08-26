#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

FILE *fin, *fout;

const int n = 4000, m = 8000;

int adj[n + 5][n + 5];
int fat[n + 5], col[n + 5], last[n + 5], ans;
int vis[n + 5];

int find(int x)
{
if (fat[x] != x) fat[x] = find(fat[x]); return fat[x];
}

void dfs(int t, int u)
{
last[t] = u;
for (int i = 1; i <= n; i++)
if (adj[t][i] && i != u) dfs(i, t);
}

int lca(int x, int y)
{
for (int i = 1; i <= n; i++) vis[i] = 0;
while (x){
vis[x] = 1; x = last[x];
}
while (!vis[y]) y = last[y];
return y;
}

void paint(int x, int u, int c)
{
while (x != u){
col[x] = c; x = last[x];
} col[u] = c;
}

void calc(int x, int u)
{
while (x != last[u]){
if (col[x] != col[last[x]] || x == u) ans++; x = last[x];
}
}

int main()
{
fin = fopen("paint.in", "w");
fout = fopen("force.out", "w");
int i, u, v, c, j, k;
fprintf(fin, "%d %d\n", n, m);
for (i = 1; i <= n; i++) fat[i] = i;
srand(time(0));
for (i = 1; i <= n; i++){
col[i] = rand() % 10; fprintf(fin, "%d ", col[i]);
} fprintf(fin, "\n");
for (i = 1; i < n; i++)
while (1){
u = rand() % n + 1; v = rand() % n + 1;
if (find(u) == find(v)) continue;
fat[find(v)] = fat[u]; adj[u][v] = adj[v][u] = 1;
fprintf(fin, "%d %d\n", u, v); break;
}
dfs(1, 0);
for (i = 1; i <= m; i++){
k = rand() % 3;
if (k == 0){
u = rand() % n + 1; v = rand() % n + 1; c = rand() % 20;
fprintf(fin, "C %d %d %d\n", u, v, c);
j = lca(u, v); paint(u, j, c); paint(v, j, c);
} else {
u = rand() % n + 1; v = rand() % n + 1; 
fprintf(fin, "Q %d %d\n", u, v);
j = lca(u, v); ans = -1;
calc(u, j); calc(v, j);
fprintf(fout, "%d\n", ans);
}
}
fclose(fin); fclose(fout);
return 0;
}
