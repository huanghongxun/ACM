#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#define MAXN 50
#define MAXM 1024

using namespace std;

int cmp(const void *a , const void *b)
{
	return ( *(int *)a - *(int *)b) ;
}

int pack[MAXN + 1] , rail[MAXM + 1] , N , M , total = 0 , sumr[MAXM + 1] , space , Mid , bag[MAXN + 1];

bool Dfsid(int deep , int pos)
{
	if (deep <= 0) return true ;
	if (space > total - sumr[Mid]) return false ;
	for (int i = pos ; i <= N ; i++)
		if (bag[i] >= rail[deep]) {
			bag[i] -= rail[deep] ;
			if (bag[i] < rail[1])
			space += bag[i] ;
			if (rail[deep] == rail[deep - 1])
			{
				if (Dfsid(deep - 1 , i)) return true ;
			}
			else
				if (Dfsid(deep - 1 , 1)) return true ;
			if (bag[i] < rail[1])
				space -= bag[i];
			bag[i] += rail[deep] ;
		}
	return false ;
}

int main()
{
	//freopen("tmp.in","r",stdin);
	scanf("%d",&N);
	for (int i = 1 ; i <= N ; i++)
	{
		scanf("%d",&pack[i]);
		total += pack[i] ;
	}
	scanf("%d",&M);
	for (int i = 1 ; i <= M ; i++)
		scanf("%d",&rail[i]);
	qsort(pack , N + 1 , sizeof(long) , cmp) ;
	qsort(rail , M + 1 , sizeof(long) , cmp) ;
	sumr[0] = 0 ;
	for (int i = 1 ; i <= M ; i++) sumr[i] = sumr[i - 1] + rail[i] ;
	while (sumr[M] > total) M--;
	int Left = 1 , Right = M ;
	Mid = ((Left + Right) >> 1 ) ;
	while (Left <= Right)
	{
		for (int i = 1 ; i <= N ; i++) bag[i] = pack[i] ;
		space = 0 ;
		if (Dfsid(Mid , 1))
		{
			Left = Mid + 1 ;
			Mid = ((Left + Right) >> 1);
		}
		else
		{
			Right = Mid - 1 ;
			Mid = ((Left + Right) >> 1);
		}
	}
	printf("%d\n",Mid);
	return 0 ;
}