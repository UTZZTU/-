#include <stdio.h>
char c[1000000],b[1000000];
int main ()
{
	int n,k,m,i=0,a,pm=0;
	char s;
	scanf("%d %d %d",&n,&k,&m);
	getchar();
	gets(c);
	while(pm<m)
	{
		i=i+k;
	if(i>=n)
	i=i%n;
	for(a=i+1;a<n;a++)
	{
		b[a]=c[a];
	}
	b[a]='\0';
	if(c[i]=='Z')
	s='A';
	else
	s=c[i]+1;
	c[i+1]=s;
	n++;
	pm++;
	for(a=i+2;a<n;a++)
	{
		c[a]=b[a-1];
	}
	i=i+1;
	}
	printf("%c",c[i]);	
	return 0;
}
