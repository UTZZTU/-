#include <bits/stdc++.h>
using namespace std;
int n,pcnt;  //��������  ������ 
struct base_root
{
	int Property_count;  //�������� 
	int *Property_num;  //ÿ�����Ե�ȡֵ���� 
	string *Property_full_name;   //ÿ�����Ե����� 
	vector<string*> Property_child_name;  //ÿ�����Բ�ͬȡֵ������ 
	int Result_count;  //���������� 
	string *Result_full_name;    //��ͬ��������� 
}base_root;
struct node  //������� 
{
	map<string,string> mp;
	string result;
	int pos;
};
void test()  //���Զ����Ƿ����� 
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
double Get_Ent(vector<node> vec)   //���Ent��ֵ 
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
bool check(vector<node> vec,map<string,bool> mp)   //��� ���vector������������Ƿ�һ�� 
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
double Get_Sum(int num,string s,vector<node> vec,int pos) //��ð������Խ��л��ֺ󣬵õ�����Ӧֵ�Ƕ��� 
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
string Get_Optimal_Attribute(vector<node> vec,map<string,bool> mp,double Ent) //��ȡ���Ż������� 
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
void dfs(vector<node> vec,map<string,bool> mp,double ent,vector<pair<string,string> >message)  //���н������Ѵ��� 
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
		printf("�ýڵ�ĸ���������Ϣ���£�\n");
		for(int j=0;j<message.size();j++)
		{
			cout<<message[j].first<<" "<<message[j].second<<endl;
		} 
		printf("�����Ϊ��%d  ",pcnt++);
		cout<<"������Ϊ��"<<vec[0].result<<"  �������Ϊ��";
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
		printf("�ýڵ�ĸ���������Ϣ���£�\n");
		for(int j=0;j<message.size();j++)
		{
			cout<<message[j].first<<" "<<message[j].second<<endl;
		}
		printf("�����Ϊ��%d ",pcnt++);
		cout<<"������Ϊ��"<<base_root.Result_full_name[ppos]<<"  �������Ϊ��";
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
	printf("����������ݼ�������������\n");
	scanf("%d",&base_root.Property_count);
	base_root.Property_num = new int[base_root.Property_count+1];
	base_root.Property_full_name = new string[base_root.Property_count+1];
	for(int i=1;i<=base_root.Property_count;i++)
	{
		printf("�������%d�����Ե����ƣ�\n",i);
		cin>>base_root.Property_full_name[i];
	}
	string *zero;
	base_root.Property_child_name.push_back(zero);
	for(int i=1;i<=base_root.Property_count;i++)
	{
		printf("�������%d�����Ե�ȡֵ������\n",i);
		scanf("%d",&base_root.Property_num[i]);
		string *result_name = new string[base_root.Property_num[i]+1];
		for(int j=1;j<=base_root.Property_num[i];j++)
		{
			printf("�������%d��ȡֵ�����ƣ�\n",j);
			cin>>result_name[j];
		}
		base_root.Property_child_name.push_back(result_name);
	}
	printf("�������������������\n");
	scanf("%d",&base_root.Result_count);
	base_root.Result_full_name = new string[base_root.Result_count+1];
	for(int i=1;i<=base_root.Result_count;i++)
	{
		printf("�������%d����������ƣ�\n",i);
		cin>>base_root.Result_full_name[i];
	}
//	test();
    printf("��������������Ŀ��\n");
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		map<string,string> mp;
		string s;
		for(int j=1;j<=base_root.Property_count;j++)
		{
			printf("�������%d�������ĵ�%d�����Ե�ȡֵ:\n",i,j);
			cin>>s;
			mp[base_root.Property_full_name[j]]=s;
		}
		printf("������������ķ�����:\n");
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
ɫ�� ���� ���� ���� �겿 ����
3
���� �ں� ǳ��
3
���� ���� Ӳͦ
3
���� ���� ���
3
���� �Ժ� ģ��
3
���� �԰� ƽ̹
2
Ӳ�� ��ճ
2
�� ��
17
���� ���� ���� ���� ���� Ӳ�� ��
�ں� ���� ���� ���� ���� Ӳ�� ��
�ں� ���� ���� ���� ���� Ӳ�� ��
���� ���� ���� ���� ���� Ӳ�� ��
ǳ�� ���� ���� ���� ���� Ӳ�� ��
���� ���� ���� ���� �԰� ��ճ ��
�ں� ���� ���� �Ժ� �԰� ��ճ ��
�ں� ���� ���� ���� �԰� Ӳ�� ��
�ں� ���� ���� �Ժ� �԰� Ӳ�� ��
���� Ӳͦ ��� ���� ƽ̹ ��ճ ��
ǳ�� Ӳͦ ��� ģ�� ƽ̹ Ӳ�� ��
ǳ�� ���� ���� ģ�� ƽ̹ ��ճ ��
���� ���� ���� �Ժ� ���� Ӳ�� ��
ǳ�� ���� ���� �Ժ� ���� Ӳ�� ��
�ں� ���� ���� ���� �԰� ��ճ ��
ǳ�� ���� ���� ģ�� ƽ̹ Ӳ�� ��
���� ���� ���� �Ժ� �԰� Ӳ�� �� 
*/
