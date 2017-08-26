#include <cstdio>
int map[35][35];
int ans[35];
int Gauss() { //高斯消元法
	int i, j, k, r;
	for(k=0; k<30; k++) {
		i = k;
		while(i<30 && map[i][k]==0)	i++;
		if(i > k)
			for(r=0; r<=30; r++)
				swap(map[i][r], map[k][r]);
		for(i=0; i<30; i++) {
			if(i != k && map[i][k]) {
				for(j=0; j<=30; j++)
					map[i][j] ^= map[k][j];	 //高斯消元的^异或运算
			}
		}
	}
	for(i=0; i<30; i++)	 //求出结果
		if(map[i][30]) {
			for(j=0; j<30 && !map[i][j]; j++);
			if(j == 30) return 0;
			else ans[j] = map[i][30];
		}
	return 1;
}
int main()
{
	int i,j,k,kn,km,kx,ky,t;
	scanf("%d",&t);
	for(k=1; k<=t; k++) {
		memset(map, 0, sizeof(map));
		for(i=0; i<30; i++) {
			scanf("%d", &map[i][30]);
			ans[i] = 0;
		}
		for(i=0; i<30; i++) { //构造30个方程
			kn = i / 6;
			km = i % 6;
			for(j=0; j<30; j++) {
				kx = j / 6; 
				ky = j % 6;
				if(abs(kx - kn) + abs(ky - km) <= 1) map[i][j] = 1;
				else map[i][j] = 0;
			}
		}
		Gauss();
		printf("PUZZLE #%d/n",k);
		for(i=0; i<30; i++) {
			printf("%d", ans[i]);
			if((i+1) % 6 == 0) printf("/n");
			else printf(" ");
		}
	}
	return 0;
}