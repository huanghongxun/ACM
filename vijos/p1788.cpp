#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100000
#define M 100000
using namespace std;

int number[N];
int i, j, n, k;

int main() {

	cin>>n>>k;
	for(i = 0; i < n; i++)
		cin>>number[i];
	sort(number, number + n);

	cout<<number[n-k];

	return 0;
}