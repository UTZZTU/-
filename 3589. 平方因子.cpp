#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int pd,n;
int main ()
{
	for(int i=2;i*i<=1000;i++)
	vec.push_back(i*i);
	while(cin>>n)
	{
		pd=0;
		for(auto it=vec.begin();it!=vec.end();it++)
		{
			if(n%*it==0)
			{
				pd=1;
				break;
			}
		}
		if(pd)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}