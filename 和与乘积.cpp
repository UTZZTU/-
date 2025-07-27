#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+10;
long long sum[N],num[N],onecnt[N];
int n=1;
int k;
int main()
{
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int temp;
		cin>>temp;
		if(temp==1)
		{
			sum[n]++;
			onecnt[n]++;	
		}
		else
		{
			sum[n]+=sum[n-1]+temp;
			num[n]=temp;
			n++;
		}
	}
	long long res=sum[n-1]+onecnt[n];//计算所有数字的和，因为最后有可能有一段连续的1，所以要加上onecnt[n] 
	long long ans=k;//初值为原序列的长度，因为原序列的每一个元素都构成一组解 
	for(int i=1;i<n;i++)
	{
		long long p=num[i];
		for(int j=i+1;j<n;j++)
		{
			p*=num[j];
			if(p>res)
			break;
			long long d=p-sum[j]+sum[i-1]+onecnt[i];
			if(d==0)
			ans++;
			else if(onecnt[i]+onecnt[j+1]>=d&&d>0)//前后面所有的1加起来大于差值 
			{
				long long left=min(d,onecnt[i]);
				long long right=min(d,onecnt[j+1]);
				ans+=left+right-d+1;//left+right-d可以理解成左右两边最多可以空出这么些1来，那么所有情况就是这个数+1，因为也可以不空出来 
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 