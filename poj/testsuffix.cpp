#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define MAXN 20
struct SuffixArray {
    char *s;
    // suffix array, 2 temp array, bucket sort auxiliary array, string length.
    int sa[MAXN], t[MAXN], t2[MAXN], c[MAXN], rank[MAXN], height[MAXN], n;

    void init(char *s, int n) {
    	this->s = s;
    	this->n = n;
    }
    
    struct Rank {
    	int x, y, id;
    	friend bool operator < (const Rank &a, const Rank &b) {
    		return a.x == b.x ? a.y < b.y : a.x < b.x;
    	}
    	friend bool operator == (const Rank &a, const Rank &b) {
    		return a.x == b.x && a.y == b.y;
    	}
    } pairs[MAXN];
    
	void build() {
		int i, j, k;
		rep(i,0,n) rank[i]=s[i];
		for(k=1;k<=n;k*=2) {
			rep(i,0,n) {
				pairs[i].x=rank[i];
				if(i<n-k) pairs[i].y=rank[i+1];
				else pairs[i].y=-1;
				pairs[i].id=i;
			}
			sort(pairs, pairs+n);
			j=0;
			rep(i,0,n) {
				if(!(i>0&&pairs[i]==pairs[i-1])) j++;
				rank[pairs[i].id]=j;
			}
		}
	}
    /*
    void build(int n, int m) {
        // x - 第一关键字，y - 第二关键字
        int i, *x = t, *y = t2, *z;
        
        // 基数排序，按照s[i]排序后的名次存入sa。
        rep(i,0,m) c[i]=0;
        rep(i,0,n) c[x[i]=s[i]]++;
        rep(i,0,m) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
        
        for(int k=1;;k*=2) {
            // 取出第二关键字
            int p=0;
            rep(i,n-k,n) y[p++]=i;
            rep(i,0,n) if(sa[i]>=k) y[p++]=sa[i]-k;
            
            // 基数排序，按照s[i]排序后的名次存入sa。
            rep(i,0,m) c[i]=0;
            rep(i,0,n) c[x[y[i]]]++;
            rep(i,1,m) c[i]+=c[i-1];
            for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
            
            z=x;x=y;y=z;
            // 获取下次的第一关键字
            p=1;x[sa[0]]=0;
            rep(i,1,n)
                if(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])
                    x[sa[i]]=p-1; // 如果
                else x[sa[i]]=p++;
            if(p>=n)break;
            m=p;
        }
        rank=x;
    }*/
    
    void cal_height() {
        int i, j,x,y,k=0;
        rep(i,0,n) sa[rank[i]]=i;
        rep(i,0,n) {
            if(k) k--;
            j = sa[rank[i]-1];
            while(s[i+k]==s[j+k]) k++;
	        height[rank[i]]=k;
        }
    }
} sa;

int main() {
    char s[20];
    scanf("%s", s);
    int n = strlen(s), i;
    rep(i,0,n) s[i]-='a'-1;
    sa.init(s,n);
    sa.build();
    printf("\nSA  :"); rep(i,1,n+1) printf("%d ", sa.sa[i]);
    printf("\nRANK:"); rep(i,0,n) printf("%d ", sa.rank[i]);
    sa.cal_height();
    printf("\nHE  :"); for(int i=2;i<=n;i++) printf("%d ", sa.height[i]);
    return 0;
}
