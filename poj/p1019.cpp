#include <iostream>
#include <cmath>
using namespace std;
const int size=31269;

unsigned a[size], s[size];

int main() {
	a[1]=s[1]=1;
	for(int i=2;i<size;i++) {
		a[i]=a[i-1]+(int)log10((double)i)+1;
		s[i]=s[i-1]+a[i];
	}
	int test, n, i;
	cin>>test;
	while(test--) {
		cin>>n;
		for(i=1;s[i]<n;i++);
		int pos=n-s[i-1], len=0;
		for(i=1;len<pos;i++)
			len+=(int)log10((double)i)+1;

		cout<<(i-1)/(int)pow((double)10,len-pos)%10<<endl;
	}
	return 0;
}