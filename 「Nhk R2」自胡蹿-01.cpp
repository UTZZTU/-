
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF=0x3f3f3f3f;
const int N=3005;
string s;
int k,cnt;

int f( int x,int y )
{
//	cout<<endl<<endl;			//
	
	cnt=0;
	while( x-1>=0 || y+1<s.size() )
	{
		if( s[x-1]==s[y] )		// you
		{
			cnt++;
			x-=2,y++;
			while( x>=0 && y<s.size() && s[x]==s[y] ) x--,y++;
			x++,y--;
			
			if( y-x+1+cnt>=k ) return -1;
		}
		
//		cout<<x<<" "<<y<<" "<<cnt<<endl;				//
		
		if( s[x]==s[y+1] )		// zuo
		{
			cnt++;
			x--,y+=2;
			while( x>=0 && y<s.size() && s[x]==s[y] ) x--,y++;
			x++,y--;
			
			if( y-x+1+cnt>=k ) return -1;
		}
		
//		cout<<x<<" "<<y<<" "<<cnt<<endl;			//
		
		if( s[x-1]!=s[y] && s[x]!=s[y+1] ) break;
	}
	
	return ( y-x+1 )+cnt;
}

int getAns( int x,int y )
{
	if( y-x+1>=k ) return 0;
	
	int ans=f( x,y );
	
	if( ans!=-1 ) 	return k-ans+cnt;
	else		
	{
//		cout<<"-1"<<" "<<cnt<<endl;				//
		
		return cnt;
	}
}

signed main()
{
	int n,i,j,tx,ty,ans;
	
	scanf("%lld%lld",&n,&k );
	cin>>s;
	
	ans=getAns( 0,0 );
	
	for( i=1;i<s.size();i++ )
	{
		for( j=1;i-j>=0 && i+j<s.size();j++ )
		{
			if( s[i-j]!=s[i+j] ) break;
		}
		tx=i-j+1;
		ty=i+j-1;
		
//		for( int k=tx;k<=ty;k++ ) cout<<s[k];				//
//		cout<<endl;
		
		ans=min( ans,getAns( tx,ty ) );
		
//		cout<<"ans:"<<ans<<endl;				//
	}
	
	for( i=1;i<s.size();i++ )
	{
		if( s[i-1]==s[i] )
		{
			for( j=1;i-1-j>=0 && i+j<s.size();j++ )
			{
				if( s[i-1-j]!=s[i+j] ) break;
			}
			tx=i-1-j+1;
			ty=i+j-1;
			
//			for( int k=tx;k<=ty;k++ ) cout<<s[k];				//
//			cout<<endl;
			
			ans=min( ans,getAns( tx,ty ) );
			
//			cout<<"ans:"<<ans<<endl;				//
		}
	}
	printf("%lld\n",ans );	
	
	return 0;
}

