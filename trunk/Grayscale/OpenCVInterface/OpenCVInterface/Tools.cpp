#include "StdAfx.h"
#include "Tools.h"

Mat Tools::gammaCorrection(Mat& mainImg, double gamma)
{
	Mat rezImg;

	rezImg.create(mainImg.rows,mainImg.cols,CV_MAKETYPE(mainImg.depth(),1));
	
	byte *lut;
	lut=new byte[256];
	lut[0]=0;
	lut[255]=255;
	
	double a;
	a=255/(pow(255,gamma));

	for(int i=1;i<255;i++)
	{
		lut[i]=a*pow(i,gamma);
	}

	int w=mainImg.cols;
	int h=mainImg.rows;

	for(int i=0;i<h;i++)
	 for(int j=0;j<w;j++)
	 {
		 rezImg.at<uchar>(i,j)=lut[mainImg.at<uchar>(i,j)];
	 }
	
	 delete lut;
	 return rezImg;
}

Mat Tools::zoom(Mat& im, int x, int y)
{
	Mat rez;

	rez.create(9,9,CV_MAKETYPE(im.depth(),1));
	int startX=x-4, startY=y-4;
	int x1=0, y1=0;
	for(int i=startX; i<x+5;i++)
	{ 
		for(int j=startY; j<y+5;j++)
		{
			if(i>=0 && j>=0 && i<im.rows && j<im.cols)
			{
				rez.at<uchar>(y1,x1)=im.at<uchar>(i,j);
				y1++;
			}
			else
			{
				rez.at<uchar>(y1,x1)=255;
				y1++;
			}
		}
		y1=0; x1++;
	}

	return rez;
}

Mat Tools::binarization(Mat& im, int t)
{
	Mat rez;
	rez.create(im.rows,im.cols,CV_MAKETYPE(im.depth(),1));

	for(int i=0;i<im.rows;i++)
		for(int j=0;j<im.cols;j++)
			if(im.at<uchar>(i,j)>t)
				rez.at<uchar>(i,j)=255;
			else
				rez.at<uchar>(i,j)=0;

	return rez;
}

Mat Tools::binarization2(Mat& im , int t1, int t2)
{
	Mat rez;
	rez.create(im.rows,im.cols,CV_MAKETYPE(im.depth(),1));

	for(int i=0;i<im.rows;i++)
		for(int j=0;j<im.cols;j++)
			if(im.at<uchar>(i,j)<=t1 || im.at<uchar>(i,j)>t2)
				rez.at<uchar>(i,j)=0;
			else
				rez.at<uchar>(i,j)=255;

	return rez;
}

Mat Tools::increaseLuminosity(Mat& im,int b)
{
	Mat rez;
	rez.create(im.rows,im.cols,CV_MAKETYPE(im.depth(),1));

	byte *lut;
	lut=new byte[256];
	for(int i=0;i<255-b;i++)
		lut[i]=i+b;
	for(int i=255-b;i<256;i++)
		lut[i]=255;

	for(int i=0;i<im.rows;i++)
	 for(int j=0;j<im.cols;j++)
	 {
		 rez.at<uchar>(i,j)=lut[im.at<uchar>(i,j)];
	 }

	 delete lut;
	 return rez;
}

Mat Tools::decreaseLuminosity(Mat& im, int b)
{
	Mat rez;
	rez.create(im.rows,im.cols,CV_MAKETYPE(im.depth(),1));

	byte *lut;
	lut=new byte[256];
	for(int i=b;i<256;i++)
		lut[i]=i-b;
	for(int i=0;i<b;i++)
		lut[i]=0;

	for(int i=0;i<im.rows;i++)
	 for(int j=0;j<im.cols;j++)
	 {
		 rez.at<uchar>(i,j)=lut[im.at<uchar>(i,j)];
	 }

	 delete lut;
	 return rez;
}

Mat Tools::logaritm(Mat& im)
{
	Mat rez;
	rez.create(im.rows,im.cols,CV_MAKETYPE(im.depth(),1));

	byte *lut;
	lut=new byte[256];

	double c;
	c=255/log(256.);

	for(int i=0;i<256;i++)
	{
		lut[i]=c*log(double(i+1));
	}

	for(int i=0;i<im.rows;i++)
	 for(int j=0;j<im.cols;j++)
	 {
		 rez.at<uchar>(i,j)=lut[im.at<uchar>(i,j)];
	 }

	delete lut;
	return rez;
}

Mat Tools::inverseLogaritm(Mat& im)
{
	Mat rez;
	rez.create(im.rows,im.cols,CV_MAKETYPE(im.depth(),1));

	byte *lut;
	lut=new byte[256];

	double c;
	c=255/log(256.);

	for(int i=0;i<256;i++)
	{
		lut[i]=exp(i/c)-1;
	}

	for(int i=0;i<im.rows;i++)
	 for(int j=0;j<im.cols;j++)
	 {
		 rez.at<uchar>(i,j)=lut[im.at<uchar>(i,j)];
	 }

	delete lut;
	return rez;

}

int* Tools::calcHisto(Mat& im)
{
	int* v=new int[256]();

	for(int i=0;i<im.rows;i++)
	 for(int j=0;j<im.cols;j++)
	 {
		 v[im.at<uchar>(i,j)]++;
	 }

	return v;
}

int* Tools::calcRow(Mat& im, int y)
{
	int* v=new int[256]();

	return v;
}

int* Tools::calcCol(Mat& im,int x)
{
	int* v=new int[256]();

	return v;
}

Tools::~Tools(void)
{
}
