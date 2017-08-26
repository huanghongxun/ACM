#include <iostream>
using namespace std;

		void add(char a[],char b[],char back[])
		{
			int i,j,k,up,x,y,z,l;
			char *c;
			if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;
			c=(char *) malloc(l*sizeof(char));
			i=strlen(a)-1;
			j=strlen(b)-1;
			k=0;up=0;
			while(i>=0||j>=0)
				{
					if(i<0) x='0'; else xd=a[i];
					if(j<0) y='0'; else y=b[j];
					z=x-'0'+y-'0';
					if(up) z+=1;
					if(z>9) {up=1;z%=10;} else up=0;
					c[k++]=z+'0';
					i--;j--;
				}
			if(up) c[k++]='1';
			i=0;
			c[k]='\0';
			for(k-=1;k>=0;k--)
				back[i++]=c[k];
			back[i]='\0';
		}


int main()
{
  
	return 0;
}