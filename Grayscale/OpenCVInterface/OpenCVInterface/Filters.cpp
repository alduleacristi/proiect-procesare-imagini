#include "StdAfx.h"
#include "Filters.h"
#include<sstream>

using namespace std;

Mat Filters::gaussianFilter(Mat& im, double sigma)
{
	Mat rez=im.clone();

	int j=0;
	double val;
	int k;
	do
	{
		val=pow(e,-(pow(j,2.))/(2*(pow(sigma,2.))));
		j++;
	}
	while(val>E);

	k=j-1;

	double **h;
	int dim=2*k+1;
	h=new double*[dim];
	for(int i=0;i<dim;i++)
		h[i]=new double[dim];

	double sum=0;
	for(int i=-k;i<=k;i++)
		for(int j=-k;j<=k;j++)
		{
			h[k-i][k-j]=pow(e,-(pow(i,2.)+pow(j,2.))/(2*(pow(sigma,2.))));
			sum+=h[k-i][k-j];
		}

	/*AllocConsole();
	HANDLE h1=GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dw;
			
	stringstream ss;
	string s;
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			ss<<h[i][j]<<" ";
		}
		ss<<endl;
		s=ss.str();
		ss.clear();
		ss.str("");
		WriteConsole(h1,s.c_str(),s.size(),&dw,NULL);
	}*/

	for(int x=k;x<im.rows-k;x++)
	  for(int y=k;y<im.cols-k;y++)
	  {
		  double d=0;
		  for(int i=-k;i<=k;i++)
			  for(int j=-k;j<=k;j++)
			  {
				  d+=h[i+k][j+k]*im.at<uchar>(x+i,y+j);
			  }
			  rez.at<uchar>(x,y)=d/sum+0.5;
	  }

	for(int i=0;i<dim;i++)
	   delete h[i];
	delete h;

	return rez;
}

Filters::~Filters(void)
{
	//FreeConsole();
}
