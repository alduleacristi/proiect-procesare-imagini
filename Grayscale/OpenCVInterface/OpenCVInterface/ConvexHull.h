#pragma once
#include <opencv2\core\core.hpp>
#include<queue>

#define PI 3.14159265359

class ConvexHull
{
public:
	ConvexHull(void);
	void graham(std::vector<cv::Point> p, std::vector<cv::Point>& convexHull);
	~ConvexHull(void);
private:
	cv::Point p0;
};

