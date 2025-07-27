#include <iostream>
#include <string>
using namespace std;
const int N = 200010;
int son[N][26], cnt[N], idx,n;
string u[N];
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(string str)
{
    int p = 0;
    for (int i = 0; i<str.size(); i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(string str)
{
    int p = 0;
    for (int i = 0; i<str.size(); i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u[i];
		insert(u[i]);
	}
	for(int i=1;i<=n;i++)
	{
		string v;
		int res=0;
		for(int j=0;j<u[i].size();i++)
		{
			v+=u[i][j];
			if(query(v))
			{
				res++;
			}
			else
			break;
		}
		cout<<res<<endl;
	}
	return 0;
}