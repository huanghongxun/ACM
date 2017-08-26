#include <iostream>
#include <set>
using namespace std;

set<int> randoms;

int main()
{
	int n, ra;
	cin>>n;
	while(n--) {
		cin>>ra;
		randoms.insert(ra);
	}
	cout<<randoms.size()<<endl;
	for(set<int>::iterator i=randoms.begin();
		i!=randoms.end();i++) {
		cout<<*i<<' ';
	}
	return 0;
}