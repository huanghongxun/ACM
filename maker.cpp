#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

int random() {
	//static int c = time(0)%200000000;
	//return abs(c += (c << 2) + 1);
	return rand();
}

struct Edge {
	int a, b, w;
} e[2000000], k[30000];
int ec = 0;
int p[2000000];

bool operator < (const Edge &a, const Edge &b) {
	return a.w < b.w;
}

int find(int i) {
	return i == p[i] ? i : p[i] = find(p[i]);
}

int main() {
	srand(time(0));
	int n = 30000;//random()%30000+1;
	printf("%d\n", n);
begin:
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		int nei = n/2;
		while(nei--) {
			e[ec].a = i;
			e[ec].b = random()%n+1;
			ec++;
		}
	}
	
	random_shuffle(e, e+ec);
	for(int i = 0; i < ec; i++) {
		int fa = find(e[i].a), fb = find(e[i].b);
		if(fa != fb) {
			k[++tot]=e[i];
			p[fa]=fb;
		}
		if(tot == n-1) break;
	}
	if(tot != n-1) goto begin;
	for (int i=1;i<n;i++) printf("%d %d\n", k[i].a, k[i].b);
	for(int i = 1; i <= n; i++) printf("%d ", random()%30000);
	printf("\n");
	
	tot = 200000;//random()%200000+1;
	printf("%d\n", tot);
	while(tot--) {
		int x = random()%3;
		if(x==2) {
			printf("QSUM %d %d\n", random()%n+1, random()%n+1);
		} else if (x==1) {
			printf("QMAX %d %d\n", random()%n+1, random()%n+1);
		} else {
			printf("CHANGE %d %d\n", random()%n+1, random()%30000);
		}
	}
	
	return 0;
}
