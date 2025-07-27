#include <stdio.h>
struct book
{
	long long int number;
	char name[200],writer[200];
	char price[20];
};
int main ()
{
	struct book s[100];
	long long int n,i,x,w;
	while(scanf("%lld",&n)!=EOF)
	{
		w=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&s[i].number);
		getchar();
		gets(s[i].name);
		gets(s[i].writer);
		gets(s[i].price);
		}
		scanf("%lld",&x);
		for(i=0;i<n;i++)
		{
			if(s[i].number==x)
			{
				printf("%lld %s %s %s\n",s[i].number,s[i].name,s[i].writer,s[i].price);
				break;
			}
			else
			w++;
		}
		if(w==n)
		printf("No find!\n");
	}
	return 0;
}
