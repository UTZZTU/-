#include <stdio.h>
#include <string.h>
int main ()
{
	char w[100000],s[100000],q[]="2013";
	while(gets(w)!=NULL)
	{
		if(strcmp(w,q)==0)
		{
				break;
		}
		else
		{
			int i,n,len,k;
			n=0;
			for(i=0;w[i]!='\0';i++)
			{
				if(w[i]!=' ')
				{
					s[n]=w[i];
					n++;
				}
			}
			s[n]='\0';
			len=strlen(s);
			k=0;
			for(i=0;i<len/2;i++)
			{
				if(s[i]==s[len-1-i])
				k++;
				else
				break;
			}
			if(k==len/2)
			printf("YES\n");
			else
			printf("NO\n");
		}
	}
	return 0;
}
