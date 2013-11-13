#include "StdAfx.h"
#include "Filters.h"
//#include<sstream>

//using namespace std;

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

Mat Filters::sobelDirectional(Mat& im) 
{
	Mat rez;
	im=gaussianFilter(im,1.5);
	rez.create(im.rows,im.cols,CV_MAKETYPE(im.depth(),1));
	double fx[3][3]={{-1,0,1},
				     {-2,0,2},
					 {-1,0,1}
					};
	double fy[3][3]={{1,2,1},
					 {0,0,0},
					 {-1,-2,-1}
					};

	for(int j=0;j<im.cols;j++)
	{
		rez.at<uchar>(0,j)=0;
		rez.at<uchar>(im.rows-1,j)=0;
	}

	for(int i=1;i<im.rows-2;i++)
	{
		rez.at<uchar>(i,0)=0;
		rez.at<uchar>(i,im.cols-1)=0;
	}

	for (int y=1;y<im.rows-1;y++) 
	{
		for (int x=1;x<im.cols-1;x++) 
		{
			double sum_x = 0.0, sum_y=0.0;
			for (int j=-1;j<=1;j++) 
			{
				for (int i=-1;i<=1;i++) 
				{
					sum_x+=fx[j+1][i+1]*im.at<uchar>(y+i,x+j);
					sum_y+=fy[j+1][i+1]*im.at<uchar>(y+i,x+j);
				}
			}

			double sum=sqrt(pow(sum_x,2)+pow(sum_y,2));
			double u=atan2(sum_y,sum_x);

			if(u>=-3*PI/4 && u<=-PI/4) 
			{
				if(sum>255)
					rez.at<uchar>(y,x)=255;
				else
					if(sum<TH)
						rez.at<uchar>(y,x)=0;
					else
						rez.at<uchar>(y,x)=sum;
			}
			else
			{
				if(u>=PI/4 && u<=3*PI/4)
				{
					if(sum>255)
						rez.at<uchar>(y,x)=255;
					else
						if(sum<TH)
						rez.at<uchar>(y,x)=0;
					else
						rez.at<uchar>(y,x)=sum;
				}
				else
					rez.at<uchar>(y,x)=0;
			}

		}
	}

	return rez;
}

Filters::~Filters(void)
{
	//FreeConsole();
}
