#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> vec;
ll n;
void dfs(ll level,ll number)
{
	if(level>9)
	{
		vec.push_back(number);
		return;
	}
	if(level==1)
	{
		for(int i=1;i<=9;i++)
		{
			dfs(level+1,i);
		}
	}
	else if(level==2)
	{
		dfs(level+1,number*10+number);
	}
	else if(level==6)
	{
		
		dfs(level+1,number*10+(number%10));
	}
	else if(level==9)
	{
		dfs(level+1,number*10+(number/10%10));
	}
	else
	{
//		if(level==7)
//		cout<<number<<endl;
		for(int i=0;i<=9;i++)
		dfs(level+1,number*10+i);
	}
}
int main ()
{
	dfs(1,0);
	cin>>n;
	sort(vec.begin(),vec.end());
	cout<<vec[n-1];
	return 0;
}