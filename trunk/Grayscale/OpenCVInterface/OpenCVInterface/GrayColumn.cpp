// GrayColumn.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "GrayColumn.h"
#include "afxdialogex.h"


// GrayColumn dialog

IMPLEMENT_DYNAMIC(GrayColumn, CDialogEx)

GrayColumn::GrayColumn(CWnd* pParent /*=NULL*/)
	: CDialogEx(GrayColumn::IDD, pParent)
	, col(false),parent(pParent)
{

}

GrayColumn::~GrayColumn()
{
}

void GrayColumn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GrayColumn, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// GrayColumn message handlers


void GrayColumn::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	if(col)
	{

		col=false;
	}

	// Do not call CDialogEx::OnPaint() for painting messages
}

void GrayColumn::CalcCol(int a[256],int xc)
{
	v=a;
	x=xc;
	col=true;
}

void GrayColumn::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	//CMenu* mmenu =parent->GetMenu();
	//CMenu* submenu =mmenu->GetSubMenu(1);
	//UINT state = submenu->GetMenuState(ID_TOOLS_GRAYLEVELCOLUMN,MF_BYCOMMAND);
	//ASSERT(state != 0xFFFFFFFF);
	//submenu->CheckMenuItem(ID_TOOLS_GRAYLEVELCOLUMN,MF_UNCHECKED|MF_BYCOMMAND);
	parent->Invalidate();

	CDialogEx::OnClose();
}
