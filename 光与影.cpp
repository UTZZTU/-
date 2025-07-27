#include<bit/sdc++.h>
using namespace std;
long long c(int m,int n)
{
	int a = 1,b = 1;
	n = min(n,m-n);				
	if( n == 0 )
		return 1;
	for( int i = m ; i >=m-n+1 ; i--  )
		a = a*i;
	for( int i = 1 ; i <= n ; i++ )
		b = b*i;
	return a/b;
}
int main(){
	long long n,m,sum;
	cin>>n>>m;
	if(n>m){
		cout<<c(pow(2,m));
	}
	else if(n<=m)
	{
	
		sum=1;
		for(int i=1;i<=n;i++){
			if(i==n)
			sum-=m-n+1;
			sum+=c(m,i);
		}
		cout<<sum<<endl;
	}
	return 0;
}
