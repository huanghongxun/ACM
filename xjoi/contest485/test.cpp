#include<stdio.h>
#include<string.h>
#include<math.h>
int flag[100006];
int num[100006],total,now,n;
void solve(int index,int Mul,int K){
      int i,t;
   if(K==0){
    now+=n/Mul;
    return;
   }
   for(i=index;i<total-K+1;i++){
     Mul*=num[i];
     t=now;
     if(Mul<=n){
              solve(i+1,Mul,K-1);
     }
     if(t==now)//优化剪枝（1）
      return;
           Mul/=num[i];
   }
}
int Judge(int x){
 int t,i;
 t=sqrt(x*1.0);
 for(i=2;i<=t;i++)
  if(n%i==0)
   return 0;
 return 1;
}
int main(){
    int i,j,t,Count;
 memset(flag,0,sizeof(flag));
 for(i=2;i<=10000;i++){
  if(flag[i])
   continue;
  for(j=2;j*i<=10000;j++)
   flag[i*j]=1;
 }
 while(scanf("%d",&n)==1){
  Count=0;
  if(n<=10000){
   for(i=2;i<n;i++)
    if(!flag[i])
     Count++;
  }
  else{
   t=sqrt(1.0*n);
   /*num[total++]=2;
   num[total++]=3;
   num[total++]=5; */
   total=0;
   for(i=2;i<=t;i++)
    if(!flag[i])
     num[total++]=i;
   for(i=1;i<=total;i++){
    now=0;
    solve(0,1,i);
    if(now==0)//优化(2)
     break;
    if(i&1)
       Count+=now;
    else
       Count-=now;
   }
   Count-=total;
   Count=n-Count-1;
   if(Judge(n))
    Count--;
  }
  printf("%d\n",Count);
 }
 return 0;
}