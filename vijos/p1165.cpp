#include <iostream>
#include <algorithm>
using namespace std;

#define N 20005

struct Edge
{
	long long a, b;
} arr[N];

bool operator < (const Edge &a, const Edge &b) {
	return a.a < b.a;
}

int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) cin>>arr[i].a>>arr[i].b;
	sort(arr, arr+n);
	for(int i = 0; i < n - 1; i++) {
		if(arr[i].b > arr[i + 1].a)
			arr[i].b = arr[i + 1].a;
		if(arr[i].b > arr[i + 1].b)
			arr[i].b = arr[i].a;
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += arr[i].b - arr[i].a;
	}
	cout<<ans;

	return 0;
}