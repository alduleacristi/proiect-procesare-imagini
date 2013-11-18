// MaskDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "MaskDlg.h"
#include "afxdialogex.h"


// CMaskDlg dialog

IMPLEMENT_DYNAMIC(CMaskDlg, CDialogEx)

CMaskDlg::CMaskDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMaskDlg::IDD, pParent)
{
	windowWasClosed = false;
}

CMaskDlg::~CMaskDlg()
{
}

void CMaskDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMaskDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMaskDlg::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMaskDlg message handlers



bool CMaskDlg::DimensionIsValid()
{
	if(n1.GetLength()==0)
		return false;
	for(int i=0; i<n1.GetLength(); i++) 
		if(n1[i] == '.')
			return false;
    if(atoi(n1)%2==0)
		return false;
    return true;
}


void CMaskDlg::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT1)->GetWindowText(n1);
	if( DimensionIsValid()!=true)
		MessageBox("Incorect parameter. Try again!");
	CDialogEx::OnOK();
}


void CMaskDlg::OnClose()
{
	windowWasClosed = true;
	CDialogEx::OnClose();
}
