#include <bits/stdc++.h>
using namespace std;
int a,b,c,cz1,cz2,t,u;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a==b&&b==c)
		cout<<-1<<endl;
		else
		{
			
			cz1=abs(b-a),cz2=abs(c-b);
			if(cz1==0)
			{
				vector<int> vec;
				for(int i=1;i<=floor(sqrt(cz2));i++)
				{
					if(cz2%i==0)
					{
						vec.push_back(i);
						u=cz2/i;
						if(u!=i)
						vec.push_back(u);
					}
				}
				sort(vec.begin(),vec.end());
				for(int i=0;i<vec.size();i++)
				{
					if(i!=0)
					cout<<" ";
					cout<<vec[i];
				}
				cout<<endl;
			}
		    else if(cz2==0)
		    {
		    	vector<int> vec;
				for(int i=1;i<=floor(sqrt(cz1));i++)
				{
					if(cz1%i==0)
					{
						vec.push_back(i);
						u=cz1/i;
						if(u!=i)
						vec.push_back(u);
					}
				}
				sort(vec.begin(),vec.end());
				for(int i=0;i<vec.size();i++)
				{
					if(i!=0)
					cout<<" ";
					cout<<vec[i];
				}
				cout<<endl;
			}
			else
			{
				vector<int> vec;
				for(int i=1;i<=floor(sqrt(cz1));i++)
				{
					if(cz1%i==0&&cz2%i==0)
					vec.push_back(i);
					u=cz1/i;
					if(u!=i&&cz1%(u)==0&&cz2%(u)==0)
					vec.push_back(cz1/i);
				}
				sort(vec.begin(),vec.end());
				for(int i=0;i<vec.size();i++)
				{
					if(i!=0)
					cout<<" ";
					cout<<vec[i];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}