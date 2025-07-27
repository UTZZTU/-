#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,x,pos;
bool judge()
{
	if(x>n)
	return false;
	if(x==n)
	return true;
	ll i=n,j=x;
	vector<int> vec1,vec2;
	while(i||j)
	{
		vec1.push_back(i%2);
		vec2.push_back(j%2);
		i/=2;
		j/=2;
	}
	reverse(vec1.begin(),vec1.end());
	reverse(vec1.begin(),vec1.end());
	for(int i=0;i<vec1.size();i++)
	{
		if(vec1[i]!=vec2[i])
		{
			pos=vec1.size()-i;
			if(i!=vec1.size()-1&&vec1[i+1]!=0)
			return false;
			return true;
		}
	}
	return true;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		pos=-1;
		cin>>n>>x;
		if(judge())
		{
			if(pos==-1)
			printf("%lld\n",x);
			else
			printf("%lld\n",(ll)pow(2,pos+1)+x);
		}
		else
		printf("-1\n");
	}
	return 0;
}