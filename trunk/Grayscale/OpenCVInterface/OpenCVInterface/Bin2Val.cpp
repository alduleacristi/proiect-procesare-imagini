// Bin2Val.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "Bin2Val.h"
#include "afxdialogex.h"


// Bin2Val dialog

IMPLEMENT_DYNAMIC(Bin2Val, CDialogEx)

Bin2Val::Bin2Val(CWnd* pParent /*=NULL*/)
	: CDialogEx(Bin2Val::IDD, pParent)
{

}

Bin2Val::~Bin2Val()
{
}

void Bin2Val::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Bin2Val, CDialogEx)
	ON_BN_CLICKED(IDOK, &Bin2Val::OnBnClickedOk)
END_MESSAGE_MAP()


// Bin2Val message handlers


void Bin2Val::OnBnClickedOk()
{
	CString s1,s2;

	GetDlgItem(IDC_T1)->GetWindowText(s1);
	GetDlgItem(IDC_T2)->GetWindowText(s2);

	t1=atoi(s1);
	t2=atoi(s2);

	CDialogEx::OnOK();
}

int Bin2Val::getT1(void)
{
	return t1;
}

int Bin2Val::getT2(void)
{
	return t2;
}
