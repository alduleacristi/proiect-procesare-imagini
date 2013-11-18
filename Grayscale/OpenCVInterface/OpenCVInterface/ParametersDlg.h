#pragma once
#include "afxwin.h"
#include <cctype>

// CParametersDlg dialog

class CParametersDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CParametersDlg)

	bool IsNumber(CString str);
	
public:
	CParametersDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CParametersDlg();

	CString m1, E1;
	bool areNumbers;
	bool windowWasClosed;
	
	
// Dialog Data
	enum { IDD = IDD_Parameters };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
};
