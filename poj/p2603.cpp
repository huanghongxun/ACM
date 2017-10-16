#include<cstdio>
#include<cstring>
#include<iostream>

int a[10001];
int const maxSize=10000;
int prime[maxSize];     //保存筛得的素数
int primeSize;          //保存的素数的个数
//若mark[x]为true,则表示该数x已被标记成非素数
bool isPrime[maxSize+1];
void init()//素数筛法
{
    //#include <cstring>
    //初始化，所有数字均没被标记
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    primeSize = 0; //得到的素数个数为0
    //依次遍历2到maxSize所有数字
    for (int i=2; i<= maxSize; i++)
    {
        //若该数字已经被标记,则跳过
        if(!isPrime[i]) continue;
        //否则,又新得到一个新素数
        prime[primeSize++]=i;
        //并将该数的所有倍数均标记成非素数
        for (int j=i*i; j<=maxSize &&j>=0; j+=i)
        {
            isPrime[j]=false;
        }
    }
}
void find(int n)
{
    int i=0;
    while (n!=1&&n>=prime[i])
    {

        while (n%prime[i]==0)
        {
            n=n/prime[i];
            a[prime[i]]++;
        }
        i++;
    }
}
int main()
{
    init();
    int i,l,n;
    for (i=1; i<=10; i++)
    {
        scanf("%d",&n);
        find(n);
    }
//    for (i=0;i<=15;i++)
//      printf("%d\n",a[prime[i]]);

    l=1;
    for (i=1; i<=10000; i++)
    {
        l=l*(a[i]+1);
//        cout<<l<<endl;
    }
    printf("%d\n",l%10);
    return 0;
}
