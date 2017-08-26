#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>t[5005];
int a[5005],d[5005][3];
int dp(int i,int j) //j=1表示i参加，j=2表示i不参加 
{
	if(d[i][j]) return d[i][j];
	if(j==1){
		d[i][j]=a[i];
		for(vector<int>::iterator it=t[i].begin();it!=t[i].end();++it)
		d[i][j]+=dp(*it,2);
	}
	if(j==2){
		for(vector<int>::iterator it=t[i].begin();it!=t[i].end();++it)
		d[i][j]+=max(dp(*it,1),dp(*it,2));
	}
	return d[i][j];
}
int main()
{
	ios::sync_with_stdio(false);
	int n,father;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		cin>>father;
		t[father].push_back(i);
	}
	cout<<max(dp(1,1),dp(1,2))<<endl;
	return 0;
}