#include <bits/stdc++.h>
using namespace std;
int n,k,flag,beg=-1,en=-1,maxx,pos,maxx1,pos1,minn;
string s;
int get_num(int l,int tt)
{
		if(l>=k)
		{
			return 0;
		}
		else if(k<=l+2*tt)
		{
			return (k-l+1)/2;
		}
		else
		{
			return tt+(k-l-tt*2);
		}
}
int main ()
{
	cin>>n>>k;
	cin>>s;
	minn=k;
	for(int i=0;i<s.size();i++)
	{
		int j=0;
		for(j;i+j<s.size()&&i-j>=0&&s[i+j]==s[i-j];j++)
		{
			;
		}
		j--;
//		printf("j:%d\n",j);
		int tt=0,cnt=i-j,pp=j+1;
		while((i-pp>=0&&s[i-pp]==s[cnt])||(i+pp<s.size()&&s[i+pp]==s[cnt]))
		{
			tt++;
			pp++;
		}
		minn=min(minn,get_num(2*j+1,tt));
//		printf("tt:%d\n",tt);
//		if(maxx<2*j+1)
//		{
//			beg=i-j,en=i+j;
//			maxx=2*j+1;
//			pos=tt;
//		}
//		else if(maxx==2*j+1)
//		{
//			if(tt>pos)
//			{
//				pos=tt;
//				beg=i-j,en=i+j;
//			}
//		}
//		if(2*j+1+tt*2>maxx1)
//		{
//			maxx1=2*j+1+tt*2;
//			pos1=tt;
//		}
//		else if(2*j+1+tt*2==maxx1)
//		{
//			if(tt<pos1)
//			{
//				pos1=tt;
//			}
//		}
//		cout<<maxx<<" "<<beg<<" "<<en<<" "<<pos<<endl;
		if(i+1<s.size()&&s[i]==s[i+1])
		{
			int be=i,e=i+1;
			while(be>=0&&e<s.size()&&s[be]==s[e])
			{
				be--,e++;
			}
			int tt=0,cnt=i,pp=i-be,ppp=e-i;
			while((i-pp>=0&&s[i-pp]==s[cnt])||(i+ppp<s.size()&&s[i+ppp]==s[cnt]))
			{
				pp++,ppp++;
				tt++;
			}
			minn=min(minn,get_num(e-be-1,tt));
//			if(e-be-1>maxx)
//			{
//				maxx=e-be-1;
//				beg=be+1;
//				en=e-1;
//				pos=tt;
//			}
//			else if(e-be-1==maxx)
//			{
//				if(tt>pos)
//				{
//					pos=tt;
//					beg=be+1;
//					en=e-1;
//				}
//			}
//			if(e-be-1+tt*2>maxx1)
//			{
//				maxx1=e-be-1+tt*2;
//				pos1=tt;
//			}
//			else if(e-be-1+tt*2==maxx1)
//			{
//				if(tt<pos1)
//				{
//					pos1=tt;
//				}
//			}
		}
	}
//	cout<<maxx<<" "<<beg<<" "<<en<<" "<<pos<<endl;
//	if(maxx>=k)
//	{
//		puts("0");
//	}
//	else if(k<=maxx+2*pos)
//	{
//		printf("%d\n",(k-maxx+1)/2);
//	}
//	else
//	{
//		printf("%d\n",pos+(k-maxx-pos*2));
//	}
	cout<<minn;
	return 0;
}