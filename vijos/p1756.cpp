#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str, reversedstr;

int main()
{
	cin>>str;
	reversedstr = "";
	bool has = false;
	if(str[0]=='-') {
		has = true;
		str = str.substr(1,str.length());
	}
	while(str.length()>0&&str[0]=='0')
		str = str.substr(1,str.length());
	for(int i=0;i<str.length()/2;i++)
	{
		swap(str[i],str[str.length()-i-1]);
	}
	while(str.length()>0&&str[0]=='0')
		str = str.substr(1,str.length());
	if(str.length()==0) str='0';
	if(has&&str[0]!='0') cout<<'-';
	cout<<str<<endl;
	return 0;
}