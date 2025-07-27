#include<iostream>
#include<cstdio>
using namespace std;
int f[3][3][1003];
int main()
{
	int n;
	char ch1,ch2,ch3,ch4;
	
	//下面单独读入第一组数据，因为第一组数据上面没有星号
	cin>>n;
	cin>>ch1>>ch2;
	cin>>ch3>>ch4;
	f[1][1][1]=ch1-'0'; // char 转 int 存入
	f[1][2][1]=ch2-'0';
	f[2][1][1]=ch3-'0';
	f[2][2][1]=ch4-'0';
	
	int k=1; // k 代表不同的牌的张数 
	for(int i=2;i<=n;++i) // 从第2张牌继续读入 
	{
		bool ok=0; //临时 bool 数组，用来判断两张牌是不是相同的 
		char x;
		cin>>x>>x;
		cin>>ch1>>ch2;
		cin>>ch3>>ch4;
		int a=ch1-'0';
		int b=ch2-'0';
		int c=ch3-'0';
		int d=ch4-'0';
		
		for(int j=1;j<=k;++j) //在每张不同的牌之间枚举，看看此牌和之前的牌是不是相同 
		{
			if(a==f[1][1][j] && b==f[1][2][j] && c==f[2][1][j] && d==f[2][2][j])
			{
				ok=1; //完全相同的情况
				break;//如果和之前的牌相同，则可以跳出循环，继续读入下一组数据
			}
			if(c==f[1][1][j] && a==f[1][2][j] && d==f[2][1][j] && b==f[2][2][j])
			{
				ok=1; //顺时针旋转90度
				break;//同上
			}
			if(d==f[1][1][j] && c==f[1][2][j] && b==f[2][1][j] && a==f[2][2][j])
			{
				ok=1;//顺时针旋转180度
				break;//同上
			}
			if(b==f[1][1][j] && d==f[1][2][j] && a==f[2][1][j] && c==f[2][2][j])
			{
				ok=1;//顺时针旋转270度
				break;//同上
			}
		}
		if(ok==0) //如果这张牌和前面的各不相同，那么把这张牌存入 f 数组 
		{
			f[1][1][++k]=ch1-'0';
			f[1][2][k]=ch2-'0';
			f[2][1][k]=ch3-'0';
			f[2][2][k]=ch4-'0';
		}
	}
	printf("%d\n",k); //最后输出不同的牌的张数 
}
