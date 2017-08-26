#include <cstdio>
#include <algorithm>
int main() {
    static long long a[100005];
    int n, i; long long x, ans;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%I64d", a+i);
    std::sort(a+1,a+n+1);
    for(i=n-1;i>=1;i--)
        if(a[i+1]-a[i]<2) {
            if(x)ans+=x*a[i],x=0;
            else x=a[i];
            i--;
        }
    printf("%I64d",ans);
    return 0;
}