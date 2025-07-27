#include<bits/stdc++.h>
#include <Windows.h>
using namespace std;

struct fact
{
    string value;
    bool finaltruth;
};

struct rule
{
    vector<string>pre_condition;
    string conclusion;
};

vector<fact>factbase;
vector<rule>rulebase;
vector<string>infact;
vector<string>finalconclusion;
vector<string>inifactbase;
map<string,int>pos;

void show();
void showfact();
void showrule();
string UTF8ToGB(const char* str);
void readTxt(string file,int type);
void writeTxt(string file,int type);
void infer();
void addfact();
void addrule();
void deletefact();
void deleterule();
void load();
void save();
bool explain(string s);
bool query(string s);

int main()
{
    load();
    while(1){
        show();
        int op;
        cin>>op;
        bool endd=false;
        switch(op)
        {
            case 1:infer();break;
            case 2:addfact();break;
            case 3:addrule();break;
            case 4:deletefact();break;
            case 5:deleterule();break;
            case 6:showfact();break;
            case 7:showrule();break;
            case 8:endd=true;break;
            default:cout<<"输入操作错误！"<<endl;
        }
        if(endd) break;
    }
    save();
    cout<<"感谢您的使用!"<<endl;
    return 0;
}

void infer()
{
    infact.clear();
    int num;
    cout<<"请输入事实数量："<<endl;
    cin>>num;
    cout<<"请输入事实(用空格分开)："<<endl;

    for(int i=0;i<num;i++){
        string s;
        cin>>s;
        infact.push_back(s);
        for(int i=0;i<finalconclusion.size();i++){
            if(finalconclusion[i]==s){
                cout<<"输入的证据中已经存在最终结论！"<<endl;
                cout<<finalconclusion[i]<<endl;
                return ;
            }
        }
    }
    inifactbase=infact;

    int flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<rulebase.size();i++){
            int ff=1;
            if(find(infact.begin(),infact.end(),rulebase[i].conclusion)!=infact.end()){ //判断规则结论是否在已知证据库中
                continue ;
            }
            for(auto j:rulebase[i].pre_condition){
                if(find(infact.begin(),infact.end(),j)==infact.end()){
                    ff=0;
                    break;
                }
            }
            if(ff){
                infact.push_back(rulebase[i].conclusion);
                flag=1;
            }
            pos[rulebase[i].conclusion]=i;
        }
    }

    for(auto i:infact){
        if(find(finalconclusion.begin(),finalconclusion.end(),i)!=finalconclusion.end()){
            cout<<i<<endl;
            explain(i);
            return ;
        }
    }

    priority_queue<pair<double,string> >q;
    for(auto i:finalconclusion){
        int p=pos[i];
        double num=0,sum=rulebase[p].pre_condition.size();
        for(auto j:rulebase[p].pre_condition){
            if(find(infact.begin(),infact.end(),j)!=infact.end()) num++;
        }
        double redit=num/sum;
        cout<<i<<" "<<redit<<endl;
        if(redit>=0.5){
            q.push({redit,i});
        }
    }

    while(!q.empty()){
        auto [d,s]=q.top();
        q.pop();
        bool flag=false;
        flag=query(s);
        if(flag){
            cout<<s<<endl;
            explain(s);
            return ;
        }
    }
    cout<<"您输入的证据无法推出结论！"<<endl;
}

bool explain(string s)
{
    if(find(inifactbase.begin(),inifactbase.end(),s)!=inifactbase.end()) return true;
    else if(!pos.count(s)&&find(inifactbase.begin(),inifactbase.end(),s)==inifactbase.end()) return false;
    for(int k=0;k<rulebase.size();k++){
        if(rulebase[k].conclusion!=s) continue;
        bool flag=true;
        for(auto i:rulebase[k].pre_condition){
            flag=explain(i);
            if(!flag) break;
        }
        if(!flag) continue;
        cout<<"因为 ";
        for(auto i:rulebase[k].pre_condition) cout<<i<<" ";
        cout<<"所以 "<<s<<endl;
        break;
    }
    return true;
}

bool query(string s)
{
    if(find(infact.begin(),infact.end(),s)!=infact.end()) return true;
    else if(!pos.count(s)&&find(infact.begin(),infact.end(),s)==infact.end()){
        cout<<"请问 "<<s<<" 吗(输入yes or no)"<<endl;
        string str;
        cin>>str;
        if(str=="yes"){
            infact.push_back(s);
            inifactbase.push_back(s);
            return true;
        }
        else return false;
    }
    for(int k=0;k<rulebase.size();k++){
        if(rulebase[k].conclusion!=s) continue;
        int cnt=0;
        for(auto i:rulebase[k].pre_condition){
            if(find(infact.begin(),infact.end(),s)!=infact.end()){
                cnt++;
                continue;
            }
            bool res=query(i);
            if(res) cnt++;
            else break;
        }
        if(cnt==rulebase[k].pre_condition.size()){
            return true;
        }
    }
    return false;
}

void addfact()
{
    cout<<"请输入你要增加的事实："<<endl;
    string a;
    cin>>a;
    cout<<"这个事实是否是最终结论（0不是，1是）："<<endl;
    int b;
    cin>>b;
    if(b){
        factbase.push_back({a,true});
        finalconclusion.push_back(a);
    }
    else{
        factbase.push_back({a,false});
    }
    cout<<"增加成功！"<<endl<<endl;
}

void addrule()
{
    cout<<"增加规则"<<endl<<endl;
    cout<<"请输入前提条件的数量："<<endl;
    int cnt;
    cin>>cnt;
    vector<string>arule;
    cout<<"请输入前提条件："<<endl;
    for(int i=0;i<cnt;i++){
        string s;
        cin>>s;
        arule.push_back(s);
    }
    cout<<"请输入最终结论："<<endl;
    string res;
    cin>>res;
    rulebase.push_back({arule,res});
    cout<<"增加成功！"<<endl<<endl;
}

void deletefact()
{
    cout<<"知识库："<<endl;
    int k=0;
    for(auto i:factbase){
        k++;
        cout<<k<<":"<<setw(14)<<left<<i.value;
        if(k%5==0) cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"请输入要删除事实的序号："<<endl;
    int id;
    cin>>id;
    if(id<=0||id>=factbase.size()){
        cout<<"删除失败！"<<endl;
        return ;
    }
    id--;
    factbase.erase(factbase.begin()+id);
    cout<<"删除成功！"<<endl<<endl;
}

void deleterule()
{
    cout<<"规则库："<<endl;
    int k=0;
    for(auto i:rulebase){
        k++;
        cout<<k<<":"<<endl;
        cout<<"前提条件：";
        for(auto j:i.pre_condition)
            cout<<j<<" ";
        cout<<endl<<"结论：";
        cout<<i.conclusion;
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"请输入要删除规则的序号："<<endl;
    int id;
    cin>>id;
    if(id<=0||id>=rulebase.size()){
        cout<<"删除失败！"<<endl;
        return ;
    }
    id--;
    rulebase.erase(rulebase.begin()+id);
    cout<<"删除成功！"<<endl<<endl;
}

void show()
{
    cout<<"-----------------------------"<<endl;
    cout<<"欢迎来到动物识别专家系统"<<endl<<endl;
    cout<<"请输入操作:"<<endl;
    cout<<"1:识别动物"<<endl;
    cout<<"2:添加事实"<<endl;
    cout<<"3:添加规则"<<endl;
    cout<<"4:删除事实"<<endl;
    cout<<"5:删除规则"<<endl;
    cout<<"6:知识库"<<endl;
    cout<<"7:规则库"<<endl;
    cout<<"8:退出"<<endl<<endl;

}

void showfact()
{
    cout<<"知识库："<<endl;
    int k=0;
    for(auto i:factbase){
        k++;
        cout<<setw(14)<<left<<i.value;
        if(k%5==0) cout<<endl;
    }
    cout<<endl<<endl;
}

void showrule()
{
    cout<<"规则库："<<endl;
    for(auto i:rulebase){
        cout<<"前提条件：";
        for(auto j:i.pre_condition)
            cout<<j<<" ";
        cout<<endl<<"结论：";
        cout<<i.conclusion;
        cout<<endl;
    }
    cout<<endl<<endl;
}

void load()
{
    factbase.clear();
    rulebase.clear();
    finalconclusion.clear();
    pos.clear();
    inifactbase.clear();
    readTxt("C:\\Users\\王文博\\Desktop\\1.txt",1);
    readTxt("C:\\Users\\王文博\\Desktop\\2.txt",0);
}

string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
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
    infile.open(file.data());   //将文件流对象与文件连接起来
	if(type)
	{
		string s;
	    int current_num=0;
	    string name;
	    int flag;
	    while(getline(infile,s))
	    {
	        //UTF8ToGB(s.c_str()).c_str()
			  string line =  s;
			  current_num++;
			  if(current_num&1) name=line;
			  else {
                    flag=stoi(line);
                    factbase.push_back({name,flag});
                    if(flag){
                        finalconclusion.push_back(name);
                    }
			  }
	    }
	}
	else
	{
		string s;
		int sumnum;
	    while(getline(infile,s))
	    {
			  string line =  s;
			  sumnum=stoi(line);
			  vector<string> v;
			  for(int i=1;i<=sumnum;i++)
			  {
			  	getline(infile,s);
			  	string line =  s;
			  	v.push_back(line);
			  }
			  getline(infile,s);
			  line =  s;
			  rulebase.push_back({v,line});
	    }
	}

    infile.close();             //关闭文件输入流
}

void writeTxt(string file,int type)
{
	ofstream outfile;
	outfile.open(file);
	outfile<<"";
	outfile.close();
	ofstream out(file, ios::app);
	if(out.fail()){
	    cout<<"error"<<endl;
	    return;
	}
	if(type)
	{
	    for(int i=0;i<factbase.size();i++)
	    {
	    	if(!i)
	    	{
	    		out<<factbase[i].value<<endl;
	    		if(factbase[i].finaltruth)
                    out<<1;
	    		else
                    out<<0;
			}
	    	else
	    	{
	    		out<<endl<<factbase[i].value<<endl;
	    		if(factbase[i].finaltruth)
                    out<<1;
	    		else
                    out<<0;
			}
		}
	}
	else
	{
		for(int i=0;i<rulebase.size();i++)
	    {
	    	if(!i)
	    	{
	    		out<<rulebase[i].pre_condition.size()<<endl;
	    		for(int j=0;j<rulebase[i].pre_condition.size();j++)
	    		{
	    			out<<rulebase[i].pre_condition[j]<<endl;
				}
	    		out<<rulebase[i].conclusion;
			}
	    	else
	    	{
	    		out<<endl<<rulebase[i].pre_condition.size()<<endl;
	    		for(int j=0;j<rulebase[i].pre_condition.size();j++)
	    		{
	    			out<<rulebase[i].pre_condition[j]<<endl;
				}
	    		out<<rulebase[i].conclusion;
			}
		}
	}
	out.close();
}

void save()
{
    writeTxt("C:\\Users\\王文博\\Desktop\\1.txt",1);
    writeTxt("C:\\Users\\王文博\\Desktop\\2.txt",0);
}