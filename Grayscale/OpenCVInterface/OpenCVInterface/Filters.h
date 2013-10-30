#pragma once
#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace cv;

class Filters
{
public:
	static Mat gaussianFilter(Mat& im, double sigma);
	~Filters(void);
};

