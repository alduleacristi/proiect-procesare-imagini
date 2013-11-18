// ParametersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "ParametersDlg.h"
#include "afxdialogex.h"


// CParametersDlg dialog

IMPLEMENT_DYNAMIC(CParametersDlg, CDialogEx)

CParametersDlg::CParametersDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CParametersDlg::IDD, pParent)
{
	areNumbers = false;
	windowWasClosed = false;
}

CParametersDlg::~CParametersDlg()
{
}

void CParametersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CParametersDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CParametersDlg::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CParametersDlg message handlers


bool CParametersDlg::IsNumber(CString str)
{
	/*
		Verific daca "str" e numar:
			- daca are lungimea > 0
			- daca incepe sau se termina cu '.'
			- daca contine mai mult de 2 puncte
			- daca contine altceva decat cifre si caracterul '.'
	*/
	int points = 0;
	if(str.GetLength()==0)
		return false;
	if(str[0] == '.' || str[str.GetLength()-1] == '.')
		return false;
	for(int i=0; i<str.GetLength(); i++) {
		if(str[i] == '.')
			points++;
        if(!std::isdigit(str[i]) && str[i] != '.' || points >1)
            return false;
    }
    return true;
}



void CParametersDlg::OnBnClickedOk()
{
	
	/*
		Iau cele doua valori din editbox-uri.
		Daca sunt numere ambele, variabila de tip boolean "areNumbers" devine true (initial e false).
	*/

	GetDlgItem(IDC_EDIT1)->GetWindowText(m1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(E1);
	if( IsNumber(m1)==true && IsNumber(E1)==true )
		areNumbers = true;
	else
		MessageBox("Incorect parameters. Try again!");
	CDialogEx::OnOK();
}


void CParametersDlg::OnClose()
{
	windowWasClosed = true;
	CDialogEx::OnClose();
}
