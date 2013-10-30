// GammaValue.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "GammaValue.h"
#include "afxdialogex.h"


// GammaValue dialog

IMPLEMENT_DYNAMIC(GammaValue, CDialogEx)

GammaValue::GammaValue(CWnd* pParent /*=NULL*/)
	: CDialogEx(GammaValue::IDD, pParent)
{

}

GammaValue::~GammaValue()
{
}

void GammaValue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GammaValue, CDialogEx)
	ON_BN_CLICKED(IDOK, &GammaValue::OnBnClickedOk)
END_MESSAGE_MAP()


// GammaValue message handlers


void GammaValue::OnBnClickedOk()
{
	CString s;
	GetDlgItem(IDC_GAMMA)->GetWindowText(s);
	
	gamma=atof(s);

	CDialogEx::OnOK();
}


double GammaValue::getGamma(void)
{
	return gamma;
}
