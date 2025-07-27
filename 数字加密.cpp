#include <stdio.h>
int main ()
{
	char s[10],w;
	int i;
	scanf("%s",s);
	w=s[0];
	s[0]=s[3];
	s[3]=w;
	w=s[1];
	s[1]=s[2];
	s[2]=w;
	for(i=0;i<4;i++)
	{
		s[i]=(9-(s[i]-'0')+'0');
	}
	printf("%s",s);
	return 0;
}