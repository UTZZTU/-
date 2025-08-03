#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],maxx,minn,mid;
void solve()
{
	maxx=0,minn=1e9;
	cin>>n;
	vector<int> vec;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	while(vec.size()<=50)
	{
		mid=maxx+minn>>1;
		vec.push_back(mid);
		maxx=0,minn=1e9;
		for(int i=1;i<=n;i++)
		{
			a[i]=abs(a[i]-mid);
			maxx=max(maxx,a[i]);
			minn=min(minn,a[i]);
		}
		if(maxx==minn)
		{
			if(maxx==0)
			{
				break;
			}
			else
			{
				vec.push_back(maxx);
				break;
			}
		}
	}
	if(vec.size()>40)
	{
		cout<<-1<<endl;
		return;
	}
	cout<<vec.size()<<endl;
	for(auto c:vec)
	{
		cout<<c<<" ";
	}
	cout<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}