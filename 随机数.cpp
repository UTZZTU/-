#include <iostream>
using namespace std;
int main ()
{
	int x,y,i;
	scanf("%d%d",&x,&y);
	for(i=max(x,y);i<=6;i++)
	printf("%d ",i);
	return 0;
}