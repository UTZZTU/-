#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pf push_front
#define cl clear
#define fi first
#define se second
#define bg begin
#define ed end
#define sz size
#define fd find
#define PI pair<int,int>
#define Um unordered_map
#define Mul multiset
#define VI vector<int>
#define VII vector< vector<int> > 
#define VS vector<string>
#define VN vector<node>
#define VP vector< pair<int,int> >
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
string op;   //读入的操作名称 
int Statu=-1;   //现在的状态
VI System_Generation;
VI Transformation;
VI User_Input;
VI User_Memory;
string Page_Number_str;
int Page_Number;
int n;
string N;
int Trand(int x,int y)
{
	return (rand()%(y-x+1))+x;
}
void ShowMenu()
{
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|     欢迎来到模拟请求页式存储管理算法实现页面      |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|                 你可以进行以下操作：              |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|      1.按 N/n 系统自动生成随机数进行操作展示      |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|       2.按 C/c 自定义输入数据进行个性化展示       |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|    3.按 M/m 返回主菜单页面（在非主菜单页面执行）  |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|                 4.按 E/e 退出系统                 |"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}
void SystemGenerate()
{
	while(1)
	{
		int M=Trand(0,319);
		if(M+1<=319)
		{
			System_Generation.pb(M+1);
			if(System_Generation.sz()==320) return;
		}
		M=Trand(0,M+1);
		if(M+1<=319)
		{
			System_Generation.pb(M+1);
			if(System_Generation.sz()==320) return;
		}
		if(M+2<=319)
		{
			M=Trand(M+2,319);
			if(M<=319)
			{
				System_Generation.pb(M);
				if(System_Generation.sz()==320) return;
			}
		}
	}
	return;
}
void ShowSystemGeneration()
{
	for(int i=0;i<320;i++)
	{
		if(i&&i/16!=(i-1)/16) cout<<endl;
		cout<<right<<setw(5)<<System_Generation[i]<<" ";
	}
}
void ShowTransformation()
{
	for(int i=0;i<320;i++)
	{
		if(i&&i/16!=(i-1)/16) cout<<endl;
		cout<<right<<setw(5)<<Transformation[i]<<" ";
	}
}
void init()
{
	System_Generation.cl();
	Transformation.cl();
	SystemGenerate();
	for(int i=0;i<320;i++)
	{
		Transformation.pb(System_Generation[i]/10);
	}
	cout<<"系统随机生成的指令序列："<<endl<<endl;
	ShowSystemGeneration();
	cout<<endl<<endl;
	cout<<"指令序列转化为页地址流："<<endl<<endl;
	ShowTransformation();
	cout<<endl<<endl;
}
bool IsNum(string s)
{
	if(s.sz()>5) return false;
	for(int i=0;i<s.sz();i++)
	{
		if(s[i]>='0'&&s[i]<='9') ;
		else return false;
	}
	return true;
}
int Find_OPT(int x,int i)
{
	for(i;i<Transformation.sz();i++)
	{
		if(Transformation[i]==x) return i;
	}
	return -1;
}
void OPT()
{
	User_Memory.cl();
	int Page_Faults=0,Maxx=0;
	double Page_Fault_Rate,Hit_Rate;
	VII Temp_Result;
	VP Error_Message;
	int Temp_Time[50]={0};
	for(int i=0;i<Transformation.sz();i++)
	{
		auto it=fd(User_Memory.bg(),User_Memory.ed(),Transformation[i]);
		if(it==User_Memory.ed())
		{
			Page_Faults++;
			if(User_Memory.sz()<Page_Number)
			{
				User_Memory.pb(Transformation[i]);
				Temp_Time[User_Memory.sz()-1]=i;
				Error_Message.pb({i,-1});
			}
			else
			{
				int maxx=0,pos=-1,TIME=0x3f3f3f3f;
				for(int j=0;j<User_Memory.sz();j++)
				{
					int Distance=Find_OPT(User_Memory[j],i+1);
					if(Distance==-1)
					{
						Distance=0x3f3f3f3f;
					}
					if(Distance>maxx)
					{
						maxx=Distance;
						TIME=Temp_Time[j];
						pos=j;
					}
					else if(Distance==maxx&&Temp_Time[j]<TIME)
					{
						TIME=Temp_Time[j];
						pos=j;
					}
				}
				Error_Message.pb({i,User_Memory[pos]});
				User_Memory[pos]=Transformation[i];
				Temp_Time[pos]=i;
			}
		}
		Temp_Result.pb(User_Memory);
		Maxx=max(Maxx,(int)(User_Memory.sz()));
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"缺页次数为："<<Page_Faults<<" 次"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"缺页率为："<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"命中率为："<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"置换流程图如下："<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  请求页号    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  第 "<<r<<" 块页号 ";
			for(int k=i;k<=j;k++)
			{
				if(Temp_Result[k].sz()<r)
				{
					cout<<right<<setw(5)<<U_V<<" ";
				}
				else
				{
					cout<<right<<setw(5)<<Temp_Result[k][r-1]<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"  ";
		for(int k=1;k<=70;k++) cout<<".";
		cout<<endl;
		i=j;
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"详细置换信息如下："<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"但由于此时用户内存还没有用完，故不用置换页面，直接将该页面装入即可!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"被置换的页面为："<<y<<" 号页面"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"本次分析完成!!!"<<endl<<endl;
}
int Find_LRU(VI vec)
{
	return vec[0];
}
void LRU()
{
	User_Memory.cl();
	int Page_Faults=0,Maxx=0;
	double Page_Fault_Rate,Hit_Rate;
	VII Temp_Result;
	VP Error_Message;
	VI Stack;
	for(int i=0;i<Transformation.sz();i++)
	{
		auto it=fd(Stack.bg(),Stack.ed(),Transformation[i]);
		if(it==Stack.ed())
		{
			Page_Faults++;
			if(User_Memory.sz()<Page_Number)
			{
				User_Memory.pb(Transformation[i]);
				Stack.pb(Transformation[i]);
				Error_Message.pb({i,-1});
			}
			else
			{
				int Page_Num,pos=-1;
				Page_Num=Find_LRU(Stack);
				for(int j=0;j<User_Memory.sz();j++)
				{
					if(User_Memory[j]==Page_Num)
					{
						pos=j;
						break;
					}
				}
				Error_Message.pb({i,User_Memory[pos]});
				User_Memory[pos]=Transformation[i];
				Stack.erase(Stack.begin());
				Stack.pb(Transformation[i]);
			}
		}
		else
		{
			Stack.erase(it);
			Stack.pb(Transformation[i]);
		}
		Temp_Result.pb(User_Memory);
		Maxx=max(Maxx,(int)(User_Memory.sz()));
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"缺页次数为："<<Page_Faults<<" 次"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"缺页率为："<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"命中率为："<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"置换流程图如下："<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  请求页号    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  第 "<<r<<" 块页号 ";
			for(int k=i;k<=j;k++)
			{
				if(Temp_Result[k].sz()<r)
				{
					cout<<right<<setw(5)<<U_V<<" ";
				}
				else
				{
					cout<<right<<setw(5)<<Temp_Result[k][r-1]<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"  ";
		for(int k=1;k<=60;k++) cout<<".";
		cout<<endl;
		i=j;
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"详细置换信息如下："<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"但由于此时用户内存还没有用完，故不用置换页面，直接将该页面装入即可!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"被置换的页面为："<<y<<" 号页面"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"本次分析完成!!!"<<endl<<endl;
}
void LFU()
{
	int Temp_Cnt[50]={0};
	int Page_Faults=0,Maxx=0;
	double Page_Fault_Rate,Hit_Rate;
	VII Temp_Result;
	VP Error_Message;
	VP Temp_Message;
	for(int i=0;i<Transformation.sz();i++)
	{
		User_Memory.cl();
		bool flag=0;
		for(int j=0;j<Temp_Message.sz();j++)
		{
			if(Temp_Message[j].fi==Transformation[i])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			Page_Faults++;
			if(Temp_Message.sz()<Page_Number)
			{
				Temp_Cnt[Transformation[i]]=1;
				Temp_Message.pb({Transformation[i],i});
				Error_Message.pb({i,-1});
			}
			else
			{
				int Minn_Cnt=0x3f3f3f3f,Minn_Time=0x3f3f3f3f,pos=-1;
				for(int j=0;j<Temp_Message.sz();j++)
				{
					int CNT=Temp_Cnt[Temp_Message[j].fi],TIME=Temp_Message[j].se;
					if(CNT<Minn_Cnt)
					{
						Minn_Cnt=CNT;
						Minn_Time=TIME;
						pos=j;
					}
					else if(CNT==Minn_Cnt&&TIME<Minn_Time)
					{
						Minn_Time=TIME;
						pos=j;
					}
				}
				Temp_Cnt[Temp_Message[pos].fi]=0;
				Temp_Cnt[Transformation[i]]=1;
				Error_Message.pb({i,Temp_Message[pos].fi});
				Temp_Message[pos].fi=Transformation[i];
				Temp_Message[pos].se=i;
			}
		}
		else
		{
			Temp_Cnt[Transformation[i]]++;
		}
		for(int j=0;j<Temp_Message.sz();j++)
		{
			User_Memory.pb(Temp_Message[j].fi);
		}
		Temp_Result.pb(User_Memory);
		Maxx=max(Maxx,(int)(User_Memory.sz()));
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"缺页次数为："<<Page_Faults<<" 次"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"缺页率为："<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"命中率为："<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"置换流程图如下："<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  请求页号    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  第 "<<r<<" 块页号 ";
			for(int k=i;k<=j;k++)
			{
				if(Temp_Result[k].sz()<r)
				{
					cout<<right<<setw(5)<<U_V<<" ";
				}
				else
				{
					cout<<right<<setw(5)<<Temp_Result[k][r-1]<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"  ";
		for(int k=1;k<=60;k++) cout<<".";
		cout<<endl;
		i=j;
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"详细置换信息如下："<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"但由于此时用户内存还没有用完，故不用置换页面，直接将该页面装入即可!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"被置换的页面为："<<y<<" 号页面"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"本次分析完成!!!"<<endl<<endl;
}
void CLOCK()
{
	User_Memory.cl();
	int Temp_Cnt[50]={0};
	int Page_Faults=0,Maxx=0;
	double Page_Fault_Rate,Hit_Rate;
	VII Temp_Result;
	VP Error_Message;
	int Point=-1;
	for(int i=0;i<Transformation.sz();i++)
	{
		int PP=-1;
		for(int j=0;j<User_Memory.sz();j++)
		{
			if(User_Memory[j]==Transformation[i])
			{
				PP=j;
				break;
			}
		}
		if(PP==-1)
		{
			Page_Faults++;
			if(User_Memory.sz()<Page_Number)
			{
				User_Memory.pb(Transformation[i]);
				Error_Message.pb({i,-1});
				Temp_Cnt[User_Memory.sz()-1]=1;
			}
			else
			{
				int pos=-1;
				while(1)
				{
					Point++;
					if(Point==(int)User_Memory.sz())
					{
						Point=0;
					}
					if(Temp_Cnt[Point]==0)
					{
						pos=Point;
						break;
					}
					else Temp_Cnt[Point]=0;
				}
				Error_Message.pb({i,User_Memory[pos]});
				User_Memory[pos]=Transformation[i];
				Temp_Cnt[pos]=1;
			}
		}
		else Temp_Cnt[PP]=1;
		Temp_Result.pb(User_Memory);
		Maxx=max(Maxx,(int)(User_Memory.sz()));
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"缺页次数为："<<Page_Faults<<" 次"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"缺页率为："<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"命中率为："<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"置换流程图如下："<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  请求页号    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  第 "<<r<<" 块页号 ";
			for(int k=i;k<=j;k++)
			{
				if(Temp_Result[k].sz()<r)
				{
					cout<<right<<setw(5)<<U_V<<" ";
				}
				else
				{
					cout<<right<<setw(5)<<Temp_Result[k][r-1]<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"  ";
		for(int k=1;k<=60;k++) cout<<".";
		cout<<endl;
		i=j;
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"详细置换信息如下："<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"但由于此时用户内存还没有用完，故不用置换页面，直接将该页面装入即可!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"被置换的页面为："<<y<<" 号页面"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"本次分析完成!!!"<<endl<<endl;
}
void FIFO()
{
	int Page_Faults=0,Maxx=0;
	double Page_Fault_Rate,Hit_Rate;
	VII Temp_Result;
	VP Error_Message;
	VP Temp_Message;
	for(int i=0;i<Transformation.sz();i++)
	{
		User_Memory.cl();
		bool flag=0;
		for(int j=0;j<Temp_Message.sz();j++)
		{
			if(Temp_Message[j].fi==Transformation[i])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			Page_Faults++;
			if(Temp_Message.sz()<Page_Number)
			{
				Temp_Message.pb({Transformation[i],i});
				Error_Message.pb({i,-1});
			}
			else
			{
				int Minn_Time=0x3f3f3f3f,pos=-1;
				for(int j=0;j<Temp_Message.sz();j++)
				{
					int TIME=Temp_Message[j].se;
					if(TIME<Minn_Time)
					{
						Minn_Time=TIME;
						pos=j;
					}
				}
				Error_Message.pb({i,Temp_Message[pos].fi});
				Temp_Message[pos].fi=Transformation[i];
				Temp_Message[pos].se=i;
			}
		}
		for(int j=0;j<Temp_Message.sz();j++)
		{
			User_Memory.pb(Temp_Message[j].fi);
		}
		Temp_Result.pb(User_Memory);
		Maxx=max(Maxx,(int)(User_Memory.sz()));
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"缺页次数为："<<Page_Faults<<" 次"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"缺页率为："<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"命中率为："<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"置换流程图如下："<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  请求页号    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  第 "<<r<<" 块页号 ";
			for(int k=i;k<=j;k++)
			{
				if(Temp_Result[k].sz()<r)
				{
					cout<<right<<setw(5)<<U_V<<" ";
				}
				else
				{
					cout<<right<<setw(5)<<Temp_Result[k][r-1]<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"  ";
		for(int k=1;k<=60;k++) cout<<".";
		cout<<endl;
		i=j;
	}
	cout<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"详细置换信息如下："<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"但由于此时用户内存还没有用完，故不用置换页面，直接将该页面装入即可!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"第 "<<x+1<<" 次调度发生缺页现象，待调度的页面为 "<<Transformation[x]<<" 号页面；"<<endl;
			cout<<"被置换的页面为："<<y<<" 号页面"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"本次分析完成!!!"<<endl<<endl;
}
void ShowOption()
{
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|         请选择你要使用的算法（输入数字）：        |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|       按 1 选择 最佳置换页面置换算法（OPT）       |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|    按 2 选择 最近最久未使用页面置换算法（LRU）    |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|       按 3 选择 最少使用页面置换算法（LFU）       |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|               按 4 选择 CLOCK算法                 |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|                按 5 选择 FIFO算法                 |"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}
void Read_Input()
{
	User_Input.cl();
	Transformation.cl();
	cout<<"请输入要读入的信息类型："<<endl;
	cout<<endl;
	cout<<"按 1 代表读入的是指令序列"<<endl;
	cout<<endl;
	cout<<"按 2 代表读入的是页地址流"<<endl;
	cout<<endl;
	while(1)
	{
		cin>>op;
		if(op.sz()==1&&(op[0]=='1'||op[0]=='2')) break;
		if(op.sz()==1&&(op[0]=='M'||op[0]=='m')) break;
		cout<<"输入的参数非法，请重新输入："<<endl; 
	}
	if(op.sz()==1&&(op[0]=='M'||op[0]=='m')) 
	{
		Statu=1;
		return;
	}
	if(op[0]=='1')
	{
		cout<<"请输入要读入的指令序列的长度:"<<endl;
		while(1)
		{
			cin>>N;
			if(IsNum(N)&&stoi(N)>0) break;
			if(N.sz()==1&&(N[0]=='M'||N[0]=='m')) break;
			cout<<"输入的n必须为正整数！！！"<<endl;
		}
		if(N.sz()==1&&(N[0]=='M'||N[0]=='m'))
		{
			Statu=1;
			return;
		}
		n=stoi(N);
		cout<<"请输入 "<<n<<" 个整数，范围在0-319之间（包括两端）:"<<endl;
		for(int i=0;i<n;i++)
		{
			string cnt_num;	
			cin>>cnt_num;
			if(!IsNum(cnt_num)||stoi(cnt_num)>319)
			{
				Statu=0;
				return;
			}
			User_Input.pb(stoi(cnt_num));
		}
		for(int i=0;i<n;i++)
		{
			Transformation.pb(User_Input[i]/10);
		}
	}
	else
	{
		cout<<"请输入要读入的页地址流的长度:"<<endl;
		while(1)
		{
			cin>>N;
			if(IsNum(N)&&stoi(N)>0) break;
			if(N.sz()==1&&(N[0]=='M'||N[0]=='m')) break;
			cout<<"输入的n必须为正整数！！！"<<endl;
		}
		if(N.sz()==1&&(N[0]=='M'||N[0]=='m'))
		{
			Statu=1;
			return;
		}
		n=stoi(N);
		cout<<"请输入 "<<n<<" 个整数，范围在0-31之间（包括两端）:"<<endl;
		for(int i=0;i<n;i++)
		{
			string cnt_num;	
			cin>>cnt_num;
			if(!IsNum(cnt_num)||stoi(cnt_num)>31)
			{
				Statu=0;
				return;
			}
			Transformation.pb(stoi(cnt_num));
		}
	}
}
bool safe()
{
	for(int i=0;i<n;i++)
	{
		if(Transformation[i]<0||Transformation[i]>31) return false;
	}
	for(int i=0;i<User_Input.sz();i++)
	{
		if(User_Input[i]<0||User_Input[i]>319) return false;
	}
	return true;
}
int main ()
{
	IOS;
	while(1)
	{
		ShowMenu();
		while(1)
		{
			cin>>op;
			if(op.sz()==1&&(op[0]=='N'||op[0]=='n'||op[0]=='C'||op[0]=='c'||op[0]=='E'||op[0]=='e')) break;
			cout<<"输入的参数非法，请重新输入："<<endl; 
		}
		if(op[0]=='E'||op[0]=='e')
		{
			cout<<"成功退出系统！！！"<<endl;
			break;
		}
		else if(op[0]=='N'||op[0]=='n')
		{
			init();
			while(1)
			{
				cout<<"请输入用户的内存容量分配多少页(4页-32页之间均可)："<<endl;
				while(1)
				{
					cin>>Page_Number_str;
					if(IsNum(Page_Number_str)&&stoi(Page_Number_str)>=4&&stoi(Page_Number_str)<=32) break;
					if(Page_Number_str.sz()==1&&(Page_Number_str[0]=='M'||Page_Number_str[0]=='m')) break;
					cout<<"输入的数字有误，请重新输入，要注意范围在4~32之间哦！"<<endl;
				}
				if(Page_Number_str.sz()==1&&(Page_Number_str[0]=='M'||Page_Number_str[0]=='m'))
				{
					break;
				}
				Page_Number=stoi(Page_Number_str);
				ShowOption();
				while(1)
				{
					cin>>op;
					if(op.sz()==1&&(op[0]>='1'&&op[0]<='5')) break;
					if(op.sz()==1&&(op[0]=='M'||op[0]=='m')) break;
			        cout<<"输入的参数非法，请重新输入："<<endl; 
				}
				if(op.sz()==1&&(op[0]=='M'||op[0]=='m'))
				{
					break;
				}
				if(op[0]=='1')
				{
					OPT();
				}
				else if(op[0]=='2')
				{
					LRU();
				}
				else if(op[0]=='3')
				{
					LFU();
				}
				else if(op[0]=='4')
				{
					CLOCK();
				}
				else
				{
					FIFO();
				}
				cout<<"请问是否还要继续用该组数据进行测试？"<<endl;
				cout<<endl;
				cout<<"输入 Y/y 代表继续用该组数据测试，可修改内存容量或者算法重新进行测试"<<endl;
				cout<<endl;
				cout<<"输入 N/n 代表停止对该组数据进行测试，并返回到主菜单页，可进行其他选择"<<endl;
				cout<<endl;
				while(1)
				{
					cin>>op;
					if(op.sz()==1&&(op[0]=='Y'||op[0]=='y'||op[0]=='N'||op[0]=='n'||op[0]=='M'||op[0]=='m')) break;
			        cout<<"输入的参数非法，请重新输入："<<endl; 
				}
				if(op[0]=='N'||op[0]=='n'||op[0]=='M'||op[0]=='m') break;
			}
		}
		else
		{
			Read_Input();
			if(Statu==1)
			{
				Statu=-1;
				continue;
			}
			if(Statu==0||!safe())
			{
				cout<<"注意，您输入的信息异常，为了安全，已终止本次服务!"<<endl; 
				Statu=-1;
				continue;
			}
			while(1)
			{
				cout<<"请输入用户的内存容量分配多少页(1页-32页之间均可)："<<endl;
				while(1)
				{
					cin>>Page_Number_str;
					if(IsNum(Page_Number_str)&&stoi(Page_Number_str)>=1&&stoi(Page_Number_str)<=32) break;
					if(Page_Number_str.sz()==1&&(Page_Number_str[0]=='M'||Page_Number_str[0]=='m')) break;
					cout<<"输入的数字有误，请重新输入，要注意范围在1~32之间哦！"<<endl;
				}
				if(Page_Number_str.sz()==1&&(Page_Number_str[0]=='M'||Page_Number_str[0]=='m')) 
				{
					break;
				}
				Page_Number=stoi(Page_Number_str);
				ShowOption();
				while(1)
				{
					cin>>op;
					if(op.sz()==1&&(op[0]>='1'&&op[0]<='5')) break;
					if(op.sz()==1&&(op[0]=='M'||op[0]=='m')) break;
			        cout<<"输入的参数非法，请重新输入："<<endl; 
				}
				if(op.sz()==1&&(op[0]=='M'||op[0]=='m'))
				{
					break;
				} 
				if(op[0]=='1')
				{
					OPT();
				}
				else if(op[0]=='2')
				{
					LRU();
				}
				else if(op[0]=='3')
				{
					LFU();
				}
				else if(op[0]=='4')
				{
					CLOCK();
				}
				else
				{
					FIFO();
				}
				cout<<"请问是否还要继续用该组数据进行测试？"<<endl;
				cout<<endl;
				cout<<"输入 Y/y 代表继续用该组数据测试，可修改内存容量或者算法重新进行测试"<<endl;
				cout<<endl;
				cout<<"输入 N/n 代表停止对该组数据进行测试，并返回到主菜单页，可进行其他选择"<<endl;
				cout<<endl;
				while(1)
				{
					cin>>op;
					if(op.sz()==1&&(op[0]=='Y'||op[0]=='y'||op[0]=='N'||op[0]=='n'||op[0]=='M'||op[0]=='m')) break;
			        cout<<"输入的参数非法，请重新输入："<<endl; 
				}
				if(op[0]=='N'||op[0]=='n'||op[0]=='M'||op[0]=='m') break;
			}
		}
	}
	return 0;
}
