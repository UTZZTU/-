#include <stdio.h>
#include <string.h>
int n;
char s[100][100],str[100];
int min(int x,int y)
{
	if(x>y)
	return y;
	else
	return x;
}
bool judge(char a[],char b[])
{
	int x=strlen(a),y=strlen(b),minn;
	minn=min(x,y);
	for(int i=0;i<minn;i++)
	{
		if(a[i]<b[i])
		return true;
	}
	if(minn==y)
	return true;
	return false;
}
int main ()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	scanf("%s",s[i]);
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(judge(s[i],s[j]))
			{
				strcpy(str,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],str);
			}
		}
	}
	for(int i=1;i<=n;i++)
	printf("%s",s[i]);
	return 0;
}
