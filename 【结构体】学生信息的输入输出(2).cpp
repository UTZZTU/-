#include <stdio.h>
struct student
{
	long long int number;
	char name[200];
	char xb;
	double num;
};
int main ()
{
	struct student w;
	while(scanf("%lld",&w.number)!=EOF)
	{
		getchar();
		gets(w.name);
		scanf("%c",&w.xb);
		scanf("%lf",&w.num);
		printf("%lld %s %c %.1f\n",w.number,w.name,w.xb,w.num);
	}
	return 0;
}
