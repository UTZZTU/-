#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt;
vector<int> v[3];
//struct node
//{
//	int u,v,w;
//};
//set<node> st;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
	}
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	sort(v[2].begin(),v[2].end());
	vector<int> vec;
	if(v[0].size())
	{
		vec.push_back(v[0][0]);
	}
	for(int i=1;i<v[0].size();i++)
	{
		if(v[0][i]==v[0][i-1]) continue;
		else vec.push_back(v[0][i]);
	}
	v[0]=vec;
	vec.clear();
	if(v[1].size())
	{
		vec.push_back(v[1][0]);
	}
	for(int i=1;i<v[1].size();i++)
	{
		if(v[1][i]==v[1][i-1]) continue;
		else vec.push_back(v[1][i]);
	}
	v[1]=vec;
	
	vec.clear();
	if(v[2].size())
	{
		vec.push_back(v[2][0]);
	}
	for(int i=1;i<v[2].size();i++)
	{
		if(v[2][i]==v[2][i-1]) continue;
		else vec.push_back(v[2][i]);
	}
	v[2]=vec;
//	vec.clear();
//	cout<<v[0].size()<<" "<<v[1].size()<<" "<<v[2].size()<<endl;
	
//	for(int i=0;i<3;i++)
//	{
//		for(int j=0;j<v[i].size();j++)
//		{
//			cout<<v[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=0;i<v[1].size();i++)
	{
		
		int l=0,r=v[2].size()-1;
		if(l>=v[0].size()||r<0) break;
//		if(i>0&&v[1][i]==v[1][i-1]) continue;
//		cout<<l<<" "<<r<<endl;
		while(l<v[0].size()&&r>=0)
		{
//			cout<<l<<" "<<i<<" "<<r<<endl;
			if(v[0][l]+v[2][r]==2*v[1][i])
			{
				cout<<"["<<v[0][l]<<", 0] ["<<v[1][i]<<", 1] ["<<v[2][r]<<", 2]"<<endl;
//				st.insert()
				cnt++;
				l++;
			}
			else
			{
				if(v[0][l]<=v[1][i]&&v[2][r]>=v[1][i])
				{
					int l1=abs(v[0][l]-v[1][i]),l2=abs(v[1][i]-v[2][r]);
					if(l1>=l2) l++;
					else r--;
				}
				else if(v[0][l]>=v[1][i]&&v[2][r]<=v[1][i])
				{
					int l1=abs(v[0][l]-v[1][i]),l2=abs(v[1][i]-v[2][r]);
					if(l1>=l2) r--;
					else l++;
				}
				else if(v[0][l]>=v[1][i]&&v[2][r]>=v[1][i])
				{
					r--;
				}
				else if(v[0][l]<=v[1][i]&&v[2][r]<=v[1][i])
				{
					l++;
				}
			}
		}
	}
	if(!cnt)
	{
		cout<<-1;
	}
	return 0;
}
