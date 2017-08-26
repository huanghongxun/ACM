#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, money, summoney = 0;
	string str;
	string firstname, isgb, iswest;
	int endavg, classavg, paper, firstmoney = 0;
	cin>>n;
	while(n--)
	{
		cin>>str>>endavg>>classavg>>isgb>>iswest>>paper;
		money = 0;
		if(endavg > 80 && paper >= 1) money += 8000;
		if(endavg > 85 && classavg > 80) money += 4000;
		if(endavg > 90) money += 2000;
		if(endavg > 85 && iswest[0] == 'Y') money += 1000;
		if(classavg > 80 && isgb[0] == 'Y') money += 850;
		summoney += money;
		if(firstmoney<money)
		{
			firstmoney = money;
			firstname = str;
		}
	}
	cout<<firstname<<endl<<firstmoney<<endl<<summoney<<endl;
	return 0;
}