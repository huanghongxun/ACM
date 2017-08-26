#include <stdio.h>
int main(int argc, char* argv[]) {
	if(argc==2)
	{
		printf("%d", argv[1][0]);
	}
	else
	{
		printf("error input");
	}
	return 0;
}