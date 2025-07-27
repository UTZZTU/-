#define GLUT_DISABLE_ATEXIT_HACK
#include <bits/stdc++.h>
#include <Windows.h>
#include <gl/glut.h>
using namespace std;
#define fi first
#define se second
pair<int,int> P[1000100];
int n,minn=0x3f3f3f3f,maxx;
/*
3 12
7 8
12 9
8 1
6 5
3 1
1 7
*/
struct LineAE{
	float x;
	float dx;
	int ymax;
	struct LineAE *next;
};
bool cmp(LineAE a,LineAE b)
{
	if(a.x==b.x) return a.dx<b.dx;
	else return a.x<b.x;
}
struct Line{
	int wx,wy,rx,ry;	
	int q;
}l[1000100];
vector<LineAE> vec[1000100];
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=minn*100;i<=maxx*100;i++)
    {
    	for(int j=0;j<vec[i].size();j+=2)
    	{
    		glColor3f(0.0, 0.0, 1.0); 
    		glBegin(GL_LINE_STRIP);
    		glVertex2f((GLfloat)vec[i][j].x/10.0-0.5, (GLfloat)i*1.0/1000.0-0.5);
    		glVertex2f((GLfloat)vec[i][j+1].x/10.0-0.5, (GLfloat)i*1.0/1000.0-0.5);
//    		cout<<(GLfloat)vec[i][j].x/100.0<<" "<<(GLfloat)i*1.0/100.0<<endl;
//    		cout<<(GLfloat)vec[i][j+1].x/100.0<<" "<<(GLfloat)i*1.0/100.0<<endl;
    		glEnd();
		}
	}
    glFlush();
}
int main(int argc, char *argv[])
{
	cout<<"请输入多边形的顶点数目n(n>=3):"<<endl;
	cin>>n;
	cout<<"请按顺序输入各个顶点的坐标"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>P[i].fi>>P[i].se;
		minn=min(minn,P[i].se);
		maxx=max(maxx,P[i].se);
	}
	for(int i=1;i<=n;i++) l[i].q=0;
	for(int i=1;i<=n;i++)
	{
		if(i==n) 
		l[i]={P[i].fi,P[i].se,P[1].fi,P[1].se};
		else
		l[i]={P[i].fi,P[i].se,P[i+1].fi,P[i+1].se};
		int pre,post;
		if(i==1) pre=n;
		else pre=i-1;
		if(i==n) post=1;
		else post=i+1;
		if(P[post].se>=P[i].se&&P[i].se>P[pre].se||P[post].se>P[i].se&&P[i].se>=P[pre].se)
		{
			l[pre].q=-1;
		}
		else if(P[pre].se>=P[i].se&&P[i].se>P[post].se||P[pre].se>P[i].se&&P[i].se>=P[post].se)
		{
			l[i].q=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(l[i].ry<l[i].wy)
		{
			if(l[i].rx==l[i].wx)
			{
				vec[l[i].ry*100].push_back({l[i].rx,0,l[i].wy*100+l[i].q});
			}
			else
			{
				vec[l[i].ry*100].push_back({l[i].rx,(float)0.01/((l[i].wy-l[i].ry)*1.0/(l[i].wx-l[i].rx)),l[i].wy*100+l[i].q});
			}
		}
		else if(l[i].ry==l[i].wy)
		{
			vec[l[i].ry*100].push_back({l[i].rx,0,l[i].wy*100+l[i].q});
		}
		else if(l[i].ry>l[i].wy)
		{
			if(l[i].rx==l[i].wx)
			{
				vec[l[i].wy*100].push_back({l[i].wx,0,l[i].ry*100+l[i].q});
			}
			else
			{
				vec[l[i].wy*100].push_back({l[i].wx,(float)0.01/((l[i].wy-l[i].ry)*1.0/(l[i].wx-l[i].rx)),l[i].ry*100+l[i].q});
			}
		}
	}
	for(int i=minn*100;i<=maxx*100;i++)
	{
		vector<LineAE> v;
		for(int j=0;j<vec[i].size();j++)
		{
			if(i+1<=vec[i][j].ymax)
			{
				v.push_back({vec[i][j].x+vec[i][j].dx,vec[i][j].dx,vec[i][j].ymax});
			}
		}
		for(int j=0;j<vec[i+1].size();j++)
		{
			v.push_back({vec[i+1][j].x,vec[i+1][j].dx,vec[i+1][j].ymax});
		}
		vec[i+1]=v;
		sort(vec[i].begin(),vec[i].end(),cmp);
	}
	for(int i=minn*100;i<=maxx*100;i++)
	{
		if(vec[i].size()&1) vec[i].push_back({vec[i][vec[i].size()-1]});
	}
//	for(int i=minn;i<=maxx;i++)
//	{
//		for(int j=0;j<vec[i].size();j++)
//		{
//			cout<<vec[i][j].x<<" "<<vec[i][j].dx<<"    ";
//		}
//		cout<<endl;
//	}
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("最终图形");
    glutDisplayFunc(&myDisplay);
    glutMainLoop(); 
    return 0;
}
