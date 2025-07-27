#include <iostream>
#include <vector>
using namespace std;
int n,a[200010],vis[200010],flag;
vector<int> vec;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		flag=0;
		vis[i]=1;
		vector<int> tt;
		tt.push_back(i);
		int j=a[i];
		while(!vis[j])
		{
			tt.push_back(j);
			vis[j]=1;
			j=a[j];
		}
		j=a[tt[tt.size()-1]];
		for(int k=0;k<tt.size();k++)
		{
			if(tt[k]==j)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			flag=0;
			for(int j=0;j<tt.size();j++)
			{
				if(flag)
				{
					vec.push_back(tt[j]);
				}
				else
				{
					if(tt[j]==a[tt[tt.size()-1]])
					{
						flag=1;
						vec.push_back(tt[j]);
					}
				}
			}
			cout<<vec.size()<<endl;
			for(int j=0;j<vec.size();j++) cout<<vec[j]<<" ";
			return 0;
		}
	}
	return 0;
}