#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node
{
	int pos,num,flag;
}s[31];
bool cmp(node x,node y)
{
	if(x.num!=y.num) return x.num>y.num;
	else return x.pos<y.pos;
}
int get(int x)
{
	if(x==1) return 25;
	else if(x==2) return 21;
	else if(x==3) return 18;
	else
	{
		return 16-(x-4);
	}
}
void solve()
{
	for(int i=1;i<=30;i++)
	{
		s[i].pos=i;
		s[i].num=0;
		s[i].flag=0;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=20;j++)
		{
			int c,p;
			cin>>c>>p;
			s[c].num+=get(p);
			s[c].flag=1;
		}
	}
	sort(s+1,s+1+30,cmp);
	for(int i=1;i<=30;i++)
	{
		if(s[i].flag==0) continue;
		cout<<s[i].pos<<" "<<s[i].num<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
