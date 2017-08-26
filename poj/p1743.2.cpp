#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define maxx 20010
int wsf[maxx],wa[maxx],wv[maxx],wb[maxx],s[maxx];
int height[maxx],rank[maxx],sa[maxx];
struct SuffixArray {
    int *s;
    // suffix array, 2 temp array, bucket sort auxiliary array, string length.
    int t1[MAXN], t2[MAXN], c[MAXN], *rank, sa[MAXN], height[MAXN], n;
    int wa[MAXN], wb[MAXN], wm[MAXN];
    
    struct Rank {
    	int x, y, id;
    	friend bool operator < (const Rank &a, const Rank &b) {
    		return a.x == b.x ? a.y < b.y : a.x < b.x;
    	}
    	friend bool operator == (const Rank &a, const Rank &b) {
    		return a.x == b.x && a.y == b.y;
    	}
    	friend bool operator != (const Rank &a, const Rank &b) {
    		return a.x != b.x || a.y != b.y;
    	}
    } pairs[MAXN];

    void init(int *s, int n) {
    	this->s = s;
    	s[n] = 0;
    	this->n = n;
    }
    /*
	void build() {
		int i, j, k;
		rep(i,0,n) rank[i]=s[i];
		for(k=1;k<=n*2;k*=2) {
			rep(i,0,n) {
				pairs[i].x=rank[i];
				if(i<n-k) pairs[i].y=rank[i+k];
				else pairs[i].y=-1;
				pairs[i].id=i;
			}
			sort(pairs, pairs+n);
			j=1;
			rep(i,0,n) {
				if(i>0&&pairs[i]!=pairs[i-1]) j++;
				rank[pairs[i].id]=j;
			}
		}
        rep(i,0,n) sa[rank[i]]=i;
		//for(int i=1;i<=n;i++) printf("%d ", sa[i]);
		//printf("\n");
		//for(int i=0;i<n;i++) printf("%d ", rank[i]);
		//printf("\n");
	}*/
	
	bool cmp(int *r,int a,int b,int l){
		return r[a] == r[b] && r[a+l] == r[b+l];
	}

	void build(int n,int m){
		int *x=wa,*y=wb,*t;
		for(int i=0;i<m;++i)wm[i]=0;
		for(int i=0;i<n;++i)wm[x[i]=s[i]]++;
		for(int i=1;i<m;++i)wm[i]+=wm[i-1];
		for(int i=n-1;i>=0;--i)sa[--wm[x[i]]]=i;
		for(int i=0,j=1,p=0;p<n;j=j*2,m=p){
			for(p=0,i=n-j;i<n;++i)y[p++]=i;
			for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;
			for(i=0;i<m;++i)wm[i]=0;
			for(i=0;i<n;++i)wm[x[y[i]]]++;
			for(i=1;i<m;++i)wm[i]+=wm[i-1];
			for(i=n-1;i>=0;--i)sa[--wm[x[y[i]]]]=y[i];
			for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0;i<n;++i){
				x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
			}
		}
		rank=x;
	}
    
    void cal_height() {
        int i, j,x,y,k=0;
        rep(i,0,n) {
            if(k) k--;
            j = sa[rank[i]-1];
            while(s[i+k]==s[j+k]) k++;
	        height[rank[i]]=k;
        }
		//for(int i=2;i<=n;i++) printf("%d ", height[i]);
		//printf("\n");
    }
} sa;
int deal(int n,int p)
{
    int minx=sa[0],maxx1=sa[0];
    for(int i=0;i<=n;i++)
    {
        if(height[i]>=p)
        {
            if(minx>sa[i])
            minx=sa[i];
            if(maxx1<sa[i])
            maxx1=sa[i];
            if(maxx1-minx>p)
            return 1;
        }
        else
        minx=maxx1=sa[i];
    }
    return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)>0&&n)
    {
        for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
        for(int i=0;i<n-1;i++)
        {
            s[i]=s[i+1]-s[i]+90;              //这里要注意，题目相当于把数据进行平移了，但是用后一个减去前一个再加上一个最大值的做法，虽然可以将之回复，但是第一个值可能会被改变，所以在最后需要把第一个值加上.....
            //printf("%d ",s[i]);
        }
        n--;
        s[n]=0;
        getsa(s,sa,n+1,200);
        getheight(s,n);
        int left=0,right=n,mid,coun=0;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(deal(n,mid))
            {
                if(coun<mid)
                coun=mid;
                left=mid+1;
            }
            else  right=mid-1;
        }
        if(coun<4) coun=0;
        else
        coun++;                     //这里+1，是为了将前面被改变了的第一个值加上.....
        printf("%d\n",coun);
    }
    return 0;
}
