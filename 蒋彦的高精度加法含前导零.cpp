#include <stdio.h>
#include <string.h> 
#define N 205
void reverse(char s[])
{
	char t;
	int i,j,len=strlen(s);
	j=len-1;
	i=0;
	while(i<j)
	{
		t=s[i];
		s[i]=s[j];
		s[j]=t;
		i++;
		j--;
	}
}
void revert(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		s[i]-=48;
	}
}
int main ()
{
	char a[N],b[N],c[N];
	int i,lena,lenb,carry,maxlen;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%s",a);
	scanf("%s",b);
	lena=strlen(a);
	lenb=strlen(b);
	reverse(a);
	reverse(b);
	revert(a);
	revert(b);
	maxlen=lena>lenb?lena:lenb;
	carry=0;
	memset(c,0,sizeof(c));
	for(i=0;i<=maxlen;i++)
	{
		c[i]=(a[i]+b[i]+carry)%10;
		carry=(a[i]+b[i]+carry)/10;
	}
	for(i=maxlen;i>=1&&c[i]==0;i--)
	;
	for(;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	printf("\n");
	return 0;
}
