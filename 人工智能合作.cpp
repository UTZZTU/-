#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
//int op;
//struct node
//{
//	string name;
//	int is_final_truth;
//};
//struct line{
//	string name;
//	vector<string> linner;
//};
//vector<node> vec1;
//vector<line> vec2;
string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;
 
	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);
 
	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);
 
	result = szRes;
	delete[]strSrc;
	delete[]szRes;
 
	return result;
}

void readTxt(string file,int type)
{
    ifstream infile; 
    infile.open(file.data());   //���ļ����������ļ��������� 
    string s;
    while(getline(infile,s))
    {
    	string line =  UTF8ToGB(s.c_str()).c_str();
    	cout<<line<<endl;
	}
    //assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 
//	if(type)
//	{
//		string s;
//	    int current_num=0;
//	    string name;
//	    int flag;
//	    while(getline(infile,s))
//	    {
	//        string u;
	//        int x;
	//        Process_files(u,x,s);
	//        cout<<u<<" "<<x<<endl;
//			  string line =  UTF8ToGB(s.c_str()).c_str();
//			  current_num++;
//			  if(current_num&1) name=line;
//			  else {
//			  	flag=stoi(line);
//			  	vec1.push_back({name,flag});
//			  }
//	    }
//	}
//	else
//	{
//		string s;
//		int sumnum;
//	    while(getline(infile,s))
//	    {
	//        string u;
	//        int x;
	//        Process_files(u,x,s);
	//        cout<<u<<" "<<x<<endl;
//			  string line =  UTF8ToGB(s.c_str()).c_str();
//			  sumnum=stoi(line);
//			  vector<string> v;
//			  for(int i=1;i<=sumnum;i++)
//			  {
//			  	getline(infile,s);
//			  	string line =  UTF8ToGB(s.c_str()).c_str();
//			  	v.push_back(line);
//			  }
//			  getline(infile,s);
//			  line =  UTF8ToGB(s.c_str()).c_str();
//			  vec2.push_back({line,v});
//	    }
//	}
//    
    infile.close();             //�ر��ļ������� 
}
//��ɾ�Ĳ�
 
int main ()
{
//	printf("��ӭ��ʹ�øö���ʶ��ר��ϵͳ,���ǽ�����Ϊ������\n"); 
//	while(1)
//	{
//		
//	}
	//readTxt("C:\\Users\\���Ĳ�\\Desktop\\1.txt",1);
//	readTxt("C:\\Users\\���Ĳ�\\Documents\\Tencent Files\\1599441272\\FileRecv\\rulebase.txt",0);
//	for(int i=0;i<vec1.size();i++)
//	{
//		cout<<vec1[i].name<<" "<<vec1[i].is_final_truth<<endl;
//	}
//	cout<<endl<<endl<<endl;
//	for(int i=0;i<vec2.size();i++)
//	{
//		cout<<vec2[i].name<<endl;
//		for(int j=0;j<vec2[i].linner.size();j++)
//		{
//			cout<<vec2[i].linner[j]<<" ";
//		}
//		cout<<endl;
//	}
	//char txt[100];
	string txt;
    ifstream infile;
    infile.open("C:\\Users\\���Ĳ�\\Desktop\\1.txt");

    if(!infile.is_open())
    {
        cout<<"txt�ļ���ʧ��"<<endl;
        exit(0);
    }

    while(getline(infile,txt))
    {       
        cout<<txt<<endl;
    }

    infile.close();
    getchar();
	return 0;
}
