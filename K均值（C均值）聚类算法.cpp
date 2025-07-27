#include <bits/stdc++.h>
using namespace std;
#define N 4
struct Mode
{
	float x1;
	float x2;
};


typedef vector<vector<Mode> > ModeVec;
int Minindex(vector<float> d);
float GetDistance(Mode d1,Mode d2);
Mode Core(vector<Mode> p);   
bool IsEqual(Mode p[],Mode q[],int n);
float Clustering(Mode p[],int Number); 
 
 
//主函数
int main()
{	
	Mode p[24];
	int i;
	for(i=0;i<24;i++)
	{
        cin>>p[i].x1>>p[i].x2;
	}
	 for(i=1;i<N;i++)
	 {
		cout<<i<<"  "<<Clustering(p,i)<<endl;
	 }
 }
 
//聚类函数
float Clustering(Mode p[],int Number)
{
	int i;
	ModeVec groupM;
	vector<float> Dis;
	for(i=0;i<Number;i++)
	{
	  vector<Mode>p1;
	  groupM.push_back(p1);
	}
	Mode c[N];
	Mode nc[N];
	for(i=0;i<Number;i++)
	{
	   c[i]=p[i];
	   nc[i]=p[i];
	}
 
   for(i=0;i<20;i++)
   {
		int j;
		Dis.clear();
		for(j=0;j<Number;j++)
		   Dis.push_back(GetDistance(p[i],c[j]));
		int k=Minindex(Dis);
		   groupM.at(k).push_back(p[i]);
	}
    
	for(i=0;i<Number;i++)
	{
		c[i]=Core(groupM.at(i));
	}
 
	int flag=1;
	while(flag)
	{
		for(i=0;i<Number;i++)
		{
			groupM.at(i).clear();
		}
 
		for(i=0;i<20;i++)
		{
			int j;
			Dis.clear();
			for(j=0;j<Number;j++)
				Dis.push_back(GetDistance(p[i],c[j]));
 
			int k=Minindex(Dis);
			groupM.at(k).push_back(p[i]);
		}
		for(i=0;i<Number;i++)
		{
		   nc[i]=Core(groupM.at(i));
		}
		if(IsEqual(c,nc,Number))
		{
			flag=0;
		}
		else
		{
			for(i=0;i<Number;i++)
			{
				c[i]=nc[i];
			}
		}
	}
	
   vector<Mode>::iterator it;
   float sum=0;
   cout<<"*******************分类数为"<<Number<<"******************:"<<endl;
   for(i=0;i<Number;i++)
   { 
	    cout<<"中心点"<<i+1<<":"<<c[i].x1<<"  "<<c[i].x2<<endl;
	    cout<<i+1<<"类:"<<endl;
	    for (it = groupM.at(i).begin(); it != groupM.at(i).end(); ++it ) 
		{
           cout<<(*it).x1<<" "<<(*it).x2<<endl;
		   sum+=GetDistance((*it),c[i]);
		}
   }
   return sum;
}
 
//返回欧式距离
float GetDistance(Mode m1,Mode m2)
{
    return sqrt((m1.x1-m2.x1)*(m1.x1-m2.x1)+(m1.x2-m2.x2)*(m1.x2-m2.x2));
}
 
//返回每个聚类的中心
Mode Core(vector<Mode> m)
{
	Mode core;
	float sum1=0,sum2=0;
	vector<Mode>::iterator it;
	for ( it = m.begin(); it != m.end(); ++it ) 
	{
          sum1+=(*it).x1;
		  sum2+=(*it).x2;
	}
	core.x1=sum1/m.size();
    core.x2=sum2/m.size();
	return core;
}
//返回属于哪个分类的索引
int Minindex(vector<float> d)
{
	float min=d.at(0);
	int i;
	int index=0;
	for(i=0;i<d.size();i++)
	{
        if(d.at(i)<min)
		{
		    min=d.at(i);
			index=i;
		}
	}
	return index;
}
//判断p,q前n个元素是否相等
bool IsEqual(Mode p[],Mode q[],int n)
{
   int i;
   for(i=0;i<n;i++)
   {
	   if(p[i].x1!=q[i].x1||p[i].x2!=q[i].x2)
		   return false;
   }
   return true;
}
 
