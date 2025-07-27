#include <stdio.h>
struct worker
{
	int number;
	char name[200];
	int year;
};
int main ()
{
	struct worker s[100];
	int n,i,a=0,b=0,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d",&s[i].number,s[i].name,&s[i].year);
		if(s[i].year<=10)
		a++;
		else if(s[i].year>10&&s[i].year<=20)
		b++;
		else
		c++;
	}
	printf("%d,%d,%d",a,b,c);
	return 0;
}
