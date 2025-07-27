#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
#define PI acos(-1)
#define pi pair<int,int>
#define vs vector<string>
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
typedef long long ll;
int n,m,k,num,t;  //训练数据的个数,属性种类,读入数据,分类总数,测试总数 
string u;  //读入的属性取值 
vi isDouble;  //该属性是否为double类型 
vs propertyAll[N];  //每一个训练数据的各个属性的取值 
vs resultAll;     //分类结果的所有种类 
vs resultName;   //每一个训练数据的最终分类结果 
vs targetAttribute;  //待测试的样本属性取值 
double Mean(int pos,string s)  //计算均值 
{
	double sum=0;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		if(resultName[i]==s)
		{
			num++;
			sum+=(double)stod(propertyAll[i][pos]);
		}
	}
	if(num==0) return 0;
	return (double)sum*1.0/num;
}
double Variance(int pos,string s,double mean) //计算方差 
{
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		if(resultName[i]==s)
		{
			double x=stod(propertyAll[i][pos]);
			sum+=(double)(x-mean)*(x-mean);
		}
	}
	return sum;
}
double Solve1(int pos,string s)  //处理属性值为浮点数的情况 
{
	double mean=Mean(pos,s);
	double variance=Variance(pos,s,mean);
	double x=(double)stod(targetAttribute[pos]);
	if(variance==0||mean==0) return (double)1;
	return (double)1.0/(sqrt(2.0*PI)*variance)*exp(-(x-mean)*(x-mean)/(2.0*variance*variance));
}
double Solve2(int pos,string s)  //处理属性值为字符串的情况
{
	int num1=0,num2=0;
	for(int i=1;i<=n;i++)
	{
		if(resultName[i]==s)
		{
			num2++;
			if(targetAttribute[pos]==propertyAll[i][pos]) num1++;
		}
	}
	if(num2==0||num1==0) return (double)0;
	else return (double)num1*1.0/num2;
}
void Solve()  //处理函数 
{
	double bys,maxx=0,pos=1;
	targetAttribute.clear();
	targetAttribute.pb("begin");
	for(int i=1;i<=m;i++)
	{
		cout<<"请输入测试样本的第"<<i<<"个属性取值："<<endl;
		cin>>u;
		targetAttribute.pb(u); 
	}
	for(int i=1;i<=num;i++)
	{
		bys=1;
		u=resultAll[i];
		for(int j=1;j<=m;j++)
		{
			if(isDouble[j])
			{
				bys*=Solve1(j,u);
			}
			else
			{
				bys*=Solve2(j,u);
			}
		}
		if(bys>maxx)
		{
			maxx=bys;
			pos=i;
		}
	}
	cout<<"---------------------------"<<endl;
	cout<<endl;
	cout<<"经过计算，最大概率为："<<maxx<<endl;
	cout<<endl;
	cout<<"所以，该测试样本的最佳预测结果为："<<resultAll[pos]<<endl;
	cout<<endl;
	cout<<"---------------------------"<<endl<<endl;
}
int main ()
{
	cout<<"请输入训练数据的个数："<<endl;
	cin>>n;
	cout<<"请输入训练数据的属性维数："<<endl;
	cin>>m;
	isDouble.pb(-1);
	resultName.pb("begin");
	resultAll.pb("begin");
	for(int i=1;i<=m;i++)
	{
		cout<<"请输入第"<<i<<"维数据是否为浮点数：（0表示不是，1表示是）"<<endl;
		cin>>k;
		isDouble.pb(k);
	} 
	for(int i=1;i<=n;i++)
	{
		propertyAll[i].pb("begin");
		for(int j=1;j<=m;j++)
		{
			cout<<"请输入第"<<i<<"个训练数据的第"<<j<<"维属性的取值："<<endl;
			cin>>u;
			propertyAll[i].pb(u);
		}
		cout<<"请输入第"<<i<<"个训练数据的分类结果为："<<endl;
		cin>>u;
		resultName.pb(u);
	}
	cout<<"请输入分类结果的种类数："<<endl;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cout<<"请输入第"<<i<<"种分类结果的取值："<<endl;
		cin>>u;
		resultAll.pb(u);
	}
	cout<<"请输入要测试的样本数目："<<endl;
	cin>>t;
	while(t--)
	{
		Solve();
	}
	return 0;
}
/*
17
8
0 0 0 0 0 0 1 1
青绿 蜷缩 浊响 清晰 凹陷 硬滑 0.697 0.460 是
乌黑 蜷缩 沉闷 清晰 凹陷 硬滑 0.774 0.376 是
乌黑 蜷缩 浊响 清晰 凹陷 硬滑 0.634 0.264 是
青绿 蜷缩 沉闷 清晰 凹陷 硬滑 0.608 0.318 是
浅白 蜷缩 浊响 清晰 凹陷 硬滑 0.556 0.215 是
青绿 稍蜷 浊响 清晰 稍凹 软粘 0.403 0.237 是
乌黑 稍蜷 浊响 稍糊 稍凹 软粘 0.481 0.149 是
乌黑 稍蜷 浊响 清晰 稍凹 硬滑 0.437 0.211 是
乌黑 稍蜷 沉闷 稍糊 稍凹 硬滑 0.666 0.091 否
青绿 硬挺 清脆 清晰 平坦 软粘 0.243 0.267 否
浅白 硬挺 清脆 模糊 平坦 硬滑 0.245 0.057 否
浅白 蜷缩 浊响 模糊 平坦 软粘 0.343 0.099 否
青绿 稍蜷 浊响 稍糊 凹陷 硬滑 0.639 0.161 否
浅白 稍蜷 沉闷 稍糊 凹陷 硬滑 0.657 0.198 否
乌黑 稍蜷 浊响 清晰 稍凹 软粘 0.360 0.370 否
浅白 蜷缩 浊响 模糊 平坦 硬滑 0.593 0.042 否
青绿 蜷缩 沉闷 稍糊 稍凹 硬滑 0.719 0.103 否
2
是 否
1
青绿 蜷缩 浊响 清晰 凹陷 硬滑 0.697 0.460 
*/
