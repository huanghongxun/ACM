#include <iostream>
#include <cstdlib>
using namespace std;

char s, t, w;
char num[30];

void add(char *num) {
	int k = w;
	num[k]++;
	while(num[k]>t) {
		if(k<=0) exit(0);
		num[k]='a';
		k--;
	cout<<num+1<<endl;
	}
	cout<<num+1<<endl;
}

int main()
{
	int s, t;
	cin>>s>>t>>w;
	s = s+'a'-1;
	t = t+'a'-1;
	cin>>num+1;
	add(num);
	add(num);
	add(num);
	add(num);
	add(num);

	return 0;
}