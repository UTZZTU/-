#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
map<pair<int,int>,int> mp;
int main ()
{
	int n,m,s,p,sx,sy,ex,ey,wo=0,num1=0,num2=0;
	cin>>n>>m>>s;
	for(int i=1;i<=s;i++)
	{
		cin>>p>>sx>>sy>>ex>>ey;
		int p1=(sx-1)*m+sy,p2=(ex-1)*m+ey;
		if(p1>p2) swap(p1,p2);
//		cout<<i<<" 888   "<<wo<<endl;
		if(sx<1||sx>n||sy<1||sy>m||ex<1||ex>n||ey<1||ey>m||mp[{p1,p2}]==1||sx!=ex&&sy!=ey||sx==ex&&sy==ey||p!=wo||abs(sx-ex)+abs(sy-ey)!=1)
		{
			vec.push_back(i);
			continue;
		}
		mp[{p1,p2}]=1;
//		cout<<"zhuanhuan:"<<p1<<" "<<p2<<endl;
		int p3,p4;
		int flag=0;
		if(sx==ex)
		{
			if(sx-1>=1)
			{
				p3=(sx-2)*m+sy,p4=(sx-2)*m+ey;
				if(p3>p4) swap(p3,p4);
				if(mp[{p3,p4}]==1&&mp[{p3,p1}]==1&&mp[{p4,p2}]==1)
				{
					flag=1;
					if(wo==0) num1++;
					else num2++;
				}
//				cout<<"www"<<p3<<" "<<p4<<endl;
			}
			
			if(sx+1<=n)
			{
				p3=sx*m+sy,p4=sx*m+ey;
				if(p3>p4) swap(p3,p4);
				if(mp[{p3,p4}]==1&&mp[{p1,p3}]==1&&mp[{p2,p4}]==1)
				{
					flag=1;
					if(wo==0) num1++;
					else num2++;
				}
//				cout<<"www"<<p3<<" "<<p4<<endl;
			}
		}
		else
		{
			if(sy-1>=1)
			{
				p3=(sx-1)*m+sy-1,p4=(ex-1)*m+sy-1;
				if(p3>p4) swap(p3,p4);
				if(mp[{p3,p4}]==1&&mp[{p3,p1}]==1&&mp[{p4,p2}]==1)
				{
					flag=1;
					if(wo==0) num1++;
					else num2++;
//					cout<<"µÚ"<<i<<"´Î"<<endl;
				}
//				cout<<"www"<<p3<<" "<<p4<<endl;
			}
			
			if(sy+1<=m)
			{
				p3=(sx-1)*m+sy+1,p4=(ex-1)*m+sy+1;
				if(p3>p4) swap(p3,p4);
				if(mp[{p3,p4}]==1&&mp[{p1,p3}]==1&&mp[{p2,p4}]==1)
				{
					flag=1;
					if(wo==0) num1++;
					else num2++;
				}
//				cout<<"www"<<p3<<" "<<p4<<endl;
			}
		}
//		cout<<p3<<" "<<p4<<endl;
		if(!flag) wo=1-wo; 
	}
	if(vec.size()==0) cout<<-1<<endl;
	else
	{
		for(int i=0;i<vec.size();i++)
		{
			if(i>0) cout<<" ";
			cout<<vec[i];
		}
		cout<<endl;
	}
	if(num1>num2)
	{
		cout<<0<<" "<<num1;
	}
	else cout<<1<<" "<<num2;
	return 0;
}
