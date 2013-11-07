#include "stdafx.h"
#include "CannyOperator.h"
#include <vector>

int** AplicaSx(Mat image)
{
	int** rezSx = new int*[image.rows];
	for(int i=0;i<image.rows;i++)
		rezSx[i] = new int[image.cols];

	for(int i=1;i<image.rows-1;i++)
		for(int j=1;j<image.cols-1;j++){
			rezSx[i][j] = image.at<uchar>(i+1,j-1) - image.at<uchar>(i-1,j-1) + 2*image.at<uchar>(i+1,j) - 2*image.at<uchar>(i-1,j) + image.at<uchar>(i+1,j+1) - image.at<uchar>(i-1,j+1);
		}

	return rezSx;
}

int** AplicaSy(Mat& image,Mat& resultImage)
{
	int** rezSy = new int*[image.rows];
	for(int i=0;i<image.rows;i++)
		rezSy[i] = new int[image.cols];

	

	return rezSy;
}

std::vector<std::vector<double>> CalculeazaGradient(std::vector<std::vector<int>> rezSx,std::vector<std::vector<int>> rezSy)
{
	std::vector<std::vector<double>> rez;

	for(int i=0;i<rezSx.size();i++)
	{
		std::vector<double> aux;
		for(int j=0;j<rezSx[0].size();j++)
			aux.push_back(std::sqrt((double) rezSx[i][j]*rezSx[i][j] + rezSy[i][j]*rezSy[i][j]));
		rez.push_back(aux);
	}
	
	return rez;
}

void ScrieLaFisier(char* nume , std::vector<std::vector<int>> rez , int n , int m)
{
	std::ofstream f;
	f.open(nume,std::ios::out);
	for(int i=1;i<rez.size();i++)
	{
		for(int j=1;j<rez[0].size();j++)
			f<<rez[i][j]<<" ";
		f<<std::endl;
	}
	f.close();
}

int DeterminaDirectie(double dx,double dy)
{
	const double PI=3.1415926535;
	double rez = std::atan2(dx,dy);

	if((rez <= -3*PI/8 && rez >= -5*PI/8) || (rez >= 3*PI/8 && rez <= 5*PI/8))
		return 1;

	if((rez <= -5*PI/8 && rez >= -7*PI/8) || (rez <= 3*PI/8 && rez >= PI/8))
		return 2;

	if((rez <= -7*PI/8 && rez >= -PI) || (rez >= 7*PI/8 && rez <= PI) || (rez >= -PI/8 && rez <= PI/8))
		return 3;

	if((rez >= 5*PI/8 && rez <= 7*PI/8) || (rez >= -3*PI/8 && rez <= -PI/8))
		return 4;
}