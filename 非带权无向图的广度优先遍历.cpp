/*
	功能：实现非带权无向图的广度优先遍历 
	输入：该图的各种信息 
	输出：该图的广度优先遍历 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年11月27日

	参考文献：殷人昆《数据结构(用面向对象方法与C++语言描述)(第3版)》,
	版次：2021年9月第3版
	印次：2022年6月第2次印刷
	页码：PP282-300
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
vector<int> vec[30];  //邻接表 
map<int,char> mp1; 
map<char,int> mp2;
int m,n,vis[30];     //判重数组 
string u,v[100010];
char x;
int main ()
{
	cin>>m>>n;
	getchar();
	cin>>u;
	for(int i=0;i<u.size();i++)  //进行字母和数字的相互标记 
	{
		mp1[i]=u[i];
		mp2[u[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	cin>>x;
	sort(v+1,v+1+n);             //排序 
	for(int i=1;i<=n;i++)
	{
		vec[mp2[v[i][0]]].push_back(mp2[v[i][1]]);  //从前往后加 
	}
	for(int i=n;i>=1;i--)
	{
		vec[mp2[v[i][1]]].push_back(mp2[v[i][0]]);  //从后往前加 
	}
	for(int i=0;i<u.size();i++)                     //邻接表输出 
	{
		cout<<i<<" "<<mp1[i];
		for(int j=0;j<vec[i].size();j++)
		{
			cout<<"-->"<<vec[i][j];
		}
		cout<<endl;
	}
//	queue<int> q;                                  //往下为广度优先遍历 
//	q.push(mp2[x]);
//	while(!q.empty())
//	{
//		int k=q.front();
//		q.pop();
//		if(vis[k])
//		continue;
//		vis[k]=1;
//		cout<<mp1[k]<<" ";
//		for(int i=0;i<vec[k].size();i++)
//		{
//			q.push(vec[k][i]);
//		}
//	}
	return 0;
}
