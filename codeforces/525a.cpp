#include <cstdio>
char s[200001];
int a[100001],n,ans;
int main() {
    scanf("%d%s",&n,s+1);
    for(int i=1;i<n;i++) {
        a[s[2*i-1]-'a']++;
        if(!a[s[2*i]-'A']) ans++;
        else a[s[2*i]-'A']--;
    }
    printf("%d",ans);
    return 0;
}