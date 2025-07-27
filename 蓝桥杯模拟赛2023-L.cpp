#include <bits/stdc++.h>
using namespace std;
int n,m,k,pos=-1;
string s,u;
int get_max(int l,int r)
{
	int minn=0x3f3f3f3f,pp;
	for(int i=l;i<=r;i++)
	{
		if((s[i]-'A')<minn)
		{
			minn=(s[i]-'A');
			pp=i;
		}
	}
	return pp;
}
int main ()
{
	scanf("%d%d",&n,&m);
	getchar();
	cin>>s;
	k=n-m;
	for(int i=1;i<=k;i++)
	{
		int u=k-i;
		pos=get_max(pos+1,n-u-1);
		cout<<s[pos];
//		cout<<u<<endl;
	}
	return 0;
}