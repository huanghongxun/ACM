#include <cstdio>
using namespace std;
int main() {
    int n,a[150010],b,c,q=0,s=0,num=0,i,j,max1,max2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    s=0;
    num++;
    while(q < n) {
        i = q;
        if(num & 1) {
            while(a[i] <= a[i + 1]) i++;
            max1=s+=a[i];
        } else {
            while(a[i] >= a[i + 1]) i++;
            max2=s-=a[i];
        }
        q = i;
        num++;
    }
    printf("%d\n", max1);
    return 0;
}