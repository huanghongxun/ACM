#include <iostream>
using namespace std;
int f[200001],n,m,x,y,cas;
char c;
int find(int x) {
    if (x!=f[x]) f[x] = find(f[x]);
    return f[x]; 
}
void merge(int x,int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) f[px] = py;
}  
int main() {
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=2*n;i++) f[i] = i;
        for (int i=1;i<=m;i++) {
            scanf("%c%c %d %d",&c,&c,&x,&y);
            if (c=='D') {
                merge(x,y+n);
                merge(y,x+n);
            }
            else {
                if (find(x)==find(y)) printf("In the same gang.\n");
                else if (find(x)==find(y+n)||find(y)==find(x+n))
                    printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}
