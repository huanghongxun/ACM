#include <cstdio>
#include <algorithm>
#define N 50005
#define M 50005
using namespace std;

double number[N];
int cnt[N];
int n, i, mi, ma = -2147483647;
double tot = 0, mid;

int main() {

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%lf", &number[i]);
		tot += number[i];
	}
	sort(number, number + n);

	for(i = 0; i < n; i++) {
		if(i > 0 && number[i] == number[i - 1]) {
			cnt[i] = cnt[i - 1] + 1;
			if(ma < cnt[i])
				ma = cnt[i];
		}
		else
			cnt[i] = 1;
	}

	mi = n / 2;
	if(n % 2 == 0) {
		mid = (number[mi] + number[mi + 1]) / 2;
	} else {
		mid = number[mi + 1];
	}

	printf("%.2lf\n", tot/n);
	printf("%.2lf\n", mid);

	for(i = 0; i < n; i++) {
		if(cnt[i] == ma) {
			printf("%.0lf ", number[i]);
		}
	}


	return 0;
}