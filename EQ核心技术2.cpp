#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n;
vector<pair<int,int>> vec;
struct node{
	int x,y;
}a[N];
bool cmp(node a,node b){
	return a.x<b.x;
}
bool check(int mid){
	vector<pair<int,int>>v;
//	int cnt=1;
//	for(int i=0;i<vec.size();i++)
//	{
//		int len=vec[i].second-vec[i].first;
//		int k=cnt;
//		for(k;k<=cnt+len;k++)
//		{
//			if(a[k].y<mid)
//			{
//				int u=k;
//				int maxx=0,minn=0x3f3f3f3f;
//				while(u<=cnt+len)
//				{
//					if(a[u].y<mid)
//					{
//						maxx=max(maxx,abs(a[u].y-mid));
//						minn=min(minn,abs(a[u].y));
//					}
//					else
//					{
//						minn=min(minn,abs(a[u].y));
//					}
//					if(maxx>minn) break;
//					u++;
//				}
//				u--;
//				v.push_back({k,u});
////				cout<<k<<" "<<u<<endl;
//				k=u;
//			}
//		}
//		cnt=k;
//	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].y<mid)
		{
			int j=i;
			int maxx=0,minn=0x3f3f3f3f;
			while(j<=n)
			{
				if(a[j].y<mid)
				{
					maxx=max(maxx,abs(a[j].y-mid));
					minn=min(minn,abs(a[j].y));
				}
				else
				{
					minn=min(minn,abs(a[j].y));
				}
				if(maxx>minn) break;
				j++;
			}
			j--;
			v.push_back({i,j});
//				cout<<k<<" "<<u<<endl;
			i=j;
		}
	}
	return v.size()<=1;
//	cout<<"v.size---"<<v.size()<<endl;
//	if(v.size()==0) return true;
//	if(v.size()>1) return false;
//	int p=v[0].first,q=v[0].second;
//	int minn=0x3f3f3f3f,maxx=0;
//	for(p;p<=q;p++)
//	{
//		maxx=max(maxx,abs(a[p].y-mid));
//		minn=min(minn,abs(a[p].y));
//	}
//	return maxx<=minn;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	int l,r;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			l=a[i].x;
			r=a[i].x;
		}
		else
		{
			if(a[i].x==r+1)
			{
				r++;
			}
			else
			{
				vec.push_back({l,r});
				l=a[i].x;
				r=a[i].x;
			}
		}
	}
	vec.push_back({l,r});
//	for(int i=0;i<vec.size();i++)
//	{
//		cout<<vec[i].first<<" "<<vec[i].second<<endl;
//	}
	l=-1e9,r=0;
	while(l<r){
		int mid=l+r+1>>1;
//		cout<<mid<<endl;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}