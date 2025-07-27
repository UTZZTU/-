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
int n,m,k,num,t;  //ѵ�����ݵĸ���,��������,��������,��������,�������� 
string u;  //���������ȡֵ 
vi isDouble;  //�������Ƿ�Ϊdouble���� 
vs propertyAll[N];  //ÿһ��ѵ�����ݵĸ������Ե�ȡֵ 
vs resultAll;     //���������������� 
vs resultName;   //ÿһ��ѵ�����ݵ����շ����� 
vs targetAttribute;  //�����Ե���������ȡֵ 
double Mean(int pos,string s)  //�����ֵ 
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
double Variance(int pos,string s,double mean) //���㷽�� 
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
double Solve1(int pos,string s)  //��������ֵΪ����������� 
{
	double mean=Mean(pos,s);
	double variance=Variance(pos,s,mean);
	double x=(double)stod(targetAttribute[pos]);
	if(variance==0||mean==0) return (double)1;
	return (double)1.0/(sqrt(2.0*PI)*variance)*exp(-(x-mean)*(x-mean)/(2.0*variance*variance));
}
double Solve2(int pos,string s)  //��������ֵΪ�ַ��������
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
void Solve()  //������ 
{
	double bys,maxx=0,pos=1;
	targetAttribute.clear();
	targetAttribute.pb("begin");
	for(int i=1;i<=m;i++)
	{
		cout<<"��������������ĵ�"<<i<<"������ȡֵ��"<<endl;
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
	cout<<"�������㣬������Ϊ��"<<maxx<<endl;
	cout<<endl;
	cout<<"���ԣ��ò������������Ԥ����Ϊ��"<<resultAll[pos]<<endl;
	cout<<endl;
	cout<<"---------------------------"<<endl<<endl;
}
int main ()
{
	cout<<"������ѵ�����ݵĸ�����"<<endl;
	cin>>n;
	cout<<"������ѵ�����ݵ�����ά����"<<endl;
	cin>>m;
	isDouble.pb(-1);
	resultName.pb("begin");
	resultAll.pb("begin");
	for(int i=1;i<=m;i++)
	{
		cout<<"�������"<<i<<"ά�����Ƿ�Ϊ����������0��ʾ���ǣ�1��ʾ�ǣ�"<<endl;
		cin>>k;
		isDouble.pb(k);
	} 
	for(int i=1;i<=n;i++)
	{
		propertyAll[i].pb("begin");
		for(int j=1;j<=m;j++)
		{
			cout<<"�������"<<i<<"��ѵ�����ݵĵ�"<<j<<"ά���Ե�ȡֵ��"<<endl;
			cin>>u;
			propertyAll[i].pb(u);
		}
		cout<<"�������"<<i<<"��ѵ�����ݵķ�����Ϊ��"<<endl;
		cin>>u;
		resultName.pb(u);
	}
	cout<<"���������������������"<<endl;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cout<<"�������"<<i<<"�ַ�������ȡֵ��"<<endl;
		cin>>u;
		resultAll.pb(u);
	}
	cout<<"������Ҫ���Ե�������Ŀ��"<<endl;
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
���� ���� ���� ���� ���� Ӳ�� 0.697 0.460 ��
�ں� ���� ���� ���� ���� Ӳ�� 0.774 0.376 ��
�ں� ���� ���� ���� ���� Ӳ�� 0.634 0.264 ��
���� ���� ���� ���� ���� Ӳ�� 0.608 0.318 ��
ǳ�� ���� ���� ���� ���� Ӳ�� 0.556 0.215 ��
���� ���� ���� ���� �԰� ��ճ 0.403 0.237 ��
�ں� ���� ���� �Ժ� �԰� ��ճ 0.481 0.149 ��
�ں� ���� ���� ���� �԰� Ӳ�� 0.437 0.211 ��
�ں� ���� ���� �Ժ� �԰� Ӳ�� 0.666 0.091 ��
���� Ӳͦ ��� ���� ƽ̹ ��ճ 0.243 0.267 ��
ǳ�� Ӳͦ ��� ģ�� ƽ̹ Ӳ�� 0.245 0.057 ��
ǳ�� ���� ���� ģ�� ƽ̹ ��ճ 0.343 0.099 ��
���� ���� ���� �Ժ� ���� Ӳ�� 0.639 0.161 ��
ǳ�� ���� ���� �Ժ� ���� Ӳ�� 0.657 0.198 ��
�ں� ���� ���� ���� �԰� ��ճ 0.360 0.370 ��
ǳ�� ���� ���� ģ�� ƽ̹ Ӳ�� 0.593 0.042 ��
���� ���� ���� �Ժ� �԰� Ӳ�� 0.719 0.103 ��
2
�� ��
1
���� ���� ���� ���� ���� Ӳ�� 0.697 0.460 
*/
