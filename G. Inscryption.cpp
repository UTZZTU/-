//
#include<bits/stdc++.h>
using namespace std;
//#define int long long 

const int N=1e6+7;
int in[N];
int sum[N];

int gcd( int a,int b )
{
	return a%b==0 ? b : gcd( b,a%b );
}

signed main()
{
	int t,n,i,cnt1,cnt2,cnt0;
	int sum1,sum2,sum0;
	int t1,t2;
	
	scanf("%d",&t );
	while( t-- )
	{
		scanf("%d",&n );
		sum1=sum2=sum0=0;
		for( i=1;i<=n;i++ )
		{
			scanf("%d",&in[i] );
			sum1+=( in[i]==1 );
			sum2+=( in[i]==-1 );
			sum0+=( in[i]==0 );	
		}
		sum[n+1]=0;
		for( i=n;i>=1;i-- ) sum[i]=sum[i+1]+( in[i]==-1 );
		
		t1=1,t2=0;
		for( i=1;i<=n;i++ )
		{
			in[i]==-1 ? t2++ : t1++ ;
			if( t2>=t1 ) break;
		}
		
		if( t2>=t1 )
		{
			printf("-1\n");
			continue;
		}
		
		cnt1=cnt2=cnt0=0;
		t1=t2=0;
		for( i=1;i<=n;i++ )
		{
			if( in[i]==1 ) 			cnt1++;
			else if( in[i]==-1 ) 	cnt2++;
			else 					cnt0++;
			
			in[i]==-1 ? t2++ : t1++ ;
			
			if( t1>=sum[i+1] )
			{
				
				sum1-=cnt1;
				sum2-=cnt2;
				sum0-=cnt0;
//				cout<<"pos:"<<i<<endl;
//				cout<<sum1<<" "<<sum0<<" "<<t1<<endl;
				
				if( sum1>=sum0 ) 
				{
					int x=t1+sum1+1;
					int y=sum1-sum0+1+t1-sum[i+1];
					int ans=gcd( x,y );
					printf("%d %d\n",x/ans,y/ans );
					break;
				}
				else
				{
					int uu=1;
					sum0-=sum1;
					if(sum0)
					{
						if(t1+1-sum[i+1]>=2)
						{
							sum0--;
							t1--;
							uu++;
						}
					}
					int x=t1+sum1+( sum0+1 )/2+uu;
					int y=1+sum0%2+t1-sum[i+1];
//					cout<<"***"<<x<<" "<<y<<endl;
					int ans=gcd( x,y );
					printf("%d %d\n",x/ans,y/ans );
					break;
				}
			}
		}
	}
	
	return 0;
} 
/*
0123

*/
