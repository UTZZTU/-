#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010],f[200010],pos;
bool judge(int x,int l,int r)
{
	int flag=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]>=x)
		{
			;
		}
		else
		{
			f[a[i]]--;
			if(f[a[i]]==0) return false;
		}
	}
	return true;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			f[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]<n) f[a[i]]++;
		}
		for(int i=0;i<=n;i++)
		{
			if(!f[i])
			{
				pos=i;
				break;
			}
		}
		if(pos==n)
		{
			puts("No");
		}
		else
		{
			set<int> st;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==pos+1)
				{
					st.insert(i);
				}
			}
			if(st.size()==0||judge(pos+1,*st.begin(),*st.rbegin()))
			{
				puts("Yes");
			}
			else puts("No");
		}
	}
	return 0;
}
/*
101
110
011
*/