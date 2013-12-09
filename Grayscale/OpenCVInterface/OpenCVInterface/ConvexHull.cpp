#include "StdAfx.h"
#include "ConvexHull.h"


ConvexHull::ConvexHull(void)
{
}

int Cotire(const cv::Point A, const cv::Point B, const cv::Point C)
{
	double rez=(B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
	if(rez==0)
		return 0; 
	if(rez>0)
		return 1; //cotire dreapta
	return -1;  //cotire stanga
}

void ConvexHull::graham(std::vector<cv::Point> p, std::vector<cv::Point>& convexHull)
{
	p0=p[0];  
	for (int i=1; i<p.size();i++)
		if (p[i].y < p0.y || (p[i].y == p0.y && p[i].x < p0.x ))
		{	
			cv::Point aux=p[0];
			p[0]=p[i];
			p[i]=aux;
			p0=p[0];
		}

   for(int i=1;i<p.size()-1;i++) 
	for(int j=i+1;j<p.size();j++)
	{
		int rez=Cotire(p0,p[i],p[j]); 
		if(rez<0)
		{
			cv::Point aux;
			aux=p[i];
			p[i]=p[j];
			p[j]=aux;
		}
		//if(rez==0)
		//{
		//	double dist1=sqrt(pow((p0.x-p[i].x),2.)+pow((p0.y-p[i].y),2.));
		//	double dist2=sqrt(pow((p0.x-p[j].x),2.)+pow((p0.y-p[j].y),2.));;
		//	if(dist1<dist2)
		//	{
		//		p.erase(p.begin()+i);
		//		//j=i+1;
		//	}
		//	else
		//	{
		//		p.erase(p.begin()+j);
		//		//i=0;
		//	}
		//}
	}
	std::vector<cv::Point> chull(p.begin(), p.begin()+3);
			
	for (int i=3; i<p.size(); ++i)
	{
		while (chull.size() >= 2 && Cotire(chull[chull.size()-2], chull[chull.size()-1], p[i])<=0)
		{
			chull.erase(chull.end()-1);
		}
		chull.push_back(p[i]);
	}

	convexHull = chull;
}

ConvexHull::~ConvexHull(void)
{
}
