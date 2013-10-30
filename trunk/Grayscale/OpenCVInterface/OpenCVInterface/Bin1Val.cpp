// Bin1Val.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "Bin1Val.h"
#include "afxdialogex.h"


// Bin1Val dialog

IMPLEMENT_DYNAMIC(Bin1Val, CDialogEx)

Bin1Val::Bin1Val(CWnd* pParent /*=NULL*/)
	: CDialogEx(Bin1Val::IDD, pParent)
{

}

Bin1Val::~Bin1Val()
{
}

void Bin1Val::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Bin1Val, CDialogEx)
	ON_BN_CLICKED(IDOK, &Bin1Val::OnBnClickedOk)
END_MESSAGE_MAP()


// Bin1Val message handlers


void Bin1Val::OnBnClickedOk()
{
	CString s;
	GetDlgItem(IDC_T)->GetWindowText(s);

	t=atoi(s);

	CDialogEx::OnOK();
}


int Bin1Val::getT(void)
{
	return t;
}
