
#include <stdio.h>
long m,i,x,y,z,t;
long s[50005],w[50005];
struct {
	long v,w,ne;
} e[50005];
void addedge(long x,long y,long z)
{
	t++;
	e[t].v=y;
	e[t].w=z;
	e[t].ne=w[x];
	w[x]=t;
}
int main() {
	scanf("%d", &m);
	for(int i=1;i<=50000;i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		addedge(x-1,y,z);
	}
	s[-1]=0;
	for(i=-1;i<=50000;i++)
	begin
		if(i>-1&&s[i-1]>s[i]) s[i]=s[i-1];
		for(x=w[i];x;x=e[x].ne) {
			y=s[i]+e[x].w;
			z=e[x].v;
			if(y>s[z]) {
				s[z]=y;
				while(s[z]-1>s[z-1]) {
					s[z-1]=s[z]-1;z--;
				}
			}
		}
	}
	printf("%d", s[50000]));
	return 0;
}