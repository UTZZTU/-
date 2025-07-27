#include <stdio.h>
#include <string.h>
int main ()
{
	char s1[100],s2[100],s3[100];
	int l1,l2,q1,q2;
	gets(s1);
	gets(s2);
	l1=strlen(s1);
	l2=strlen(s2);
	q1=l1/2;
	q2=l2/2;
	s3[0]=s1[0];
	s3[1]=s1[q1];
	s3[2]=s1[l1-1];
	s3[3]=s2[0];
	s3[4]=s2[q2];
	s3[5]=s2[l2-1];
	s3[6]='\0';
	printf("%s",s3);
	return 0;
}