// FiltruMedianCristi.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "FiltruMedianCristi.h"
#include "afxdialogex.h"


// FiltruMedianCristi dialog

IMPLEMENT_DYNAMIC(FiltruMedianCristi, CDialogEx)

FiltruMedianCristi::FiltruMedianCristi(CWnd* pParent /*=NULL*/)
	: CDialogEx(FiltruMedianCristi::IDD, pParent)
{

}

FiltruMedianCristi::~FiltruMedianCristi()
{
}

void FiltruMedianCristi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit1);
}


BEGIN_MESSAGE_MAP(FiltruMedianCristi, CDialogEx)
	ON_BN_CLICKED(IDOK, &FiltruMedianCristi::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &FiltruMedianCristi::OnBnClickedCancel)
END_MESSAGE_MAP()


// FiltruMedianCristi message handlers


void FiltruMedianCristi::OnBnClickedOk()
{
	CString s;
	edit1.GetWindowTextA(s);
	val=atoi(s);
	CDialogEx::OnOK();
}


void FiltruMedianCristi::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

int FiltruMedianCristi::getVal()
{
	return val;
}