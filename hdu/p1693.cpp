#include<iostream>
using namespace std;
int mat[100][100];
long long dp[12][12][1<<12];
int main()
{
    int zu;
    int g=1;
    scanf("%d",&zu);
    while(zu--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        int i,j,k;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&mat[i][j]);
            //memset(dp,0,sizeof(dp));
            dp[0][n][0]=1;
            for(i=1;i<=m;i++)
            {
                for(j=0;j<(1<<n);j++)
                    dp[i][0][j<<1]=dp[i-1][n][j];
                //把最右边的去掉 把所有的状态拉到下一行并进行合理的改变(注意最左边的是低位所代表的数) 
                //上一行最右边的边格一定不与轮廓线重合 下一行最左边的边格也一定不与轮廓线重合 
                //所以进行的是上一行所有状态(也就是轮廓线)向右的一次滑动
                    for(j=1;j<=n;j++)//枚举决策线的拐向
                    {
                        for(k=0;k<(1<<n<<1);k++)//枚举轮廓线
                        {
                            int p=1<<j;//第j个轮廓段(上)
                            int q=p>>1;//第j-1个轮廓段(左)
                            bool x=k&p;//左轮廓是否与通路相交
                            bool y=k&q;//上轮廓是否与通路相交
                            
                            //判断轮廓线在[i,j]为拐向时的分布 每个格子有1<<n<<1种 多阶段决策
                            
                            if(mat[i][j])//如果该单元可以通行
                            {
                                dp[i][j][k]=dp[i][j-1][k^p^q];//必然有一个通路连接上一个格的通路
                                if(x!=y)
                                    dp[i][j][k]+=dp[i][j-1][k];//有一处新覆盖则有另外的一种情况
                            }
                            else//否则为障碍格子
                            {
                                if(x==0&&y==0)//通路与轮廓线不相交
                                    dp[i][j][k]=dp[i][j-1][k];//直接转移
                                else
                                    dp[i][j][k]=0;//通路与轮廓线相交的方案一定为0
                            }
                        }
                    }
            }
            printf("Case %d: There are %I64d ways to eat the trees.\n",g++,dp[m][n][0]);
    }
    return 0;
}