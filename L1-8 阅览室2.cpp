#include <bits/stdc++.h>
using namespace std;
int n,f[1010],hh,mm,t,book;
char s[5];
int main ()
{
	int res=0,ti=0;
	cin>>n;
	memset(f,-1,sizeof(f));
	while(scanf("%d%s%d:%d",&book,s,&hh,&mm)!=EOF)
	{
		
		if(book==0)
		{
			t++;
			if(res) cout<<res<<" "<<(int)(ti*1.0/res+0.5)<<endl;
			else cout<<0<<" "<<0<<endl;
			if(t==n) break;
			res=0,ti=0;
			memset(f,-1,sizeof(f));
			continue;
		}
		if(s[0]=='S')
		{
				f[book]=hh*60+mm;
		}
		else if(s[0]=='E')
		{
			if(f[book]!=-1)
			{
				res++;
				ti+=hh*60+mm-f[book];
				f[book]=-1;
			}
		}
	}
	return 0;
}
