#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,p[510],x,y,z,cj=0x3f3f3f3f,t;
//struct node
//{
//	int pos,v;
//}s[510];
//bool cmp(node x,node y)
//{
//	if(x.v!=y.v) return x.v<y.v;
//	else return x.pos<y.pos;
//}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
//		s[i].pos=i;
//		s[i].v=p[i];
	}
//	sort(s+1,s+1+n,cmp);
	cin>>x>>y;
	z=p[x]+p[y]+1>>1;
	for(int i=1;i<=n;i++)
	{
		if(abs(p[i]-z)<cj)
		{
			cj=abs(p[i]-z);
			t=i;
		}
	}
	cout<<t<<endl;
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