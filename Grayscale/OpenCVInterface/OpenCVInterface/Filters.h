#pragma once
#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace cv;

#define E 0.136
#define e 2.718281828459045
#define PI 3.14159265359
#define TH 127

class Filters
{
public:
	static Mat gaussianFilter(Mat& im, double sigma);
	static Mat sobelDirectional(Mat& im);
	~Filters(void);
};

