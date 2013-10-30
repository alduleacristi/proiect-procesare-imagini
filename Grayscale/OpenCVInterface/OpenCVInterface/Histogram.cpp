// Histogram.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "Histogram.h"
#include "afxdialogex.h"


// Histogram dialog

IMPLEMENT_DYNAMIC(Histogram, CDialogEx)

Histogram::Histogram(CWnd* pParent /*=NULL*/)
	: CDialogEx(Histogram::IDD, pParent), h(false)
{

}

Histogram::~Histogram()
{
}

void Histogram::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Histogram, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Histogram message handlers

void Histogram::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	if(h)
	{
		CRect r;
		GetClientRect(&r);

		CPen *pen=new CPen(PS_SOLID,2,RGB(0,0,0));
		dc.SelectObject(pen);

		dc.MoveTo(20,10);
		dc.LineTo(20,r.Height()-10);
		dc.MoveTo(10,r.Height()-20);
		dc.LineTo(r.Width()-20,r.Height()-20);

		delete pen;
		
		double scalarX=(r.Width()-40)/255;
		double max=0;
		for(int i=0; i<256;i++)
		{	
			if (max<v[i])
			{
				max=v[i];
			}
		}

		double scalarY=(r.bottom-40)/max;

		dc.MoveTo(22,r.Height()-20);
		dc.LineTo(20,(int)(r.Height()-20-(int)(scalarY*v[0]+0.5)));

		int mut=22;
		for(int i=1; i<256;i++)
		{
			dc.MoveTo(i+mut-1,r.Height()-20);
			dc.LineTo(i+mut-1,(int)(r.Height()-20-(int)(scalarY*v[i]+0.5)));
			mut=mut-1+(int)(scalarX+0.5);
		}
		
		h=false;
	}
	// Do not call CDialogEx::OnPaint() for painting messages
}

void Histogram::setHisto(int a[256])
{
	v=a;
	h=true;
}
