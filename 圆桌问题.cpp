#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int a[70000],n,m,cnt;
vector<int> v;//默认初始化，a为空
int main()
{
	while(cin>>n>>m)
	{
		v.clear();
		cnt=0;
		memset(a,0,sizeof(a));//memset函数：第一个参数为数组名称，即为首地址；第二个参数为0//-1//单个字符；第三个参数为改变的数组的大小
		for(int i=1;i<=2*n;i++)
			v.push_back(i);//利用了vector的赋值功能，在尾部添加元素
		while(v.size()>n)
		{

			cnt=(cnt+m-1)%v.size();//取余循环
			v.erase(v.begin ()+cnt);
		}
		vector<int>::iterator it;
		for(it=v.begin();it!=v.end();it++)
			a[*it]=1;
		for(int i=1;i<=2*n;i++)
		{
			if((i-1)%50==0&&i>1)//根据题目要求，五十个字母为一行
				cout<<endl;
			if(a[i])//a非零时，执行下一步
				cout<<"G";//为好人
			else cout<<"B";
		}
		cout<<endl;
		cout<<endl;
	}
	return 0;
}
