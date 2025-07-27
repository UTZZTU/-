#include <bits/stdc++.h>
using namespace std;
bool judge(int n)
{
	if(n==2||n==3)
	return true;
	if(n%6!=1&&n%6!=5)
	return false;
	else
	{
		for(int i=5;i<=floor(sqrt(n));i+=6)
		{
			if(n%i==0||n%(i+2)==0)
			return false;
		}
		return true;
	}
}
vector<int> ss;
int main ()
{
	int n,m;
	cin>>m>>n;
	for(int i=2;ss.size()<=n;i++)
	{
		if(judge(i))
		ss.push_back(i);
	}
	for(int i=m-1;i<=n-1;i++)
	{
		if((i-(m-1))%10==0)
		cout<<ss[i];
		else
		cout<<" "<<ss[i];
		if((i-(m-1))%10==9)
		cout<<endl;
	}
	return 0;
}