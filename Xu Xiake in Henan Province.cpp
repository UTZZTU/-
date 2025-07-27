#include <stdio.h>
int main ()
{
	int n,a,b,c,d,s;
	scanf("%d",&n);
	while (n--)
	{
		s=0;
		scanf("%d %d %d %d",&a,&b,&c,&d);
	if(a==0)
	s++;
	if(b==0)
	s++;
	if(c==0)
	s++;
	if(d==0)
	s++;
	if(s==4)
	printf("Typically Otaku\n");
	else if(s==3)
	printf("Eye-opener\n");
	else if(s==2)
	printf("Young Traveller\n");
	else if(s==1)
	printf("Excellent Traveller\n");
	else if(s==0)
	printf("Contemporary Xu Xiake\n");
	}
	return 0;
}
