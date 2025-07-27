#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s[N];
int ne[N],n;
int main ()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&s[i]!=s[j+1]) j=ne[j];
		if(s[i]==s[j+1]) j++;
		ne[i]=j;
	}
	cout<<n-ne[n];
	return 0;
}