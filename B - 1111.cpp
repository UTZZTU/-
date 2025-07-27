#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int n,d[110],res;
bool judge(int x)
{
	set<int> st;
	while(x)
	{
		st.insert(x%10);
		x/=10;
	}
	return (int)st.size()==1;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=d[i];j++)
		{
			if(judge(i)&&judge(j)&&i%10==j%10) res++;
		}
	}
	cout<<res;
	return 0;
}