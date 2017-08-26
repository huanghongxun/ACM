#include <iostream>
#include <string>
using namespace std;
string player[55];
int main() {
	int o, n, m;
	cin>>o>>n>>m;
	for(int i=1;i<o;i++) cin>>player[i];
	cin>>player[0];
	if(!n||!m) cout<<player[1]<<" can win!";
	if(n*m%4!=0) goto noanswer;
	if(n*m%8!=0) goto noanswer;
	if(n==1||m==1) goto noanswer;
	cout<<player[(n*m/4)%o]<<" can win!";
	goto end;
noanswer:
	cout<<"Nobody can win!";
end:
	return 0;
}