#include <stdio.h>
#define N 21
#define INF 0x7fffffff
typedef long ll;

ll f[N][N][N];

ll w(ll a, ll b, ll c) {
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) return w(20,20,20);
	else {
		if(f[a][b][c] != INF)
			return f[a][b][c];
		if(a<b&&b<c) {
			f[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
			return f[a][b][c];
		}
		else {
			f[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
			return f[a][b][c];
		}
	}
}

int main() {
	ll a, b, c;
	for(a = 0; a <= 20; a++)
		for(b = 0; b <= 20; b++)
			for(c = 0; c <= 20; c++)
				f[a][b][c] = INF;
	scanf("%ld%ld%ld", &a, &b, &c);
	while(a != -1 && b != -1 && c != -1) {
		printf("w(%ld, %ld, %ld) = %ld\n", a, b, c, w(a,b,c));
		scanf("%ld%ld%ld", &a, &b, &c);
	}
	return 0;
}

w(1, 1, 1) = 2;
w(1, 1, 1) = 2;