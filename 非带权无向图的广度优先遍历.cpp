/*
	���ܣ�ʵ�ַǴ�Ȩ����ͼ�Ĺ�����ȱ��� 
	���룺��ͼ�ĸ�����Ϣ 
	�������ͼ�Ĺ�����ȱ��� 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��11��27��

	�ο����ף������������ݽṹ(��������󷽷���C++��������)(��3��)��,
	��Σ�2021��9�µ�3��
	ӡ�Σ�2022��6�µ�2��ӡˢ
	ҳ�룺PP282-300
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
vector<int> vec[30];  //�ڽӱ� 
map<int,char> mp1; 
map<char,int> mp2;
int m,n,vis[30];     //�������� 
string u,v[100010];
char x;
int main ()
{
	cin>>m>>n;
	getchar();
	cin>>u;
	for(int i=0;i<u.size();i++)  //������ĸ�����ֵ��໥��� 
	{
		mp1[i]=u[i];
		mp2[u[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	cin>>x;
	sort(v+1,v+1+n);             //���� 
	for(int i=1;i<=n;i++)
	{
		vec[mp2[v[i][0]]].push_back(mp2[v[i][1]]);  //��ǰ����� 
	}
	for(int i=n;i>=1;i--)
	{
		vec[mp2[v[i][1]]].push_back(mp2[v[i][0]]);  //�Ӻ���ǰ�� 
	}
	for(int i=0;i<u.size();i++)                     //�ڽӱ���� 
	{
		cout<<i<<" "<<mp1[i];
		for(int j=0;j<vec[i].size();j++)
		{
			cout<<"-->"<<vec[i][j];
		}
		cout<<endl;
	}
//	queue<int> q;                                  //����Ϊ������ȱ��� 
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
