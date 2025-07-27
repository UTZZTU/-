#include <iostream>
using namespace std;
int main ()
{
	int a,b,c,d,q,h;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	q=max(a,c);
	h=min(b,d);
	if(h-q<0)
	printf("0");
	else
	printf("%d",h-q);
	return 0;
}