#include <stdio.h>
struct student
{
	int number;
	char name[100];
	int age;
	int num;
};
int main ()
{
	struct student s;
	while(scanf("%d%s%d%d",&s.number,s.name,&s.age,&s.num)!=EOF)
	{
		printf("%d\n",s.number);
		printf("%s\n",s.name);
		printf("%d\n",s.age);
		printf("%d\n",s.num);
	}
	return 0;
}
