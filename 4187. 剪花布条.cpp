#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char s[N],p[N];
int ne[N];
int main ()
{
	while(scanf("%s",s+1))
	{
		int res=0;
		memset(ne,0,sizeof ne);
		if(s[1]=='#'&&s[2]=='\0') break;
		scanf("%s",p+1);
		int n=strlen(s+1),m=strlen(p+1);
		for(int i=2,j=0;i<=m;i++)
		{
			while(j&&p[i]!=p[j+1]) j=ne[j];
			if(p[i]==p[j+1]) j++;
			ne[i]=j;
		}
		
		for(int i=1,j=0;i<=n;i++)
		{
			while(j&&s[i]!=p[j+1]) j=ne[j];
			if(s[i]==p[j+1]) j++;
			if(j==m)
			{
				res++;
				j=0;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}