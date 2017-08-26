#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;

int h[N], dir[N], f[N][2];

int look_forward(int now, int type) {
	for(int i = now - 1; i >= 0; i--) {
		if(h[i] == h[now]) continue;
		if(dir[i] == type && (h[i] > h[now]) == type)
			return i;
	}
	return 0;
}

int main()
{
	int i, n, bigger, smaller;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &h[i]);
	dir[0] = 0;
	f[0][0] = f[0][1] = 1;
	for(i = 1; i < n; i++) {
		//compute how many flower is bigger than flower i.
		bigger = look_forward(i, 1);
		//otherwise
		smaller = look_forward(i, 0);

		f[i][0] = f[bigger][1] + 1;
		f[i][1] = f[smaller][0] + 1;
		//f[i] = max(f[bigger], f[smaller]) + 1;
		dir[i] = h[i] > h[f[bigger][1] > f[smaller][0] ? bigger : smaller];
	}
	printf("%d", max(f[n-1][1],f[n-1][0]));
	//printf("%d", f[n-1]);
	return 0;
}