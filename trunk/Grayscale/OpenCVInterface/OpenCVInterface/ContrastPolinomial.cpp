#include "ContrastPolinomial.h"
#include "stdafx.h";

const double a = -2.0/(255.0*255.0) , b = 3.0/255.0;

double PolinomialFunction(double r)
{
	return a*r*r*r + b*r*r;
}

double* CreateLookUpForContrast()
{
	double *LookUp = new double[256];
	for(int i=0;i<256;i++)
		LookUp[i] = PolinomialFunction(i);
	return LookUp;
}