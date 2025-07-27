#include <bits/stdc++.h>
using namespace std;
vector<int> jh1,jh2;
void find (int shu,int num)
{
	if(shu==1)
	{
		if(num==1)
		jh1.push_back(shu);
		else
		jh2.push_back(shu);
		return;
	}
	if(num==1)
	jh1.push_back(shu);
	else
	jh2.push_back(shu);
	if(shu&1)
	shu=(shu-1)/2;
	else
	shu=shu/2;
	find(shu,num);
}
int x,y;
int main ()
{
	cin>>x>>y;
	find(x,1);
	find(y,2);
	for(int i=0;i<jh1.size();i++)
	{
		vector<int>::iterator it=find(jh2.begin(),jh2.end(),jh1[i]);
		if(it!=jh2.end())
		{
			cout<<jh1[i];
			return 0;
		}
	}
	return 0;
}