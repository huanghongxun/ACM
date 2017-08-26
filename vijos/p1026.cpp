#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int INT;

INT e[10];
INT tree[2048][2];
INT rec[101][2];
bool hash[1025];


int main() {

	int n,m,l=0,r=1;
	e[0]=1;
	for (int i=1; i<=9; i++) e[i]=e[i-1]<<1;
	memset(rec,0,sizeof(rec));
	memset(hash,0,sizeof(hash));
	//preproccesor
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; i++)
	for (int j = 0; j < n; j++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 1) rec[i][0] += e[j];
		else if (tmp == -1) rec[i][1] += e[j];
	}
	//read
	tree[l][0]=(1<<n)-1;
	tree[l][1]=0;
	hash[tree[l][0]]=1;
	//root create
	while (l<=r)
	{
		for (int i=1; i<=m; i++)
		{
			tree[r][0] = tree[l][0] & ( ~rec[i][0]);
			tree[r][0] |= rec[i][1];
			if (!hash[tree[r][0]]) 
			{
				hash[tree[r][0]] = 1;
				tree[r][1] = tree[l][1] + 1;
				if (tree[r][0]==0)
				{
					printf("%d\n",tree[r][1]);
					goto end;
				}
			}
			else r--;
			r++;
		}
		l++;
	}
	puts("The patient will be dead.\n");
end:
	return 0;
}