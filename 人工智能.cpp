#include <bits/stdc++.h>
using namespace std;
int op;  //1-识别动物  2-添加事实及规则  3-删除规则  4- 
void Process_files(string &u,int &v,string s)
{
	cout<<s<<endl;
}
void readTxt(string file)
{
    ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 
    //assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    string s;
    while(getline(infile,s))
    {
        string u;
        int x;
        Process_files(u,x,s);
//        cout<<u<<" "<<x<<endl;
    }
    infile.close();             //关闭文件输入流 
}
//增删改查
 
int main ()
{
//	printf("欢迎你使用该动物识别专家系统,我们将竭力为您服务\n"); 
//	while(1)
//	{
//		
//	}
	readTxt("D:\\test.txt");
	return 0;
}