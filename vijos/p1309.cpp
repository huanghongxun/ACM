#include <stdio.h>
#include <string.h>
int main()
{
	int m,i,sum=1,len;
	long long t=0,n=0;
	char a[1000];
	gets(a);
	scanf("%d",&m);
	len=strlen(a);
	if(len>=10) {
		len=len-10;
		for(i=len;i<len+10;i++) {
			n=n*10+(a[i]-'0');
		}	
	} else if(len>=2&&len<10) {
		for(i=0;i<len;i++) {
			n=n*10+(a[i]-'0');
		}
	}
	else
	n=a[0]-'0';
	t=n*3+1;
	for(i=1;i<=m;i++) sum*=2;
	printf("%d",t%sum);
	return 0;
}