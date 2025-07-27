#include <bits/stdc++.h>
using namespace std;
int n,f[1010],hh,mm,t,book;
char s[5];
pair<int,int> p[1010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int res=0,ti=0;
		memset(f,0,sizeof(f));
		while(scanf("%d%s%d:%d",&book,s,&hh,&mm),book)
		{
			if(s[0]=='E')
			{
				if(f[book])
				{
					ti+=(hh-p[book].first)*60+(mm-p[book].second);
					res++;
					f[book]=0;
				}
			}else
			{
				f[book]=1;
				p[book]={hh,mm};
			}
		}
		if(res) cout<<res<<" "<<(int)(ti*1.0/res+0.5)<<endl;
		else cout<<0<<" "<<0<<endl;
	}
	return 0;
}
