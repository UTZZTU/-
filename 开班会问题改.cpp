#include <iostream>
#include <algorithm>
using namespace std;
struct time
{
	int ks,js;
}s[210];
bool cmp(struct time x,struct time y)
{
	return x.js<y.js;
}
int main()
{
	int n,sum=0,sc;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>s[i].ks>>s[i].js;
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			sc=s[i].js;
			sum=1;
		}
		else
		{
			if(sc<=s[i].ks)
			{
				sum++;
				sc=s[i].js;
			}
		}
	}
	cout<<sum;
	return 0;
}