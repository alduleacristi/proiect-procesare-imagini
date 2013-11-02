#pragma once
#include "afxwin.h"


// FiltruMedianCristi dialog

class FiltruMedianCristi : public CDialogEx
{
	DECLARE_DYNAMIC(FiltruMedianCristi)

public:
	FiltruMedianCristi(CWnd* pParent = NULL);   // standard constructor
	virtual ~FiltruMedianCristi();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	CEdit edit1;
	int val;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	int getVal();
};
