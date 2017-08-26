#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string str, line;
char ch;
long long w11, l11, w21[1000000], l21[1000000];
long n = 1;

int main() {
	while(cin>>ch) {
		if(ch!='W'&&ch!='L'&&ch!='E') continue;
		switch(ch) {
			case 'W':
				w11++, w21[n]++;
				break;
			case 'L':
				l11++, l21[n]++;
				break;
			case 'E':
				goto out;
				break;
		}
		if((w11>=11||l11>=11)&&fabs(w11-l11)>1) {
			cout<<w11<<':'<<l11<<endl;
			w11 = l11 = 0;
		}
		if((w21[n]>=21||l21[n]>=21)&&fabs(w21[n]-l21[n])>1) {
			n++;
		}
	}
out:
	cout<<w11<<':'<<l11<<endl<<endl;
	for(long i=1;i<=n;i++) {
		cout<<w21[i]<<':'<<l21[i]<<endl;
	}

	return 0;
}