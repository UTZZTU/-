#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,k,b,x,y,cnt,pp;
vector<int> vec1,vec2,vec3,vec;
void solve()
{
	cin>>n>>k>>b;
	for(int i=1;i<=2*n;i++)
	{
		cin>>x>>y;
		if(k*x+b==y) vec2.push_back(i);
		else if(k*x+b>y) vec1.push_back(i);
		else vec3.push_back(i);
	}
	if(vec1.size()<vec3.size()) swap(vec1,vec3);
	int minn=min(vec1.size(),vec3.size());
	cout<<minn+min(vec1.size()-minn,vec2.size())+(vec2.size()-min(vec1.size()-minn,vec2.size()))/2<<endl;
	for(int i=0;i<minn;i++)
	{
		cout<<vec1[i]<<" "<<vec3[i]<<" Y"<<endl;
	}
	for(int i=minn,j=0;i<vec1.size()&&j<vec2.size();i++,j++)
	{
		cout<<vec1[i]<<" "<<vec2[j]<<" Y"<<endl;
	}
	if(vec1.size()-minn>=vec2.size())
	{
		for(int i=minn+vec2.size();i<vec1.size();i+=2)
		{
			cout<<vec1[i]<<" "<<vec1[i+1]<<" N"<<endl;
		}
	}
	else
	{
		for(int i=vec1.size()-minn;i<vec2.size();i+=2)
		{
			cout<<vec2[i]<<" "<<vec2[i+1]<<" Y"<<endl;
		}
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