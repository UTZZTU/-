#include <bits/stdc++.h>
using namespace std;
int n,sum,res,cnt;
string s;
vector<int> vec;
int main ()
{
	cin>>n;
	getchar();
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1') sum++;
		else
		{
			if(sum>0) vec.push_back(sum);
			sum=0;
		}
	}
	if(sum>0) vec.push_back(sum);
	sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;i--)
	{
		res+=vec[i];
		cnt++;
		if(cnt==2) break;
	}
	printf("%d",res);
	return 0;
}