// LumVal.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "LumVal.h"
#include "afxdialogex.h"


// LumVal dialog

IMPLEMENT_DYNAMIC(LumVal, CDialogEx)

LumVal::LumVal(CWnd* pParent /*=NULL*/)
	: CDialogEx(LumVal::IDD, pParent)
{

}

LumVal::~LumVal()
{
}

void LumVal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LumVal, CDialogEx)
	ON_BN_CLICKED(IDOK, &LumVal::OnBnClickedOk)
END_MESSAGE_MAP()


// LumVal message handlers


void LumVal::OnBnClickedOk()
{
	CString s;
	GetDlgItem(IDC_B)->GetWindowText(s);
	b=atoi(s);
	
	CDialogEx::OnOK();
}

int LumVal::getB(void)
{
	return b;
}
