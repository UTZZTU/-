#include <stdio.h>
#include <string.h>
int main ()
{
	int t,l,s1,s2,s3,s4,q1,q2,q3,q4;
	char c[50],s;
	scanf("%d",&t);
	s=getchar();
	for(int i=1;i<=t;i++)
	{
		s1=0;
		s2=0;
		s3=0;
		s4=0;
		q1=0;
		q2=0;
		q3=0;
		q4=0;
		gets(c);
		l=strlen(c);
		if(l>=8&&l<=16)
		{
			for(int a=0;c[a]!='\0';a++)
			{
				if(c[a]>='A'&&c[a]<='Z')
				s1++;
				else if(c[a]>='a'&&c[a]<='z')
				s2++;
				else if(c[a]>='0'&&c[a]<='9')
				s3++;
				else  s4++;
			}
			if(s1>0)
			q1=1;
			if(s2>0)
			q2=1;
			if(s3>0)
			q3=1;
			if(s4>0)
			q4=1;
			if((q1+q2+q3+q4)>=3)
			printf("YES");
			else  printf("NO");
		}
		else
		printf("NO");
		printf("\n");
	}
	return 0;
}
