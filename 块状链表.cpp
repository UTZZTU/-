#include <bits/stdc++.h>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_cxx;
 
const int MAXN = 10010;
string s;
int board[MAXN];
 
int main(){
	
	rope<char> ropeC;
	rope<int> ropeI;
	cin>>s;
	cout<<"s: "<<s<<endl;
	for(int i=0 ; i<=9 ; ++i){
		board[i] = i;
		ropeI.push_back(i);
	}
	cout<<"board[10]: ";
	for(int i=0 ; i<=9 ; ++i)cout<<board[i]<<" ";
	cout<<endl;
	cout<<"ropeI: ";
	for(int i=0 ; i<=9 ; ++i)cout<<ropeI[i]<<" ";
	cout<<endl;
	for(int i=0 ; i<s.length() ; ++i)ropeC.push_back(s[i]);
	cout<<"ropeC: "<<ropeC<<endl;
	cout<<endl;
	
	cout<<"1------ .push_back(x);//在末尾添加x"<<endl;
	cout<<"在ropeC末尾添加a:"<<endl;
	ropeC.push_back('a');
	cout<<"ropeC: "<<ropeC<<endl;
	cout<<"在ropeI末尾添加7:"<<endl;
	ropeI.push_back(7);
	cout<<"ropeI: ";
	for(int i=0 ; i<=10 ; ++i)cout<<ropeI[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"2------ .insert(pos,x);//在pos位置插入x"<<endl;
	cout<<"ropeC.insert(2,'c'):"<<endl;
	ropeC.insert(2,'c');
	cout<<"ropeC:"<<ropeC<<endl;
	cout<<"ropeC.insert(2,\"ccc\"):"<<endl;
	ropeC.insert(2,"ccc");
	cout<<"ropeC:"<<ropeC<<endl;
	cout<<"ropeI.insert(2,7):"<<endl;
	ropeI.insert(2,7);
	cout<<"ropeI:";
	for(int i=0 ; i<=11 ; ++i)cout<<ropeI[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"3------ .erase(pos,x);//从pos开始删除x个元素"<<endl;
	cout<<"ropeC.erase(0,2):"<<endl;
	ropeC.erase(0,2);
	cout<<"ropeC:"<<ropeC<<endl;
	cout<<"ropeI.erase(0,2):"<<endl;
	ropeI.erase(0,2);	
	cout<<"ropeI:";
	for(int i=0 ; i<=9 ; ++i)cout<<ropeI[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"4------ .copy(pos,len,x);//将pos开始长len个元素替换到char[] x中"<<endl;
	char ss[10];//注意string不行只能用char[] 
	cout<<"ropeC.copy(0,2,ss):"<<endl;
	ropeC.copy(0,2,ss);
	ss[2] = '\0';//注意加\0 
	cout<<"ss:"<<ss<<endl;
	cout<<"ropeI.copy(0,2,board):"<<endl;
	ropeI.copy(0,2,board);
	cout<<"board[10]: ";
	for(int i=0 ; i<=9 ; ++i)cout<<board[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"5------ .replace(pos,x);//将pos换成x"<<endl;
	cout<<"ropeC.replace(1,'e'):"<<endl;
	ropeC.replace(1,'e');
	cout<<"ropeC: "<<ropeC<<endl;
	cout<<"ropeC.replace(1,\"eee\"):"<<endl;
	ropeC.replace(1,"eee");
	cout<<"ropeC: "<<ropeC<<endl;
	cout<<"ropeI.replace(1,9):"<<endl;
	ropeI.replace(1,9);
	cout<<"ropeI:";
	for(int i=0 ; i<=9 ; ++i)cout<<ropeI[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"6------ .substr(pos,x);//提取pos开始x个元素"<<endl;
	cout<<"ropeC.substr(1,3):"<<ropeC.substr(1,3)<<endl<<endl;
	
	cout<<"7------ .at(x)/[x];//访问第x个元素"<<endl;
	cout<<"ropeC.at(3):"<<ropeC.at(3)<<endl;
	cout<<"ropeC[3]:"<<ropeC[3]<<endl;
	cout<<"ropeI.at(3):"<<ropeI.at(3)<<endl;
	cout<<"ropeI[3]:"<<ropeI[3]<<endl;
	
	
	return 0;
}