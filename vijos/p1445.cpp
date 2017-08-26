#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100000
#define M 100000
using namespace std;

struct TaoTao
{
	int w, num;
};

int apple[N], size[N];
TaoTao taotao[M];
int i, j, n, m;

int taotao_cmp(const TaoTao &a, const TaoTao &b) {
	return a.w > b.w;
}

int cmp(const int &a, const int &b) {
	return a > b;
}

int main() {

	memset(size, 0, sizeof(size));

	cin>>n>>m;
	for(i = 0; i < n; i++)
		cin>>apple[i];
	for(i = 0; i < m; i++) {
		taotao[i].num = i;
		cin>>taotao[i].w;
	}
	sort(apple, apple + n, cmp);
	sort(taotao, taotao + m, taotao_cmp);

	for(i = 0; i < m; i++) {
		for(j = i; j < n; j += m) {
			size[taotao[i].num] += apple[j];
		}
	}

	for(i = 0; i < m; i++)
		cout<<size[i]<<' ';

	return 0;
}

//5 4 3 2 1
//3 2 1