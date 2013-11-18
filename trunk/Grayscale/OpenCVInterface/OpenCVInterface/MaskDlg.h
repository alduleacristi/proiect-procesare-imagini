#pragma once
#include <cctype>

// CMaskDlg dialog

class CMaskDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMaskDlg)
	bool DimensionIsValid();
public:
	CMaskDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMaskDlg();

	CString n1;
	bool windowWasClosed;
// Dialog Data
	enum { IDD = IDD_MaskDimension };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
};
