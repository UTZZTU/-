#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,l1[N],l2[N],r1[N],r2[N];
set<pair<int,int>> st1,st2;
void work(set<pair<int,int>> &st,int l,int r,int &num)
{
	st.insert({l,r});
	pair<int,int> p=*st.begin();
	while(p.first<=num)
	{
		num=max(num,p.second+1);
		st.erase(st.begin());
		if(st.empty()) return;
		p=*st.begin();
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l1[i]>>r1[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>l2[i]>>r2[i];
	}
	int num1=1,num2=1;
	for(int i=1;i<=n;i++)
	{
		work(st1,l1[i],r1[i],num1);
		work(st2,l2[i],r2[i],num2);
		if(num1>num2)
		{
			cout<<"sa_win!"<<endl;
		}
		else if(num1==num2)
		{
			cout<<"win_win!"<<endl;
		}
		else
		{
			cout<<"ya_win!"<<endl;
		}
		cout<<abs(num1-num2)<<endl;
	}
	return 0;
}