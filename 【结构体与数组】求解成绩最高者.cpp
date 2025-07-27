#include <stdio.h>
#define n 8
struct student
{
	int number;
	char name[100];
	int num;
};
int main ()
{
	struct student s[n];
	int i,max=0,j;
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d",&s[i].number,s[i].name,&s[i].num);
		if(s[i].num>max)
		{
			max=s[i].num;
			j=i;
		}
	}
	printf("%d %s %d",s[j].number,s[j].name,s[j].num);
	return 0;
}
