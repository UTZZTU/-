#include <bits/stdc++.h>
using namespace std;
set<int> st;
vector<int> vec;
map<int,int> mp1,mp2,mp3;
int add[100010],surface[100010],a[100010],n,k,ans,maxx;
char c;
int main ()
{
	cin>>n;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k>>c;
		st.insert(k);
		if(c=='.')
		{
			ans++;
			mp2[k]++;
		}
		else if(c=='+')
		mp1[k]++;
		else if(c=='-')
		mp3[k]++;
	}
	for(auto it=st.begin();it!=st.end();it++)
	vec.push_back(*it);
	for(int i=0;i<vec.size();i++)
	{
		if(i==0)
		add[i]=mp1[vec[i]];
		else
		add[i]=add[i-1]+mp1[vec[i]];
	}
	for(int i=vec.size()-1;i>=0;i--)
	{
		if(i==vec.size()-1)
		surface[i]=mp3[vec[i]];
		else
		surface[i]=surface[i+1]+mp3[vec[i]];
	}
    for(int i=0;i<vec.size();i++)
    {
    	maxx=max(maxx,n-add[i]-surface[i]-(ans-mp2[vec[i]]));
	}
	cout<<maxx;
	return 0;
}