#pragma once

#include "MedianFilter.h"
#include "stdafx.h";

int partitionare(int st,int dr,int* v)
{
    int j=dr+1,i=st-1,ok=1,k;

    int pivot=v[st];

    do
    {
        do
        {
            j--;
        }
        while(v[j] > pivot);

        do
        {
            i++;
        }
        while(v[i] < pivot);

        if(i<j)
            {
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        else
            {
                ok=0;
                k=j;
            }
    }
    while(ok==1);
    return k;
}

int statistici(int k,int st,int dr,int* v)
{
    int p;
    if(st==dr)
        return v[k];
    else
        {
			p=partitionare(st,dr,v);
            if(k<p)
                statistici(k,st,p,v);
            else
                statistici(k,p+1,dr,v);
        }
}
