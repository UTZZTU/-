#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,k;
struct node
{
	int num,pos;
}s[200010];
bool cmp(node x,node y)
{
	return x.num<y.num;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		s[i].num=k;
		s[i].pos=i;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=2;i<=n;i++)
	{
		if(s[i].num==s[i-1].num)
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<s[i].pos<<" ";
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