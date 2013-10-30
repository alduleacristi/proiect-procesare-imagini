// GrayRow.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "GrayRow.h"
#include "afxdialogex.h"


// GrayRow dialog

IMPLEMENT_DYNAMIC(GrayRow, CDialogEx)

GrayRow::GrayRow(CWnd* pParent /*=NULL*/)
	: CDialogEx(GrayRow::IDD, pParent)
	, row(false)
{

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


// GrayRow message handlers


void GrayRow::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	if(row)
	{

		row=false;
	}

	// Do not call CDialogEx::OnPaint() for painting messages
}

void GrayRow::CalcRow(int a[256], int yc)
{
	v=a;
	y=yc;
	row=true;
}
