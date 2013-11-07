#pragma once

#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include <fstream>
#include <vector>

using namespace cv;

int** AplicaSx(Mat image);

int** AplicaSy(Mat& image,Mat& resultImage);

std::vector<vector<double>> CalculeazaGradient(std::vector<std::vector<int>> rezSx,std::vector<std::vector<int>> rezSy);

void ScrieLaFisier(char* nume , std::vector<std::vector<int>> rez , int n , int m);

int DeterminaDirectie(double dx,double dy);