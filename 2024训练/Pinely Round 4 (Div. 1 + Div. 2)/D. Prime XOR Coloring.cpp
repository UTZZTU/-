#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[200010],zs[200010],tp[65];
int primes[200010],cnt;
bool st[200010];
void tpp(int l,int r,int temp[])
{
	for(int i=1,j=l;i<=4;i++,j++)
	{
		tp[j]=temp[i];
		tp[++j]=temp[i];
	}
}
void init()
{
//	clock_t startTime,endTime;
//	startTime = clock();//计时开始
	st[1]=st[0]=true;
	for(int i=2;i<=200000;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=200000;++j)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
	}
	f[1]=1;
	zs[1]=1;
	for(int i=2;i<=200000;i++)
	{
		if(i%64==0)
		{
			int cnt=i-64+1;
			int pp=ceil(cnt/64.0)*4+4;
//			cout<<i<<" "<<pp<<" ppp:"<<endl;
			int ppp1[5]={0,pp-3,pp-2,pp-1,pp};
			tpp(1,8,ppp1);
			int ppp2[5]={0,pp,pp-1,pp-2,pp-3};
			tpp(9,16,ppp2);
			int ppp3[5]={0,pp-1,pp,pp-3,pp-2};
			tpp(17,24,ppp3);
			int ppp4[5]={0,pp-2,pp-3,pp,pp-1};
			tpp(25,32,ppp4);
			int ppp5[5]={0,pp-2,pp-3,pp,pp-1};
			tpp(33,40,ppp5);
			int ppp6[5]={0,pp-1,pp,pp-3,pp-2};
			tpp(41,48,ppp6);
			int ppp7[5]={0,pp,pp-1,pp-2,pp-3};
			tpp(49,56,ppp7);
			int ppp8[5]={0,pp-3,pp-2,pp-1,pp};
			tpp(57,64,ppp8);
			tp[0]=pp;
//			if(i!=64) continue;
//			for(int j=1;j<=63;j++)
//			{
//				cout<<tp[j]<<" "<<endl;
//			}
		}
		if(i<=63)
		{
			set<int> stt;
	    	for(int j=1;j<i;j++)
	    	{
	    		stt.insert(f[j]);
			}
	    	for(int j=1;j<i;j++)
	    	{
	    		if(!st[i^j])
	    		{
	    			if(stt.find(f[j])!=stt.end())
	    			stt.erase(stt.find(f[j]));
				}
			}
			if(stt.size())
			{
				f[i]=*stt.rbegin();
				zs[i]=zs[i-1];
			}
			else
			{
				zs[i]=zs[i-1]+1;
				f[i]=zs[i];
			}
		}
		else
		{
			int cnt=i-64+1;
			if(cnt%64==1||cnt%64==3||cnt%64==5||cnt%64==7)
			{
				zs[i]=zs[i-1]+1;
			}
			else
			{
				zs[i]=zs[i-1];
			}
			if(cnt%64==0) f[i]=tp[0];
			else f[i]=tp[cnt%64];
		}
	}
//	endTime = clock();//计时结束
//    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
//	for(int i=1;i<=200;i++)
//	{
//		cout<<f[i]<<" "<<zs[i]<<endl;
//	}
}
void solve()
{
	cin>>n;
	cout<<zs[n]<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<" ";
	}
	cout<<endl;
}
/*
1
1
2
1 2
2
1 2 2
3
1 2 2 3
3
1 2 2 3 3
4
1 2 2 3 3 4
4
1 2 2 3 3 4 4
4
1 2 22 3 33 4 4 4

5
5
6
6
7
7


*/
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}