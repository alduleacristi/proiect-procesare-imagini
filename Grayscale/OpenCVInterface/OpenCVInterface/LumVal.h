#pragma once


// LumVal dialog

class LumVal : public CDialogEx
{
	DECLARE_DYNAMIC(LumVal)

public:
	LumVal(CWnd* pParent = NULL);   // standard constructor
	virtual ~LumVal();

// Dialog Data
	enum { IDD = IDD_LUMVAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int b;
public:
	afx_msg void OnBnClickedOk();
	int getB(void);
	afx_msg void OnBnClickedCancel();
};
