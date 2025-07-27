#include <bits/stdc++.h>
using namespace std;
int n,a,b,k,cnt;
vector<int> vec;
string u;
int main ()
{
	cin>>n>>a>>b>>k;
	getchar();
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='0')
		{
			cnt++;
			if(cnt==b)
			{
				vec.push_back(i+1);
				cnt=0;
			}
		}
		else
		cnt=0;
	}
	cout<<vec.size()-a+1<<endl;
	for(int i=0;i<vec.size()-a+1;i++)
	cout<<vec[i]<<" ";
	return 0;
}