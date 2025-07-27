#include <bits/stdc++.h>
using namespace std;
int n,pcnt;  //样本个数  总条数 
struct base_root
{
	int Property_count;  //属性总数 
	int *Property_num;  //每个属性的取值个数 
	string *Property_full_name;   //每个属性的名称 
	vector<string*> Property_child_name;  //每个属性不同取值的名称 
	int Result_count;  //分类结果总数 
	string *Result_full_name;    //不同分类的名字 
}base_root;
struct node  //样本结点 
{
	map<string,string> mp;
	string result;
	int pos;
};
void test()  //测试读入是否正常 
{
	for(int i=1;i<=base_root.Property_count;i++)
	{
		cout<<base_root.Property_num[i]<<" "<<base_root.Property_full_name[i]<<endl;
	}
	for(int i=1;i<=base_root.Property_count;i++)
	{
		for(int j=1;j<=base_root.Property_num[i];j++)
		{
			cout<<base_root.Property_child_name[i][j]<<endl;
		}
	}
	for(int i=1;i<=base_root.Result_count;i++)
	{
		cout<<base_root.Result_full_name[i]<<endl;
	}
}
vector<node> vec; 
double Get_Ent(vector<node> vec)   //获得Ent的值 
{
	int total=vec.size();
	double ent=0;
	int *cnt=new int[base_root.Result_count+1];
	for(int i=1;i<=base_root.Result_count;i++)
	{
		cnt[i]=0;
	}
	for(int i=0;i<total;i++)
	{
		for(int j=1;j<=base_root.Result_count;j++)
		{
			if(vec[i].result==base_root.Result_full_name[j])
			{
				cnt[j]++;
				break;
			}
		}
	}
	for(int i=1;i<=base_root.Result_count;i++)
	{
		if(cnt[i])
		{
//			cout<<cnt[i]<<endl;
			ent+=(cnt[i]*1.0/total)*(log(cnt[i]*1.0/total)*1.0/log(2));
		}
	}
	return -ent;
}
bool check(vector<node> vec,map<string,bool> mp)   //检查 这个vector里的样本属性是否都一样 
{
	for(int i=1;i<=base_root.Property_count;i++)
	{
		string u=base_root.Property_full_name[i];
		if(mp[u]) continue;
		for(int j=1;j<vec.size();j++)
		{
			if(vec[j].mp[u]!=vec[j-1].mp[u])
			{
				return false;
			}
		}
	}
	return true;
}
double Get_Sum(int num,string s,vector<node> vec,int pos) //求得按该属性进行划分后，得到的相应值是多少 
{
	double sum=0;
	for(int i=1;i<=base_root.Property_num[pos];i++)
	{
		vector<node> v;
		for(int j=0;j<vec.size();j++)
		{
			if(vec[j].mp[s]==base_root.Property_child_name[pos][i])
			{
				v.push_back(vec[j]);
			}
		}
		if(v.size())
		{
			sum+=((int)v.size()*1.0/num)*(Get_Ent(v));
		}
	}
	return sum;
}
string Get_Optimal_Attribute(vector<node> vec,map<string,bool> mp,double Ent) //获取最优划分属性 
{
	double maxx=0;
	int pos=-1;
	for(int i=1;i<=base_root.Property_count;i++)
	{
		string u=base_root.Property_full_name[i];
		if(mp[u]) continue;
		double rp=Ent-Get_Sum((int)vec.size(),u,vec,i);
		if(rp>maxx)
		{
			maxx=rp;
			pos=i;
		}
	}
	return base_root.Property_full_name[pos];
}
void dfs(vector<node> vec,map<string,bool> mp,double ent,vector<pair<string,string> >message)  //进行建树深搜处理 
{
	int i=1;
	for(i;i<vec.size();i++)
	{
		if(vec[i].result!=vec[i-1].result)
		{
			break;
		}
	}
	if(i==vec.size())
	{
		printf("该节点的各种属性信息如下：\n");
		for(int j=0;j<message.size();j++)
		{
			cout<<message[j].first<<" "<<message[j].second<<endl;
		} 
		printf("结点编号为：%d  ",pcnt++);
		cout<<"分类结果为："<<vec[0].result<<"  样本编号为：";
		for(int j=0;j<vec.size();j++)
		{
			cout<<vec[j].pos<<" ";
		}
		cout<<endl<<endl<<endl;
		return;
	}
	if(check(vec,mp))
	{
		int *cnt=new int[base_root.Result_count+1];
		for(int i=1;i<=base_root.Result_count;i++)
		{
			cnt[i]=0;
		}
		for(int i=0;i<vec.size();i++)
		{
			for(int j=1;j<=base_root.Result_count;j++)
			{
				if(vec[i].result==base_root.Result_full_name[j])
				{
					cnt[j]++;
					break;
				}
			}
		}
		int maxx=0,ppos=-1;
		for(int i=1;i<=base_root.Result_count;i++)
		{
			if(cnt[i]>maxx)
			{
				maxx=cnt[i];
				ppos=i;
			}
		}
		printf("该节点的各种属性信息如下：\n");
		for(int j=0;j<message.size();j++)
		{
			cout<<message[j].first<<" "<<message[j].second<<endl;
		}
		printf("结点编号为：%d ",pcnt++);
		cout<<"分类结果为："<<base_root.Result_full_name[ppos]<<"  样本编号为：";
		for(int j=0;j<vec.size();j++)
		{
			cout<<vec[j].pos<<" ";
		}
		cout<<endl<<endl<<endl;
		return;
	}
	else
	{
		string rib=Get_Optimal_Attribute(vec,mp,ent);
		mp[rib]=true;
		int i=1;
		for(i;i<base_root.Property_count;i++)
		{
			if(base_root.Property_full_name[i]==rib)
			{
				break;
			}
		}
		for(int j=1;j<=base_root.Property_num[i];j++)
		{
			vector<node> v;
			for(int k=0;k<vec.size();k++)
			{
				if(vec[k].mp[rib]==base_root.Property_child_name[i][j])
				{
					v.push_back(vec[k]);
				}
			}
			if(v.size())
			{
				message.push_back({rib,base_root.Property_child_name[i][j]});
				dfs(v,mp,Get_Ent(v),message);
				message.pop_back();
			}
		}
	}
}
int main ()
{
	printf("请输入该数据集的属性总数：\n");
	scanf("%d",&base_root.Property_count);
	base_root.Property_num = new int[base_root.Property_count+1];
	base_root.Property_full_name = new string[base_root.Property_count+1];
	for(int i=1;i<=base_root.Property_count;i++)
	{
		printf("请输入第%d个属性的名称：\n",i);
		cin>>base_root.Property_full_name[i];
	}
	string *zero;
	base_root.Property_child_name.push_back(zero);
	for(int i=1;i<=base_root.Property_count;i++)
	{
		printf("请输入第%d个属性的取值个数：\n",i);
		scanf("%d",&base_root.Property_num[i]);
		string *result_name = new string[base_root.Property_num[i]+1];
		for(int j=1;j<=base_root.Property_num[i];j++)
		{
			printf("请输入第%d个取值的名称：\n",j);
			cin>>result_name[j];
		}
		base_root.Property_child_name.push_back(result_name);
	}
	printf("请输入结果的种类个数：\n");
	scanf("%d",&base_root.Result_count);
	base_root.Result_full_name = new string[base_root.Result_count+1];
	for(int i=1;i<=base_root.Result_count;i++)
	{
		printf("请输入第%d个结果的名称：\n",i);
		cin>>base_root.Result_full_name[i];
	}
//	test();
    printf("请输入样本的数目：\n");
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		map<string,string> mp;
		string s;
		for(int j=1;j<=base_root.Property_count;j++)
		{
			printf("请输入第%d个样本的第%d个属性的取值:\n",i,j);
			cin>>s;
			mp[base_root.Property_full_name[j]]=s;
		}
		printf("请输入该样本的分类标记:\n");
		cin>>s;
		vec.push_back({mp,s,i}); 
	}
	printf("\n\n\n");
	printf("-------------------------------\n");
	printf("-------------------------------\n");
	printf("-------------------------------\n");
	printf("\n\n\n");
	vector<pair<string,string> >message;
	map<string,bool> temp;
	dfs(vec,temp,Get_Ent(vec),message);
//	cout<<Get_Ent(vec);
	return 0;
}
/*
6
色泽 根蒂 敲声 纹理 脐部 触感
3
青绿 乌黑 浅白
3
蜷缩 稍蜷 硬挺
3
浊响 沉闷 清脆
3
清晰 稍糊 模糊
3
凹陷 稍凹 平坦
2
硬滑 软粘
2
是 否
17
青绿 蜷缩 浊响 清晰 凹陷 硬滑 是
乌黑 蜷缩 沉闷 清晰 凹陷 硬滑 是
乌黑 蜷缩 浊响 清晰 凹陷 硬滑 是
青绿 蜷缩 沉闷 清晰 凹陷 硬滑 是
浅白 蜷缩 浊响 清晰 凹陷 硬滑 是
青绿 稍蜷 浊响 清晰 稍凹 软粘 是
乌黑 稍蜷 浊响 稍糊 稍凹 软粘 是
乌黑 稍蜷 浊响 清晰 稍凹 硬滑 是
乌黑 稍蜷 沉闷 稍糊 稍凹 硬滑 否
青绿 硬挺 清脆 清晰 平坦 软粘 否
浅白 硬挺 清脆 模糊 平坦 硬滑 否
浅白 蜷缩 浊响 模糊 平坦 软粘 否
青绿 稍蜷 浊响 稍糊 凹陷 硬滑 否
浅白 稍蜷 沉闷 稍糊 凹陷 硬滑 否
乌黑 稍蜷 浊响 清晰 稍凹 软粘 否
浅白 蜷缩 浊响 模糊 平坦 硬滑 否
青绿 蜷缩 沉闷 稍糊 稍凹 硬滑 否 
*/
