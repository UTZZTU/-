#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k;
string s;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		getchar();
		cin>>s;
		if(k==n-1)
		{
			puts("YES");
		}
		else
		{
			int cr[26]={0},res=0;
			for(int i=0;i<n;i++)
			{
				cr[s[i]-'a']++;
			}
			for(int i=0;i<26;i++)
			{
				if(cr[i]&1) res++;
			}
			if(k>=res||res-k==1)
			{
				puts("YES");
			}
			else
			puts("NO");
		}
	}
	return 0;
}