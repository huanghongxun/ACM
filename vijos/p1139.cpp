#include <stdio.h>
#define C 502
#define L 102

struct room {
	int p;
	int num;
	int c; 
};
room r[L][C];

int main()
{
	int n,m;
	int i,j,k,min,tmp[5005];
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&r[i][j].p);
	for (i=1;i<=m;i++) {
		r[i][0].p=r[i][C+1].p=2147483647; 
		for(j=1;j<=n;j++) {
			tmp[j] = r[i][j].p;
			if (r[i][j-1].p<r[i][j].p) {
				r[i][j].p += r[i][j-1].p;
				r[i][j].num = j-1;
			}
			else {
				r[i][j].p += r[i][j-1].p;
				r[i][j].num = j;
				r[i][j].c = 1;
			}
			for (k = j;r[i][k].p+tmp[k-1]<r[i][k-1].p && k>0;k--) {
				r[i][k-1].p=r[i][k].p + tmp[k-1];
				r[i][k-1].num=k;
				r[i][k-1].c = 0;
			}
		}
	}
	min = 2147483647;
	for (j=1;j<=n;j++) {
		if (min > r[m][j].p) {
			min = r[m][j].p;
			k = j;
		}
	}
	j = k;
	k = 0;
	while (m > 0) {
		tmp[k] = j;
		j = r[m][j].num;
		m -= r[m][tmp[k]].c;
		k++;
	}
	k--;
	while (k>=0) { 
		printf("%d\n",tmp[k]);
		k--;
	}
	return 0;
}