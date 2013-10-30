#pragma once
#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace cv;

class Tools
{
public:
	static Mat gammaCorrection(Mat& mainImg, double gamma);
	static Mat zoom(Mat& im, int x, int y);
	static Mat binarization(Mat& im, int t);
	static Mat binarization2(Mat& im , int t1, int t2); 
	static Mat increaseLuminosity(Mat& im, int b);
	static Mat decreaseLuminosity(Mat& im, int b);
	static Mat logaritm(Mat& im);
	static Mat inverseLogaritm(Mat& im);
	static int* calcHisto(Mat& im);
	static int* calcRow(Mat& im, int y);
	static int* calcCol(Mat& im,int x);
	~Tools(void);
};

