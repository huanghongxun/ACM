#include <stdio.h>
#include <string.h>
#define rep(i,j,k) for(i=j;i<k;i++)
const int INF=0x3f3f3f3f, N=105;
char s[N];
int f[N][N],split[N][N];

void output(int l,int r) {
    if (l>r) return;
    if (l==r) {
        if(s[l]=='(' || s[r]==')') printf("()");
        if(s[l]=='[' || s[r]==']') printf("[]");
        return;
    }

    if (split[l][r]==-1) {
        printf("%c",s[l]);
        output(l+1,r-1);
        printf("%c",s[r]);
    }
    else {
        output(l,split[l][r]);
        output(split[l][r]+1,r);
    }
}
int main() {
    int i,j,k,a,b,n;
    gets(s); n=strlen(s);
    if (n==0) goto end;
    rep(i,0,n) rep(j,0,n) f[i][j]=i>=j?0:inf;
    rep(i,0,n) f[i][i]=1;
    for (j=2;j<=n;j++)
        for (i=0;i<=n-j;i++) {
            a=i; b=i+j-1;
            if ((s[a]=='(' && s[b]==')') || (s[a]=='[' && s[b]==']')) {
                f[a][b]=f[a+1][b-1];
                split[a][b]=-1;
            }
            rep(k,a,b) if (f[a][k]+f[k+1][b]<f[a][b]) {
                f[a][b]=f[a][k]+f[k+1][b];
                split[a][b]=k;
            }
        }
    output(0,n-1);
end:
    printf("\n");
    return 0;
}
