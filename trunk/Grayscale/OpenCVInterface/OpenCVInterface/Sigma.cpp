// Sigma.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "Sigma.h"
#include "afxdialogex.h"


// Sigma dialog

IMPLEMENT_DYNAMIC(Sigma, CDialogEx)

	Sigma::Sigma(CWnd* pParent /*=NULL*/)
	: CDialogEx(Sigma::IDD, pParent)
{

}


double Sigma::getSigma()
{
	return si;
}


Sigma::~Sigma()
{
}

void Sigma::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Sigma, CDialogEx)
	ON_BN_CLICKED(IDOK, &Sigma::OnBnClickedOk)
END_MESSAGE_MAP()


// Sigma message handlers

void Sigma::OnBnClickedOk()
{
	CString st;
	GetDlgItem(IDC_SIG)->GetWindowText(st);

	si=atof(st);

	CDialogEx::OnOK();
}
