#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
char s[100010][100];
int main ()
{
	char w[100];
    int q=0,n,i,a[100010],pd=0,t=0,j;
    memset(a,0,sizeof(a));
    while(~scanf("%s",w))
    {
    	if(w[0]>='0'&&w[0]<='9')
    	break;
    	scanf("%d",&n);
    	pd=0;
        if(q==0)
        {
        	strcpy(s[q],w);
        	a[q]+=n;
        	q++;
		}
		else
		{
			for(i=0;i<q;i++)
			{
				if(strcmp(s[i],w)==0)
				{
					pd=1;
					a[i]+=n;
					break;
				}
			}
			if(pd==0)
			{
				strcpy(s[q],w);
				a[q]+=n;
				q++;
			}
		}
    }
    for(i=0;w[i]!='\0';i++)
    t=t*10+w[i]-'0';
    getchar();
    for(i=1;i<=t;i++)
    {
    	scanf("%s",w);
    	for(j=0;j<q;j++)
    	{
    		if(strcmp(w,s[j])==0)
    		{
    			printf("%d\n",a[j]);
    			break;
			}
		}
	}
	return 0;
}