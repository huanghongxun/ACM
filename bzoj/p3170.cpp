#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
  
#define ps system("pause")
#define message printf("*\n")
#define pb push_back
#define X first
#define Y second
#define PII pair<int,int>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
  
typedef long long ll;
  
using namespace std;
  
struct node{
    double x,y;
    int id;
}p[100010];
  
bool cmp1(node a,node b){
    return  a.x<b.x;
}
  
bool cmp2(node a,node b){
    return  a.y<b.y;
}
  
double sx=0,sy=0,ts;
double ans[100010];
int n;
  
int main(){
    scanf("%d",&n);
    rep(i,1,n){
        double xx,yy;
        scanf("%lf%lf",&xx,&yy);
        p[i].x=(xx+yy)/2;p[i].y=(xx-yy)/2;
        sx+=p[i].x;sy+=p[i].y;p[i].id=i;
    }
    sort(p+1,p+n+1,cmp1);ts=0;
    rep(i,1,n){
        ans[p[i].id]+=(i-1)*p[i].x-ts;
        ans[p[i].id]+=(sx-ts)-(n-i+1)*p[i].x;
        ts+=p[i].x;
    }
    sort(p+1,p+n+1,cmp2);ts=0;
    rep(i,1,n){
        ans[p[i].id]+=(i-1)*p[i].y-ts;
        ans[p[i].id]+=(sy-ts)-(n-i+1)*p[i].y;
        ts+=p[i].y;
    }
    double s=1e18;
    rep(i,1,n)  s=min(s,ans[i]);
    printf("%.0lf\n",s);
    return  0;
}