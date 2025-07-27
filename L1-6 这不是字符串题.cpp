#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v1,v2;
int n,m;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		v1.push_back(k);
	}
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int len1,len2;
			cin>>len1;
			vector<int> v,v3;
			for(int i=0;i<len1;i++)
			{
				int k;
				cin>>k;
				v.push_back(k);
			}
			cin>>len2;
			for(int i=0;i<len2;i++)
			{
				int k;
				cin>>k;
				v3.push_back(k);
			}
			int pos=-1;
			for(int i=0;i<v1.size();i++)
			{
				if(v1[i]==v[0])
				{
					int cnt=1;
					for(int j=i+1,k=1;j<v1.size()&&k<v.size();j++,k++)
					{
						if(v1[j]==v[k]) cnt++;
						else break;
					}
					if(cnt==v.size())
					{
						pos=i;
						break;
					}
				}
			}
			v2.clear();
			if(pos!=-1)
			{
				for(int i=0;i<pos;i++)
				{
					v2.push_back(v1[i]);
				}
				for(int i=0;i<v3.size();i++)
				{
					v2.push_back(v3[i]);
				}
				for(int i=pos+len1;i<v1.size();i++)
				{
					v2.push_back(v1[i]);
				}
				v1=v2;
			}
		}
		else if(op==2)
		{
			v2.clear();
			if(v1.size())
			{
				v2.push_back(v1[0]);
				for(int i=1;i<v1.size();i++)
				{
					if((v2.back()+v1[i])%2==0)
					{
						v2.push_back((v2.back()+v1[i])/2);
						v2.push_back(v1[i]);
					}
					else v2.push_back(v1[i]);
				}
				v1=v2;
			}
		}
		else
		{
			int l,r;
			cin>>l>>r;
			l--,r--;
			while(l<r)
			{
				swap(v1[l],v1[r]);
				l++,r--;
			}
		}
//		for(int i=0;i<v1.size();i++)
//	{
//		if(i!=0) cout<<" ";
//		cout<<v1[i];
//	}
//	cout<<endl;
	}
	for(int i=0;i<v1.size();i++)
	{
		if(i!=0) cout<<" ";
		cout<<v1[i];
	}
	return 0;
}
