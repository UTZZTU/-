#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
char s[N];
int ne[N],n;
int main ()
{
	int T = 1;
	while(scanf("%d",&n),n)
	{
		scanf("%s",s+1);
		for(int i=2,j=0;i<=n;i++)
		{
			while(j&&s[i]!=s[j+1]) j=ne[j];
			if (s[i]==s[j+1]) j++;
			ne[i]=j;
		}
		
		printf("Test case #%d\n", T++);
		for(int i=1;i<=n;i++)
		{
			int t=i-ne[i];
			if(i%t==0&&i/t>1)
			printf("%d %d\n",i,i/t);
		}
		printf("\n");
	}
	return 0;
}