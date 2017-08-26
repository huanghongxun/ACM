#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 10
#define N 600
#define NN 100
typedef int big[600];
//set bignum to 0
void base_big(void *a)
{
    memset(a,0,sizeof(big));
}
/*big num*simple num,
b<500
*/
void smlt(int *r,int b,int *a,int n)
{
    int static i;
    for (i = 0;i < n-1;i++) {
        *(r+i) += *(a+i)*b;
        *(r+i+1) += *(r+i)/M;
        *(r+i) %= M;
    }
    if (i < n) *(r+i) = (*(a+i)*b+*(r+i))%M;
}
void print(big *a,int n)
{
    int i,r,l;
    for (i = N-1;i > 0;i--) if ((*a)[i]) break;
    r=i;
    if ((r==0)&&((*a)[r]==0)) {
        printf("0");
        return;
    }
    for (i = 0;i <= r;i++) if ((*a)[i]) break;
    l=i;
    if ((r==2*n)&&(r==l)) {
        printf("1");
        return;
    }
    printf("0.");
    for (i=2*n-1;i>=l;i--) printf("%d",(*a)[i]); //if M=100 %d->%.02d
}
int main()
{
    big a,b;
    int *rslt,*mltor,*tmp;
    int n,i,j;
    char key[NN+1];
    int p[4];
    scanf("%d",&n); scanf("%s",key);
    rslt=a; mltor=b;
    base_big(rslt); //set result=0 to prepare calculate
    base_big(mltor); *mltor=1; //set multiplicator=1 to prepare
    for (i=0;i<n;i++) {
        for (j=0;j<4;j++)
            scanf("%d%%",p+j);
        smlt(rslt,p[key[i]-'A'],mltor,210);
        tmp=mltor; mltor=rslt; rslt=tmp;
        base_big(rslt);
    }
    print((big *)mltor,n);
    return 0;
}