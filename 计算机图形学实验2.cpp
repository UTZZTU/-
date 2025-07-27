#define GLUT_DISABLE_ATEXIT_HACK
#include <bits/stdc++.h>
#include <Windows.h>
#include <gl/glut.h>
using namespace std;
#define fi first
#define se second
#define PI 3.1415926
pair<int,int> P[1000100];
int n,judge;
float point[101][101];
/*
3 12
7 8
12 9
8 1
6 5
3 1
1 7
*/
/*
0 5
10 10
3 0
*/
void MatrixMultiplication(float a[][101], float b[][4])
{
	float f[101][101]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=3;k++)
			{
				f[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	memcpy(a,f,sizeof f);
}
void MatrixInverse(float a[][4], float b[][4])
{
	int i, j, k, N = 4;
	float max, temp;
	float t[N][N];
	for (i = 1; i < N; i++)
	{
		for (j = 1; j < N; j++)
		{
			t[i][j] = a[i][j];
		}
	}
	for (i = 1; i < N; i++)
	{
		for (j = 1; j < N; j++)
		{
			b[i][j] = (i == j) ? (float)1 : 0;
		}
	}
	for (i = 1; i < N; i++)
	{
		max = t[i][i];
		k = i;
		for (j = i + 1; j < N; j++)
		{
			if (fabs(t[j][i]) > fabs(max))
			{
				max = t[j][i];
				k = j;
			}
		}
		if (k != i)
		{
			for (j = 1; j < N; j++)
			{
				temp = t[i][j];
				t[i][j] = t[k][j];
				t[k][j] = temp;
				temp = b[i][j];
				b[i][j] = b[k][j];
				b[k][j] = temp;
			}
		}
		if (t[i][i] == 0)
		{
			cout << "\nthe matrix does not exist inverse matrix\n";
			break;
		}
		temp = t[i][i];
		for (j = 1; j < N; j++)
		{
			t[i][j] = t[i][j] / temp;
			b[i][j] = b[i][j] / temp;
		}
		for (j = 1; j < N; j++)
		{
			if (j != i)
			{
				temp = t[j][i];
				for (k = 1; k < N; k++)
				{
					t[j][k] = t[j][k] - temp * t[i][k];
					b[j][k] = b[j][k] - temp * b[i][k];
				}
			}
 
		}
	}
}
void Translation()
{
	float x,y;
	cout<<"������Ҫƫ�Ƶ�x����y����"<<endl;
	cin>>x>>y;
	float solve[4][4]={
		{0,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,x,y,1}
	};
	MatrixMultiplication(point,solve);
}
void Spin()
{
	float angle;
	cout<<"������Ҫ��ת�ĽǶȣ�"<<endl;
	cin>>angle;
	float solve[4][4]={
		{0,0,0,0},
		{0,cos(angle*PI/180.0f),sin(angle*PI/180.0f),0},
		{0,-sin(angle*PI/180.0f),cos(angle*PI/180.0f),0},
		{0,0,0,1}
	};
	MatrixMultiplication(point,solve);
}
void Zoom()
{
	float x,y;
	cout<<"������x�����ϵ���������y�����ϵ���������"<<endl;
	cin>>x>>y;
	float solve[4][4]={
		{0,0,0,0},
		{0,x,0,0},
		{0,0,y,0},
		{0,0,0,1}
	};
	MatrixMultiplication(point,solve);
}
void Symmetry()
{
	cout<<"��Ҫ����x��Գ�������1��"<<endl;
	cout<<"��Ҫ����y��Գ�������2��"<<endl;
	cout<<"��Ҫ����ԭ��Գ�������3��"<<endl;
	cout<<"��Ҫ����ֱ��y=x�Գ�������4��"<<endl;
	cout<<"��Ҫ����ֱ��y=-x�Գ�������5��"<<endl;
	cin>>judge;
	if(judge==1)
	{
		float solve[4][4]={
			{0,0,0,0},
			{0,1,0,0},
			{0,0,-1,0},
			{0,0,0,1}
		};
		MatrixMultiplication(point,solve);
	}
	else if(judge==2)
	{
		float solve[4][4]={
			{0,0,0,0},
			{0,-1,0,0},
			{0,0,1,0},
			{0,0,0,1}
		};
		MatrixMultiplication(point,solve);
	}
	else if(judge==3) 
	{
		float solve[4][4]={
			{0,0,0,0},
			{0,-1,0,0},
			{0,0,-1,0},
			{0,0,0,1}
		};
		MatrixMultiplication(point,solve);
	}
	else if(judge==4) 
	{
		float solve[4][4]={
			{0,0,0,0},
			{0,0,1,0},
			{0,1,0,0},
			{0,0,0,1}
		};
		MatrixMultiplication(point,solve);
	}
	else if(judge==5) 
	{
		float solve[4][4]={
			{0,0,0,0},
			{0,0,-1,0},
			{0,-1,0,0},
			{0,0,0,1}
		};
		MatrixMultiplication(point,solve);
	}
}
void WrongCut()
{
	float angle1,angle2;
	cout<<"������x������Ҫ���еĽǶȣ�"<<endl;
	cin>>angle1;
	cout<<"������y������Ҫ���еĽǶȣ�"<<endl;
	cin>>angle2;
	float solve[4][4]={
		{0,0,0,0},
		{0,1,tan(angle2*PI/180.0f),0},
		{0,tan(angle1*PI/180.0f),1,0},
		{0,0,0,1}
	};
	cout<<"������x�����ϽǶȵķ���1Ϊ������2Ϊ������"<<endl;
	cin>>judge;
	if(judge==2) solve[2][1]*=-1;
	cout<<"������y�����ϽǶȵķ���1Ϊ������2Ϊ�����򣺣�"<<endl;
	cin>>judge;
	if(judge==2) solve[1][2]*=-1;
	MatrixMultiplication(point,solve);
}
void PointTransformation()
{
	float x,y;
	cout<<"������Ҫ���ڵĵ�����꣨x,y����"<<endl;
	cin>>x>>y;
	float solve[4][4]={
		{0,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,-x,-y,1}
	};
	MatrixMultiplication(point,solve);
	cout<<"ƽ�Ʊ任������1"<<endl;
	cout<<"��ת�任������2"<<endl;
	cout<<"���ű任������3"<<endl;
	cout<<"�ԳƱ任������4"<<endl;
	cout<<"���б任������5"<<endl;
	cin>>judge;
	if(judge==1)
	{
		Translation();
	}
	else if(judge==2)
	{
		Spin();
	}
	else if(judge==3)
	{
		Zoom();
	}
	else if(judge==4)
	{
		Symmetry();
	}
	else
	{
		WrongCut();
	}
	solve[3][1]*=-1,solve[3][2]*=-1;
	MatrixMultiplication(point,solve);
}
void LineTransformation()
{
	float wx,wy,rx,ry;
	cout<<"������Ҫ���ڵĵ�1�����꣨x,y����"<<endl;
	cin>>wx>>wy;
	cout<<"������Ҫ���ڵĵ�2�����꣨x,y����"<<endl;
	cin>>rx>>ry;
	float solve1[4][4]={
		{0,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,-wx,-wy,1}
	};
	MatrixMultiplication(point,solve1);
	float angle=atan((wy-ry)*1.0/(wx-rx));
//	cout<<angle<<endl;
	float solve2[4][4]={
		{0,0,0,0},
		{0,cos(-angle),sin(-angle),0},
		{0,-sin(-angle),cos(-angle),0},
		{0,0,0,1}
	};
	MatrixMultiplication(point,solve2);
	cout<<"ƽ�Ʊ任������1"<<endl;
	cout<<"���ű任������2"<<endl;
	cout<<"�ԳƱ任������3"<<endl;
	cout<<"���б任������4"<<endl;
	cin>>judge;
	if(judge==1)
	{
		float rm;
		cout<<"������Ҫƽ�Ƶľ��룺"<<endl;
		cin>>rm;
		float solve3[4][4]={
			{0,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,rm,0,1}
		};
		MatrixMultiplication(point,solve3);
	}
	else if(judge==2)
	{
		float scale;
		cout<<"������Ҫ���ŵı�����"<<endl;
		cin>>scale;
		float solve3[4][4]={
			{0,0,0,0},
			{0,scale,0,0},
			{0,0,1,0},
			{0,0,0,1}
		};
		MatrixMultiplication(point,solve3);
	}
	else if(judge==3)
	{
		float solve3[4][4]={
			{0,0,0,0},
			{0,1,0,0},
			{0,0,-1,0},
			{0,0,0,1}
		};
		MatrixMultiplication(point,solve3);
	}
	else
	{
		float angle;
		cout<<"������Ҫ���еĽǶȣ�"<<endl;
		cin>>angle;
		float solve3[4][4]={
			{0,0,0,0},
			{0,1,0,0},
			{0,tan(angle*PI/180.0f),1,0},
			{0,0,0,1}
		};
		cout<<"������÷����ϽǶȵķ���1Ϊ������2Ϊ������"<<endl;
		cin>>judge;
		if(judge==2) solve3[2][1]*=-1;
		MatrixMultiplication(point,solve3);
	}
	float solve4[4][4]={0};
	MatrixInverse(solve2,solve4);
	MatrixMultiplication(point,solve4);
	solve1[3][1]*=-1,solve1[3][2]*=-1;
	MatrixMultiplication(point,solve1);
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0); 
    glBegin(GL_POLYGON);
    for(int i=1;i<=n;i++)
    {
    	glVertex2f((GLfloat)point[i][1]/10.0-0.5, (GLfloat)point[i][2]/10.0-0.5);
	}
    glEnd();
    glFlush();
}
void solve1()
{
	cout<<"ƽ�Ʊ任������1"<<endl;
	cout<<"��ת�任������2"<<endl;
	cout<<"���ű任������3"<<endl;
	cout<<"�ԳƱ任������4"<<endl;
	cout<<"���б任������5"<<endl;
	cin>>judge;
	if(judge==1)
	{
		Translation();
	}
	else if(judge==2)
	{
		Spin();
	}
	else if(judge==3)
	{
		Zoom();
	}
	else if(judge==4)
	{
		Symmetry();
	}
	else
	{
		WrongCut();
	}
}
void solve2()
{
	cout<<"�������һ��ı任������1"<<endl;
	cout<<"�������һ����ı任������2"<<endl;
	cin>>judge;
	if(judge==1)
	{
		PointTransformation();
	}
	else
	{
		LineTransformation();
	}
}
int main(int argc, char *argv[])
{
	cout<<"���������εĶ�����Ŀn(n>=3):"<<endl;
	cin>>n;
	cout<<"�밴˳������������������"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>P[i].fi>>P[i].se;
	}
	for(int i=1;i<=n;i++)
	{
		point[i][1]=P[i].fi,point[i][2]=P[i].se,point[i][3]=1;
	}
	cout<<"�������α任������1�����ϱ任������2��ԭʼ��״��ʾ������3��"<<endl;
	cin>>judge;
	if(judge==1)
	{
		solve1();
	}
	else if(judge==2) 
	{
		solve2();
	}
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("����ͼ��");
    glutDisplayFunc(&myDisplay);
    glutMainLoop(); 
    return 0;
}
