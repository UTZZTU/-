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
string op;   //����Ĳ������� 
int Statu=-1;   //���ڵ�״̬
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
	cout<<"|     ��ӭ����ģ������ҳʽ�洢�����㷨ʵ��ҳ��      |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|                 ����Խ������²�����              |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|      1.�� N/n ϵͳ�Զ�������������в���չʾ      |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|       2.�� C/c �Զ����������ݽ��и��Ի�չʾ       |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|    3.�� M/m �������˵�ҳ�棨�ڷ����˵�ҳ��ִ�У�  |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|                 4.�� E/e �˳�ϵͳ                 |"<<endl;
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
	cout<<"ϵͳ������ɵ�ָ�����У�"<<endl<<endl;
	ShowSystemGeneration();
	cout<<endl<<endl;
	cout<<"ָ������ת��Ϊҳ��ַ����"<<endl<<endl;
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
	cout<<"ȱҳ����Ϊ��"<<Page_Faults<<" ��"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"ȱҳ��Ϊ��"<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"������Ϊ��"<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"�û�����ͼ���£�"<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  ����ҳ��    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  �� "<<r<<" ��ҳ�� ";
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
	cout<<"��ϸ�û���Ϣ���£�"<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"�����ڴ�ʱ�û��ڴ滹û�����꣬�ʲ����û�ҳ�棬ֱ�ӽ���ҳ��װ�뼴��!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"���û���ҳ��Ϊ��"<<y<<" ��ҳ��"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"���η������!!!"<<endl<<endl;
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
	cout<<"ȱҳ����Ϊ��"<<Page_Faults<<" ��"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"ȱҳ��Ϊ��"<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"������Ϊ��"<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"�û�����ͼ���£�"<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  ����ҳ��    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  �� "<<r<<" ��ҳ�� ";
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
	cout<<"��ϸ�û���Ϣ���£�"<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"�����ڴ�ʱ�û��ڴ滹û�����꣬�ʲ����û�ҳ�棬ֱ�ӽ���ҳ��װ�뼴��!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"���û���ҳ��Ϊ��"<<y<<" ��ҳ��"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"���η������!!!"<<endl<<endl;
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
	cout<<"ȱҳ����Ϊ��"<<Page_Faults<<" ��"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"ȱҳ��Ϊ��"<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"������Ϊ��"<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"�û�����ͼ���£�"<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  ����ҳ��    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  �� "<<r<<" ��ҳ�� ";
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
	cout<<"��ϸ�û���Ϣ���£�"<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"�����ڴ�ʱ�û��ڴ滹û�����꣬�ʲ����û�ҳ�棬ֱ�ӽ���ҳ��װ�뼴��!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"���û���ҳ��Ϊ��"<<y<<" ��ҳ��"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"���η������!!!"<<endl<<endl;
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
	cout<<"ȱҳ����Ϊ��"<<Page_Faults<<" ��"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"ȱҳ��Ϊ��"<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"������Ϊ��"<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"�û�����ͼ���£�"<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  ����ҳ��    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  �� "<<r<<" ��ҳ�� ";
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
	cout<<"��ϸ�û���Ϣ���£�"<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"�����ڴ�ʱ�û��ڴ滹û�����꣬�ʲ����û�ҳ�棬ֱ�ӽ���ҳ��װ�뼴��!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"���û���ҳ��Ϊ��"<<y<<" ��ҳ��"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"���η������!!!"<<endl<<endl;
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
	cout<<"ȱҳ����Ϊ��"<<Page_Faults<<" ��"<<endl<<endl;
	Page_Fault_Rate=Page_Faults*1.0/(int)(Transformation.sz());
	Hit_Rate=1.0-Page_Fault_Rate;
	Page_Fault_Rate*=100;
	Hit_Rate*=100;
	cout<<fixed<<setprecision(2)<<"ȱҳ��Ϊ��"<<Page_Fault_Rate<<" %"<<endl<<endl;
	cout<<fixed<<setprecision(2)<<"������Ϊ��"<<Hit_Rate<<" %"<<endl<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	cout<<"�û�����ͼ���£�"<<endl<<endl; 
	for(int i=0;i<Transformation.sz();i++)
	{
		cout<<endl;
		int j=i+9;
		j=min(j,(int)(Transformation.sz()-1));
		cout<<"  ����ҳ��    ";
		for(int k=i;k<=j;k++)
		{
			cout<<right<<setw(5)<<Transformation[k]<<" ";
		}
		cout<<endl<<endl;
		int U_V=-1;
		for(int r=1;r<=Maxx;r++)
		{
			cout<<"  �� "<<r<<" ��ҳ�� ";
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
	cout<<"��ϸ�û���Ϣ���£�"<<endl<<endl;
	for(int i=0;i<Error_Message.sz();i++)
	{
		int x=Error_Message[i].fi;
		int y=Error_Message[i].se;
		if(y==-1)
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"�����ڴ�ʱ�û��ڴ滹û�����꣬�ʲ����û�ҳ�棬ֱ�ӽ���ҳ��װ�뼴��!!!"<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"�� "<<x+1<<" �ε��ȷ���ȱҳ���󣬴����ȵ�ҳ��Ϊ "<<Transformation[x]<<" ��ҳ�棻"<<endl;
			cout<<"���û���ҳ��Ϊ��"<<y<<" ��ҳ��"<<endl;
			cout<<endl<<endl;
		}
	}
	cout<<"���η������!!!"<<endl<<endl;
}
void ShowOption()
{
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|         ��ѡ����Ҫʹ�õ��㷨���������֣���        |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|       �� 1 ѡ�� ����û�ҳ���û��㷨��OPT��       |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|    �� 2 ѡ�� ������δʹ��ҳ���û��㷨��LRU��    |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|       �� 3 ѡ�� ����ʹ��ҳ���û��㷨��LFU��       |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|               �� 4 ѡ�� CLOCK�㷨                 |"<<endl;
	cout<<"|                                                   |"<<endl;
	cout<<"|                �� 5 ѡ�� FIFO�㷨                 |"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}
void Read_Input()
{
	User_Input.cl();
	Transformation.cl();
	cout<<"������Ҫ�������Ϣ���ͣ�"<<endl;
	cout<<endl;
	cout<<"�� 1 ����������ָ������"<<endl;
	cout<<endl;
	cout<<"�� 2 ����������ҳ��ַ��"<<endl;
	cout<<endl;
	while(1)
	{
		cin>>op;
		if(op.sz()==1&&(op[0]=='1'||op[0]=='2')) break;
		if(op.sz()==1&&(op[0]=='M'||op[0]=='m')) break;
		cout<<"����Ĳ����Ƿ������������룺"<<endl; 
	}
	if(op.sz()==1&&(op[0]=='M'||op[0]=='m')) 
	{
		Statu=1;
		return;
	}
	if(op[0]=='1')
	{
		cout<<"������Ҫ�����ָ�����еĳ���:"<<endl;
		while(1)
		{
			cin>>N;
			if(IsNum(N)&&stoi(N)>0) break;
			if(N.sz()==1&&(N[0]=='M'||N[0]=='m')) break;
			cout<<"�����n����Ϊ������������"<<endl;
		}
		if(N.sz()==1&&(N[0]=='M'||N[0]=='m'))
		{
			Statu=1;
			return;
		}
		n=stoi(N);
		cout<<"������ "<<n<<" ����������Χ��0-319֮�䣨�������ˣ�:"<<endl;
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
		cout<<"������Ҫ�����ҳ��ַ���ĳ���:"<<endl;
		while(1)
		{
			cin>>N;
			if(IsNum(N)&&stoi(N)>0) break;
			if(N.sz()==1&&(N[0]=='M'||N[0]=='m')) break;
			cout<<"�����n����Ϊ������������"<<endl;
		}
		if(N.sz()==1&&(N[0]=='M'||N[0]=='m'))
		{
			Statu=1;
			return;
		}
		n=stoi(N);
		cout<<"������ "<<n<<" ����������Χ��0-31֮�䣨�������ˣ�:"<<endl;
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
			cout<<"����Ĳ����Ƿ������������룺"<<endl; 
		}
		if(op[0]=='E'||op[0]=='e')
		{
			cout<<"�ɹ��˳�ϵͳ������"<<endl;
			break;
		}
		else if(op[0]=='N'||op[0]=='n')
		{
			init();
			while(1)
			{
				cout<<"�������û����ڴ������������ҳ(4ҳ-32ҳ֮�����)��"<<endl;
				while(1)
				{
					cin>>Page_Number_str;
					if(IsNum(Page_Number_str)&&stoi(Page_Number_str)>=4&&stoi(Page_Number_str)<=32) break;
					if(Page_Number_str.sz()==1&&(Page_Number_str[0]=='M'||Page_Number_str[0]=='m')) break;
					cout<<"����������������������룬Ҫע�ⷶΧ��4~32֮��Ŷ��"<<endl;
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
			        cout<<"����Ĳ����Ƿ������������룺"<<endl; 
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
				cout<<"�����Ƿ�Ҫ�����ø������ݽ��в��ԣ�"<<endl;
				cout<<endl;
				cout<<"���� Y/y ��������ø������ݲ��ԣ����޸��ڴ����������㷨���½��в���"<<endl;
				cout<<endl;
				cout<<"���� N/n ����ֹͣ�Ը������ݽ��в��ԣ������ص����˵�ҳ���ɽ�������ѡ��"<<endl;
				cout<<endl;
				while(1)
				{
					cin>>op;
					if(op.sz()==1&&(op[0]=='Y'||op[0]=='y'||op[0]=='N'||op[0]=='n'||op[0]=='M'||op[0]=='m')) break;
			        cout<<"����Ĳ����Ƿ������������룺"<<endl; 
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
				cout<<"ע�⣬���������Ϣ�쳣��Ϊ�˰�ȫ������ֹ���η���!"<<endl; 
				Statu=-1;
				continue;
			}
			while(1)
			{
				cout<<"�������û����ڴ������������ҳ(1ҳ-32ҳ֮�����)��"<<endl;
				while(1)
				{
					cin>>Page_Number_str;
					if(IsNum(Page_Number_str)&&stoi(Page_Number_str)>=1&&stoi(Page_Number_str)<=32) break;
					if(Page_Number_str.sz()==1&&(Page_Number_str[0]=='M'||Page_Number_str[0]=='m')) break;
					cout<<"����������������������룬Ҫע�ⷶΧ��1~32֮��Ŷ��"<<endl;
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
			        cout<<"����Ĳ����Ƿ������������룺"<<endl; 
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
				cout<<"�����Ƿ�Ҫ�����ø������ݽ��в��ԣ�"<<endl;
				cout<<endl;
				cout<<"���� Y/y ��������ø������ݲ��ԣ����޸��ڴ����������㷨���½��в���"<<endl;
				cout<<endl;
				cout<<"���� N/n ����ֹͣ�Ը������ݽ��в��ԣ������ص����˵�ҳ���ɽ�������ѡ��"<<endl;
				cout<<endl;
				while(1)
				{
					cin>>op;
					if(op.sz()==1&&(op[0]=='Y'||op[0]=='y'||op[0]=='N'||op[0]=='n'||op[0]=='M'||op[0]=='m')) break;
			        cout<<"����Ĳ����Ƿ������������룺"<<endl; 
				}
				if(op[0]=='N'||op[0]=='n'||op[0]=='M'||op[0]=='m') break;
			}
		}
	}
	return 0;
}
