#include <bits/stdc++.h>
using namespace std;
int t,n,a[210],bz;
string s;
bool judge(string s)
{
	int res1=0,res2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='W')
		{
			a[i+1]=1;
			res1++;
		}
		else
		{
			a[i+1]=0;
			res2++;
		}
	}
	if(res1%2==0)
	{
		bz=1;
		return true;
	}
	if(res2%2==0)
	{
		bz=0;
		return true;
	}
	return false;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		getchar();
		cin>>s;
		cout<<s<<endl;
		if(judge(s))
		{
			vector<int> vec;
			for(int i=1;i<n;i++)
			{
				if(a[i]==a[i+1])
				{
					if(a[i]!=bz)
					{
						i++;
					}
					else
					{
						vec.push_back(i);
						a[i]=a[i+1]=1-bz;
					}
				}
				else
				{
					if(a[i]==bz)
					{
						swap(a[i],a[i+1]);
						vec.push_back(i);
					}
				}
			}
			cout<<vec.size()<<endl;
			if(vec.size()!=0)
			{
				for(int i=0;i<vec.size();i++)
				{
					cout<<vec[i]<<" ";
				}
				cout<<endl;
			}
		}
		else
		cout<<-1<<endl;
	}
	return 0;
}