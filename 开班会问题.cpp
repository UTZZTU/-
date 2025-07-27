#include <iostream>
#include <algorithm>
using namespace std;
int mx=0,scx,scy,f=0;
struct time
{
	int begin,end;
}s[200];
bool cmp(time x,time y)
{
		if(x.begin!=y.begin)
	return x.begin<y.begin;
	else
	return x.end<y.end;
}
void xbx(int n)
{
	if(n==1)
	{
		f++;
		scx=s[1].begin;
		scy=s[1].end;
		xbx
	}
}
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].begin>>s[i].end;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<s[i].begin<<s[i].end<<endl;
	}
	xbx(1);
	cout<<mx;
	return 0;
}