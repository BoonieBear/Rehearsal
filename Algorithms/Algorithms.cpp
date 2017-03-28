// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define NewTonRecrusive//OneWayLinkReverse,NewTonRecrusive
#include<fstream> 
#include<iostream> 
#include <iomanip> 
#include<cmath>  
#include <cstdlib>  
#define N 3                  
const int       N2=N*N;
#define eps     0.00001      // 收敛精度 
#define Max     2000        // 最大迭代次数
using namespace std;
#ifdef OneWayLinkReverse
#include"LinkList.h"
#endif
int main()
{
#ifdef OneWayLinkReverse
	OneWayLinkNode* head = InitList(10);
	if (head==NULL)
	{
		printf("Init list failed!\n");
		return 0;
	}
	WalkList(head);
	head = LinkNodeReverse(head);
	WalkList(head);
	CleanList(head);
#endif // OneWayLinkReverse
#ifdef NewTonRecrusive
	double x0[N], y[N], x1[N], es, esmax, jacobi[N][N], aij,tmp;
	int i, j, k, it = 0, iter = 0;       
	cout << "**********   Please input X0   ***********" << endl;    // 技巧一：为保证jacobi矩阵尽快收敛，初值最好在 0 附近 
	for(i=0;i<N;i++)  cin>>x0[i];  
	cout<<"输入的初值为："<<endl; 
	for(i=0;i<N;i++) cout<<x0[i]<<"\t";  
	cout<<endl; 
	do {
		it++;
		cout << endl;
							  //计算jacobi矩阵的值 
			jacobi[0][0]=0; 
			jacobi[0][1]=0.3*x0[2]; 
			jacobi[0][2]=0.3*x0[1]-2*x0[2]; 
			jacobi[1][0]=-0.2*x0[0]+0.8*x0[2]; 
			jacobi[1][1]=0;  
			jacobi[1][2]=0.8*x0[0]-1; 
			jacobi[2][0]=0.3+0.7*x0[1]; 
			jacobi[2][1]=-x0[1]+0.7*x0[0];
			jacobi[2][2]=0; 

		aij = 0;  
		for (i = 0; i<N; i++)//计算jacobi矩阵元素的平方和aij 
			for(j=0;j<N;j++)  
				aij=aij+jacobi[i][j]*jacobi[i][j]; 
		if(aij>1) 
		{
			cout << "Sorry,   aij>1" << endl;
			k = rand() % 3;
		x0[k] = ((double)rand()) / RAND_MAX;
		cout << endl << "由计算机第 " << it << " 次随机产生初值：" << endl; 
		cout << "    "; 
		for (i = 0; i<N; i++)  
			cout << x0[i] << "\t";  
		cout << endl;
		}
	} while (aij>1);
	for (i = 0; i<N; i++) 
		x1[i] = x0[i];
	cout << "***************  牛顿迭代如下  ***************" << endl; 
	cout << "迭代次数    x1\t\t    x2\t\t    x3" << endl << endl; 
	do {
		iter = iter + 1;  
		cout << "  " << iter << "   " << "\t"; 
		for (i = 0; i<N; i++) 
			cout << x1[i] << "\t"; 
		cout << endl;
		y[0] = 0.3*x1[1] * x1[2] - x1[2] * x1[2] + 0.6;                
		y[1] = -0.1*x1[0] * x1[0] + 0.8*x1[0] * x1[2] - x1[2] + 0.4;  
		y[2] = 0.3*x1[0] - 0.5*x1[1] * x1[1] + 0.7*x1[0] * x1[1] + 0.5;
		esmax = 0.0; 
		for (i = 0; i<N; i++) 
		{ 
			es = y[i] - x1[i];  
		if (fabs(es)>fabs(esmax)) 
			esmax = es; 
		}  
		if (fabs(esmax) < eps)
		{
			cout << endl << endl << "方程组的解为 : " << endl;
			for (i = 0; i < N; i++)
			{
				cout << x1[i] << "\t";
			}
			cout << endl << endl;
			break;
		}
		for (i = 0; i < N; i++)
			x1[i] = y[i];			
	} while (iter < Max);
#endif // NewTonRecrusive

	cin >> tmp;
    return 0;
}

