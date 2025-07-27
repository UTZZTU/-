#include<bits/stdc++.h>
using namespace std;
int n,total,k,len,mid,len1;
string a;
int main()
{
	int st[100010];
	vector<int>d;
	cin>>n;
	len=len1=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a=="Push")
		{
			cin>>k;
			st[++len]=k;
			int l=0,r=len1++;
			while(l<r)
			{
				mid=(r+l)>>1;
				if(d[mid]>=k)r=mid;
				else l=mid+1;
			}
			d.insert(d.begin()+l,k);
		}
		else if(a=="Pop")
		{
			if(len==0)cout<<"Invalid"<<endl;
			else {
				k=st[len--];
				cout<<k<<endl;
				int l=0,r=len1--;
				while(l<r)
				{
					mid=(r+l)>>1;
					if(d[mid]>k)r=mid-1;
					else if(d[mid]<k)l=mid+1;
					else l=r=mid;
				}
				d.erase(d.begin()+l);
			}
		}
		else{
		
			if(len1==0)cout<<"Invalid"<<endl;
			else cout<<d[(len1-1)>>1]<<endl;
		}
	}
	return 0;
}