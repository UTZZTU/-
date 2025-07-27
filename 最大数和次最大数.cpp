#include <iostream>
#include <algorithm>
using namespace std;
int a[200];
int main ()
{
	char s[100010];
	while(gets(s)!=NULL)
	{
		int i,pd2=0,shu=0,sum=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]==' ')
			{
				a[sum++]=shu;
				shu=0;
			}
			else if(s[i]=='-')
			{
				pd2=1;
			}
			else if(s[i]>='0'&&s[i]<='9')
			{
				if(pd2==1)
				{
					shu=shu*10+s[i]-'0';
					shu*=-1;
					pd2=0;
				}
				else
				shu=shu*10+s[i]-'0';
			}
		}
		a[sum++]=shu;
		sort(a,a+sum);
	    printf("%d %d\n",a[sum-1],a[sum-2]);
	}
	return 0;
}