#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 100010
#define rep(i,j,k) for(i=j;i<k;i++)
#define FOR(i,j,k) for(i=j;i<=k;i++)
char str[MAXN];
int s[MAXN];

template<typename T>
struct SuffixArray {
    T *r;
    int sa[MAXN], wa[MAXN], wb[MAXN], z[MAXN], bucket[MAXN], rank[MAXN], height[MAXN], n;
    int dp[MAXN][33];

    void init(T *s, int n) {
        (r = s)[this->n = n] = 0;
    }
    
    void sort(int *sa, int *x, int *y, int n, int m) {
        int i;
        rep(i,0,m) bucket[i] = 0;
        rep(i,0,n) bucket[x[y[i]]]++;
        rep(i,1,m) bucket[i] += bucket[i-1];
        for(i=n-1;i>=0;i--) sa[--bucket[x[y[i]]]] = y[i];
    }
    
    void da(int m) {
        int n=this->n+1;
        int i,j,p,*x=wa,*y=wb,*t;
        rep(i,0,n) x[i]=r[i],z[i]=i;
        sort(sa, x, z, n, m);
        for(j=1,p=1;p<n;j*=2,m=p) {
            p = 0;
            rep(i,n-j,n) y[p ++] = i;
            rep(i,0,n) if(sa[i] >= j) y[p ++] = sa[i] - j;
            sort(sa, x, y, n, m);
            t=x,x=y,y=t;p=1;x[sa[0]]=0;
            rep(i,1,n) x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        }
    }
    
    void calHeight() {
        int i, j, k = 0;
        FOR(i,1,n) rank[sa[i]] = i;
        rep(i,0,n) {
            if (k) k--;
            j = sa[rank[i]-1];
            while(r[i+k]==r[j+k]) k++;
            height[rank[i]] = k;
        }
    }
    
    void initRMQ() {
        int i, j;
        FOR(i,1,n) dp[i][0]=height[i];
        for(j=1;(1<<j)<=n;j++)
            for(i=1;i+(1<<j)-1<=n;i++)
                dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
    
    int query(int ll, int rr) {
        int k = 0;
        ll = rank[ll]; rr = rank[rr];
        if(ll > rr) swap(ll,rr);
        ll++;
        while((1<<(k+1))<=rr-ll+1) k++;
        return min(dp[ll][k],dp[rr-(1<<k)+1][k]);
    }
};
SuffixArray<int> sa;

int main() {
    int text=0, i;
    while(scanf("%s", str) && str[0] != '#') {
        int len=strlen(str);
        rep(i,0,len) s[i] = str[i] - 'a' + 1;
        sa.init(s, len);
        sa.da(30);
        sa.calHeight();
        sa.initRMQ();
        int ans = 0, pos = 0, lenn;
        FOR(i,1,len/2)
            for(int j = 0; j < len - i; j += i) {
                if (str[j] != str[j + i]) continue;
                int k = sa.query(j,j+i);
                int tol = k / i + 1;
                int r = i - k % i;
                int p = j;
                int cnt = 0;
                for(int m=j-1;m>j-i&&str[m]==str[m+i]&&m>=0;m--) {
                    cnt++;
                    if(cnt == r) {
                        tol++;
                        p = m;
                    } else if(sa.rank[p] > sa.rank[m]) {
                        p = m;
                    }
                }
                if(ans<tol) {
                    ans = tol;
                    pos = p;
                    lenn = tol*i;
                } else if(ans ==tol&&sa.rank[pos]>sa.rank[p]) {
                    pos=p;
                    lenn=tol*i;
                }
            }
        printf("Case %d: ", ++text);
        if(ans < 2) {
            char ch = 'z';
            rep(i,0,len) if(str[i] < ch) ch = str[i];
            printf("%c\n", ch);
            continue;
        }
        rep(i,pos,pos+lenn) printf("%c", str[i]);
        printf("\n");
    }
    return 0;
} 
