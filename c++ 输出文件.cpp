#include <bits/stdc++.h>
using namespace std;
void writeTxt(string file,int type)
{
	ofstream outfile;
	outfile.open(file);
	outfile<<"666";
	outfile.close();
//	ofstream out(file, ios::app);
//	if(out.fail()){
//	    cout<<"error"<<endl;
//	    return;
//	}
//	if(type)
//	{
//	    for(int i=0;i<vec1.size();i++)
//	    {
//	    	if(!i)
//	    	{
//	    		out<<vec1[i].name<<endl;
//	    		out<<vec1[i].realtrue;
//			}
//	    	else
//	    	{
//	    		out<<endl<<vec1[i].name;
//	    		out<<endl<<vec1[i].realtrue;
//			}
//		}
//	}
//	else
//	{
//		for(int i=0;i<vec1.size();i++)
//	    {
//	    	if(!i)
//	    	{
//	    		out<<vec1[i].pre.size()<<endl;
//	    		for(int j=0;j<vec2.size();j++)
//	    		{
//	    			out<<vec2[j]<<endl;
//				}
//	    		out<<vec1[i].realtrue;
//			}
//	    	else
//	    	{
//	    		out<<endl<<vec1[i].pre.size();
//	    		for(int j=0;j<vec2.size();j++)
//	    		{
//	    			out<<endl<<vec2[j];
//				}
//	    		out<<endl<<vec1[i].realtrue;
//			}
//		}
//	}
	outfile.close();
}
//void readTxt(string file,int type)
//{
//	ifstream outfile;
//	outfile.open(file);
//	string s;
//	while(getline())
//	outfile.close();
//	out.close();
//}
int main ()
{
	//writeTxt("C:\\Users\\王文博\\Desktop\\1.txt",1);
	ofstream outfile("C:\\Users\\王文博\\Desktop\\1.txt",ios::ate);   //打开文件，设置写入方式为覆盖写入

    if(!outfile)
    {
        cout<<"txt文件打开失败!"<<endl;
        exit(0);
    }

    outfile<<"写入txt文件示例.\n";
    outfile<<"成功写入.\n";

    outfile.close();
	return 0;
}
