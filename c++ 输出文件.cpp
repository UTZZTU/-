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
	//writeTxt("C:\\Users\\���Ĳ�\\Desktop\\1.txt",1);
	ofstream outfile("C:\\Users\\���Ĳ�\\Desktop\\1.txt",ios::ate);   //���ļ�������д�뷽ʽΪ����д��

    if(!outfile)
    {
        cout<<"txt�ļ���ʧ��!"<<endl;
        exit(0);
    }

    outfile<<"д��txt�ļ�ʾ��.\n";
    outfile<<"�ɹ�д��.\n";

    outfile.close();
	return 0;
}
