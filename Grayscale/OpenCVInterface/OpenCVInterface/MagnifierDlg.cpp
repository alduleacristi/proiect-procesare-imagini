// MagnifierDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "MagnifierDlg.h"
#include "afxdialogex.h"


// MagnifierDlg dialog

IMPLEMENT_DYNAMIC(MagnifierDlg, CDialogEx)

	MagnifierDlg::MagnifierDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MagnifierDlg::IDD, pParent)
{

}

MagnifierDlg::~MagnifierDlg()
{
}

void MagnifierDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MagnifierDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MagnifierDlg message handlers
BOOL MagnifierDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	rezim.create(9,9,CV_8UC1);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			rezim.at<uchar>(i,j)=255;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void MagnifierDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

	CBrush *br;
	CPen *pen;

	CString color;

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			br=new CBrush(RGB(rezim.at<uchar>(i,j),rezim.at<uchar>(i,j),rezim.at<uchar>(i,j)));
			pen=new CPen(PS_SOLID,1,RGB(rezim.at<uchar>(i,j),rezim.at<uchar>(i,j),rezim.at<uchar>(i,j)));

			dc.SelectObject(br);
			dc.SelectObject(pen);

			dc.Rectangle(i*25,j*25,i*25+25,j*25+25);
			color.Format("%d",rezim.at<uchar>(i,j));
			dc.SetTextColor(RGB(0,255,0));
			dc.SetBkColor(RGB(rezim.at<uchar>(i,j),rezim.at<uchar>(i,j),rezim.at<uchar>(i,j)));
			dc.TextOutA(i*25,j*25,color);


			delete br;
			delete pen;
		}
		// Do not call CDialogEx::OnPaint() for painting messages
}

void MagnifierDlg::Zoom(Mat& im)
{
	rezim=im;
}
