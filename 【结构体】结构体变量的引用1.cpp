#include <stdio.h>
# define n 3
struct  student
{
	int number;
	char name[100];
	int age;
	int num1,num2,num3;
};
int main ()
{
	struct student s[n];
	int i,c[3];
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d",&s[i].number,s[i].name,&s[i].age);
		scanf("%d%d%d",&s[i].num1,&s[i].num2,&s[i].num3);
		c[i]=(s[i].num1+s[i].num2+s[i].num3);
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d",s[i].number,c[i]);
		if(i!=n-1)
		printf("\n");
	}
	return 0;
}
