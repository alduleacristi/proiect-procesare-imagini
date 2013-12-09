// GrayRow.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "GrayRow.h"
#include "afxdialogex.h"


// GrayRow dialog

IMPLEMENT_DYNAMIC(GrayRow, CDialogEx)

	GrayRow::GrayRow(Mat image,CWnd* pParent /*=NULL*/)
	: CDialogEx(GrayRow::IDD, pParent)
	, m_image(image),
	x_coord(0),
	y_coord(0),
	parent(pParent)
	, gcheck(false)
{
	int i;
	grey_lev=new int[image.cols];
	for(i=0;i<image.cols;i++)
		grey_lev[i]=0;
}

GrayRow::~GrayRow()
{
}

void GrayRow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GrayRow, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void GrayRow::SetCoord(int x, int y)
{
	x_coord=x;
	y_coord=y;
}


int GrayRow::GetY(void)
{
	return y_coord;
}

int GrayRow::GetX(void)
{
	return x_coord;
}


// GrayRow message handlers


void GrayRow::OnPaint()
{
	CPaintDC dc(this);
	CPen *pen,*pen2;
	if(gcheck==true){

	int linie,j,coloana;
	if(!m_image.empty())
		if(x_coord>=0 && x_coord<m_image.cols && y_coord>=0 && y_coord<m_image.rows)
		{
			linie=y_coord;
			for(j=0;j<m_image.cols;j++)
				grey_lev[j] = m_image.at<uchar>(y_coord,j);

		}

	CRect rect;
	GetClientRect(&rect);
	pen=new CPen(PS_SOLID,1,RGB(0,0,255));
	pen2=new CPen(PS_DASH,1,RGB(0,0,255));
	dc.SelectObject(pen);
	dc.MoveTo(27,320);
	for(j=0;j<m_image.cols;j++)
		dc.LineTo(27+j,65+255-grey_lev[j]);
	//dc.LineTo(27+m_image->GetWidth(),320);
	dc.MoveTo(27,320);
	dc.LineTo(27+m_image.cols+30,320);
	dc.MoveTo(27,320);
	dc.LineTo(27,10);
	dc.SelectObject(pen2);
	dc.MoveTo(27,65);
	dc.LineTo(27+m_image.cols,65);
	dc.TextOut(17, 324, "0");
	dc.TextOut(5, 55, "255");
	CString str;
	str.Format("%d",m_image.cols);
	dc.TextOut(7+m_image.cols+10, 324, str);
	delete pen;
	}
	else
	{
		int linie,j,coloana;
	if(!m_image.empty())
		if(x_coord>=0 && x_coord<m_image.cols && y_coord>=0 && y_coord<m_image.rows)
		{
			linie=y_coord;
			for(j=0;j<m_image.rows;j++)
				grey_lev[j] = m_image.at<uchar>(j,x_coord);

		}

	CRect rect;
	GetClientRect(&rect);
	pen=new CPen(PS_SOLID,1,RGB(0,0,255));
	pen2=new CPen(PS_DASH,1,RGB(0,0,255));
	dc.SelectObject(pen);
	dc.MoveTo(27,320);
	for(j=0;j<m_image.rows;j++)
		dc.LineTo(27+j,65+255-grey_lev[j]);
	//dc.LineTo(27+m_image->GetWidth(),320);
	dc.MoveTo(27,320);
	dc.LineTo(27+m_image.rows+30,320);
	dc.MoveTo(27,320);
	dc.LineTo(27,10);
	dc.SelectObject(pen2);
	dc.MoveTo(27,65);
	dc.LineTo(27+m_image.cols,65);
	dc.TextOut(17, 324, "0");
	dc.TextOut(5, 55, "255");
	CString str;
	str.Format("%d",m_image.cols);
	dc.TextOut(7+m_image.cols+10, 324, str);
	delete pen;
	}

}

void GrayRow::setGCheck(bool check)
{
	this->gcheck = check;
}

bool GrayRow::getGCheck(void)
{
	return gcheck;
}

//void GrayRow::CalcRow(int a[256], int yc, int c ,int r)
//{
//	cols=c;
//	rows=r;
//	v=a;
//	y=yc;
//	row=true;
//}
