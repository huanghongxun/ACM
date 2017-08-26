#include <cstdio>
typedef long long ll;
int n,ans=1,num=1;
int p[15]={1,2,3,5,7,11,13,17,19,23,29,31};
void dfs(int k,ll now,int cnt,int last) {
    if(k==12) {
        if(now>ans&&cnt>num||now<=ans&&cnt>=num){ans=now;num=cnt;}
        return;
    }
    int t=1;
    for(int i=0;i<=last;i++) {
        dfs(k+1,now*t,cnt*(i+1),i);
        t*=p[k];
        if(now*t>n)break;
    }
}
int main() {
    scanf("%d",&n);
    dfs(1,1,1,20);
    printf("%d",ans);
    return 0;
}