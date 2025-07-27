#include <stdio.h>
struct worker
{
	int number;
	char name[300];
	double money;
};
int main ()
{
	struct worker s[10];
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
    	for(i=0;i<n;i++)
    	{
    		scanf("%d%s%lf",&s[i].number,s[i].name,&s[i].money);
		}
		for(i=0;i<n;i++)
		{
			if(s[i].money>5000)
			printf("%d %s %.1f\n",s[i].number,s[i].name,s[i].money);
		}
	}
    return 0;
}
