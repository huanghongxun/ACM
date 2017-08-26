#include <cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define rep(i,j,k) for(i=j;i<k;i++)
#define MAXN 20050

int n, num[MAXN], z[MAXN];
int sa[MAXN], rank[MAXN], height[MAXN];
int wa[MAXN], wb[MAXN], wv[MAXN], wd[MAXN];

void sort(int *sa, int *x, int *bucket, int *y, int n, int m) {
    int i;
    rep(i,0,m) bucket[i] = 0;
    rep(i,0,n) bucket[x[i]]++;
    rep(i,1,m) bucket[i] += bucket[i-1];
    for(i = n-1; i >= 0; i --) sa[--bucket[x[i]]] = y[i];
}

void da(int *r, int n, int m) {
    int i, j, p, *x = wa, *y = wb, *t;
    rep(i,0,n) x[i] = r[i], z[i] = i;
    sort(sa, x, wd, z, n, m);
    for(j=1,p=1;p<n;j*=2,m=p) {
        p=0; // 排序第二关键字
        rep(i,n-j,n) y[p ++] = i;
        rep(i,0,n) if(sa[i]>=j) y[p++]=sa[i]-j;
        rep(i,0,n) wv[i] = x[y[i]];
        sort(sa, wv, wd, y, n, m); //排序第一关键字
        t=x,x=y,y=t;p=1;x[sa[0]]=0;
        rep(i,1,n) x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
    }
}

void calHeight(int *r, int n) {
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    rep(i,0,n) {
        if (k) k--;
        j = sa[rank[i]-1];
        while(r[i+k]==r[j+k]) k++;
        height[rank[i]] = k;
    }
}

bool valid(int len) {
    int i = 2, ma, mi;
    while(1) {
        while(i <= n && height[i] < len) i ++;
        if(i > n) break;    
        ma = sa[i-1];
        mi = sa[i-1];
        while(i <= n && height[i] >= len) {
            ma = max(ma, sa[i]);
            mi = min(mi, sa[i]);
            i ++;
        }
        if(ma - mi >= len) return true;
    }
    return false;
}

int main() {
    int i;
    while(scanf("%d", &n) && n != 0) {
        rep(i,0,n) scanf("%d", &num[i]);
        if(n < 10) {
            printf("0\n");
            continue;
        }
        n --;
        rep(i,0,n) num[i] = num[i+1] - num[i] + 89;
        num[n] = 0;
        da(num, n + 1, 200);
        calHeight(num, n);
        
        int low = 4, high = (n-1)/2, mid;
        while(low < high) {
            mid = (low + high + 1) / 2;
            if(valid(mid)) low = mid;
            else high = mid - 1;
        }
        printf("%d\n", low < 4 ? 0 : low + 1);
    }
    return 0;
}