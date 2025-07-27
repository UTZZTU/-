#include <bits/stdc++.h>
using namespace std;
#define startblock 10
#define starttime 5
#define time tt
int n;       //进程个数 
int time=0;  //外界总时间 
int pos=1;   //当前处理到的进程位置 
int cc=0;    //后面的累加次数 
struct PCB
{
	int ID;
	int Priority;
	int ArrivalTime;
	int AllTime;
	int CPUTime;
	int StartBlock;
	int StartTime;
	string State;
	int CntTime;
//	inline bool operator<(const PCB &x)const
//	{
//		if(Priority!=x.Priority)
//		return Priority>x.Priority;
//		else return ArrivalTime<x.ArrivalTime;
//	}
};
bool cmp1(PCB x,PCB y)
{
	return x.ArrivalTime<y.ArrivalTime;
}
bool cmp2(PCB x,PCB y)
{
	if(x.Priority!=y.Priority)
	return x.Priority>y.Priority;
	else return x.ArrivalTime<y.ArrivalTime;
}
deque<PCB> q;
vector<PCB> block;
int check()
{
	int flag=0;
	for(int i=0;i<block.size();i++)
	{
		block[i].CntTime++;
		if(block[i].CntTime==block[i].StartTime)
		{
			flag=1;
		}
	}
	return flag;
}
int main ()
{
	cout<<"请输入进程的个数："<<endl;
	cin>>n;
	PCB* pcb = new PCB[n+1];
	for(int i=1;i<=n;i++)
	{
		cout<<"请输入第"<<i<<"号"<<"的优先数、到达时间和运行时间（按顺序输入）:"<<endl;
		scanf("%d%d%d",&pcb[i].Priority,&pcb[i].ArrivalTime,&pcb[i].AllTime);
		pcb[i].CPUTime=0;
		pcb[i].ID=i;
		pcb[i].StartBlock=startblock;
		pcb[i].StartTime=starttime;
		pcb[i].State="Ready";
		pcb[i].CntTime=0;
	}
	if(n==0)
	{
		printf("这里没有进程！！！");
		return 0;
	}
	sort(pcb+1,pcb+1+n,cmp1);
	int first_arrive_time=pcb[1].ArrivalTime;
	while(pos<=n&&pcb[pos].ArrivalTime==first_arrive_time)
	{
		q.push_back(pcb[pos++]);
	}
	time=pcb[1].ArrivalTime;
	while(1)
	{
		cc=0;
		if(q.size()==0)
		{
			if(block.size())
			{
				for(int i=0;i<block.size();i++)
				{
					block[i].CntTime=0;
				}
				sort(block.begin(),block.end(),cmp2);
				for(int i=0;i<block.size();i++)
				{
					q.push_back(block[i]);
				}
				block.clear();
			}
			else if(pos<=n)
			{
				time=pcb[pos].ArrivalTime;
				while(pos<=n&&pcb[pos].ArrivalTime==time)
				{
					q.push_back(pcb[pos++]);
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			vector<PCB> temp;
			while(q.size())
			{
				auto u=q.front();
//				cout<<u.ID<<" "<<time<<endl;
				q.pop_front();
				u.CPUTime++;
				u.CntTime++;
				time++;
				if(u.CPUTime==u.AllTime)
				{
					printf("编号为 %d 的进程，运行结束的时间为 %d\n",u.ID,time,u.Priority);
				}
				else
				{
					u.Priority+=cc-3;
					if(u.CntTime==u.StartBlock)
					{
						u.CntTime=0;
						block.push_back(u);
					}
					else
					{
						temp.push_back(u);
					}
				}
				cc++;
				int flag1=0,flag2=0;
				flag1=check();
				if(pos<=n&&pcb[pos].ArrivalTime==time)
				{
					flag2=1;
				}
				if(flag1||flag2)
				{
					break;
				}
			}
			while(q.size())
			{
				auto u=q.front();
				q.pop_front();
				u.Priority+=cc;
				temp.push_back(u);
			}
			vector<PCB> v;
			for(int i=0;i<block.size();i++)
			{
				if(block[i].CntTime==block[i].StartTime)
				{
					block[i].CntTime=0;
					temp.push_back(block[i]);
				}
				else v.push_back(block[i]);
			}
			block=v;
			while(pos<=n&&pcb[pos].ArrivalTime==time)
			{
				temp.push_back(pcb[pos++]);
			}
			sort(temp.begin(),temp.end(),cmp2);
			for(int i=0;i<temp.size();i++)
			{
				q.push_back(temp[i]);
			}
//			temp.clear();
		}
		
	}
	return 0;
}
