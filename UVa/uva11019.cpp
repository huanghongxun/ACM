#include <cstdio>
#define N 1005
#define MOD 2147483647
#define P 636291451ll //1344226405ll
typedef long long ll;

char getValidChar() {
    char ch=getchar();
    while(ch=='\n') ch=getchar();
    return ch-'a';
}

ll mod(ll a) {
    a%=MOD;
    if(a<0)a+=MOD;
    return a;
}

ll pows[1005];

struct Matrix {
    int x, y;
    int map[N][N];
    ll hash[N][N];
    ll hashw[N][N];
    
    void read() {
        scanf("%d%d", &x, &y);
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                map[i][j]=getValidChar();
    }
    
    void processHash(int w, int l) {
        for(int i=0;i<x;i++) {
            int h=0;
            for(int j=0;j<l;j++)
                h=mod(h+pows[j]*map[i][j]);
            hashw[i][0]=h;
            for(int j=1;j<=y-l;j++) {
                h=mod((h-map[i][j-1])*P+map[i][j+l-1]*pows[l-1]);
                hashw[i][j]=h;
            }
        }
        for(int i=0;i<y;i++) {
            int h=0;
            for(int j=0;j<w;j++)
                h=mod(h+pows[j]*hashw[j][i]);
            hash[0][i]=h;
            for(int j=1;j<=x-w;j++) {
                h=mod((h-hashw[j-1][i])*P+hashw[j+w-1][i]*pows[w-1]);
                hash[j][i]=h;
            }
        }
    }
} a, b;

int main() {
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);

    pows[0]=1;
    for(int i=1;i<=1000;i++) {
        pows[i]=mod(pows[i-1]*27);
    }
    
    int kase;
    scanf("%d", &kase);
    while(kase--) {
        a.read();
        b.read();
        a.processHash(b.x, b.y);
        b.processHash(b.x, b.y);
        int ans=0;
        for(int i=0;i<a.x;i++)
            for(int j=0;j<a.y;j++)
                if(a.hash[i][j]==b.hash[0][0]) ans++;
        printf("%d\n", ans);
    }
    
    return 0;
}