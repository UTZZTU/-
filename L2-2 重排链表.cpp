#include<stdio.h>
struct p
{
	int q,h;
}s[100005];
int main ()
{
	int ks,n,i,j,w,k;
	scanf("%d %d",&ks,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&ks,&w,&k);
		s[w].q=ks;
	}
	for(i=n,j=1;i>=j+1;i--,j++)
	{
		s[i].h=s[j].q;
		if(i-1!=j)
		s[j].h=s[i-1].q;
		printf("%05d %d %05d\n",s[i].q,i,s[i].h);
		if(i-1==j)
		{
			s[j].h=-1;
			printf("%05d %d %d\n",s[j].q,j,s[j].h);
		}
		else
		printf("%05d %d %05d\n",s[j].q,j,s[j].h);
	}
	return 0;
}